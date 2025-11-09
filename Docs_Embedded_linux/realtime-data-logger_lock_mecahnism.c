#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include <string.h>
#include <errno.h>
#include <sys/epoll.h>
#include <sys/timerfd.h>
#include <time.h>
#include <sched.h>
#include <linux/i2c-dev.h>
#include <sys/ioctl.h>

#define MAX_EVENTS 10
#define BUTTON_GPIO "/sys/class/gpio/gpio60/value"
#define I2C_DEVICE "/dev/i2c-1"
#define ADXL345_ADDR 0x53
#define EEPROM_ADDR 0x50
#define RTC_ADDR 0x68

// Function prototypes
void *button_thread(void *arg);
void *sensor_thread(void *arg);
int read_accelerometer(int fd, int16_t *x, int16_t *y, int16_t *z);
int read_temperature(int fd, float *temp);
int read_rtc(int fd, struct tm *time);
int write_to_eeprom(int fd, uint16_t address, uint8_t *data, size_t len);

// Global variables
volatile int g_button_pressed = 0;
int g_i2c_fd;

// Synchronization primitives
pthread_mutex_t g_button_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t g_i2c_mutex = PTHREAD_MUTEX_INITIALIZER;
sem_t g_eeprom_sem;
sem_t g_button_sem;

int main() {
    pthread_t button_tid, sensor_tid;
    pthread_attr_t attr;
    struct sched_param param;

    // Initialize semaphores
    sem_init(&g_eeprom_sem, 0, 1);
    sem_init(&g_button_sem, 0, 0);

    // Open I2C device
    g_i2c_fd = open(I2C_DEVICE, O_RDWR);
    if (g_i2c_fd < 0) {
        perror("Failed to open I2C device");
        return 1;
    }

    // Set up real-time priority for threads
    pthread_attr_init(&attr);
    pthread_attr_setinheritsched(&attr, PTHREAD_EXPLICIT_SCHED);
    pthread_attr_setschedpolicy(&attr, SCHED_FIFO);
    param.sched_priority = 80;
    pthread_attr_setschedparam(&attr, &param);

    // Create button thread
    if (pthread_create(&button_tid, &attr, button_thread, NULL) != 0) {
        perror("Failed to create button thread");
        return 1;
    }

    // Create sensor thread
    if (pthread_create(&sensor_tid, &attr, sensor_thread, NULL) != 0) {
        perror("Failed to create sensor thread");
        return 1;
    }

    // Wait for threads to finish (they won't in this example)
    pthread_join(button_tid, NULL);
    pthread_join(sensor_tid, NULL);

    close(g_i2c_fd);
    sem_destroy(&g_eeprom_sem);
    sem_destroy(&g_button_sem);
    return 0;
}

void *button_thread(void *arg) {
    int fd, epfd;
    struct epoll_event ev, events[MAX_EVENTS];
    char buf[2];

    // Open GPIO value file
    fd = open(BUTTON_GPIO, O_RDONLY);
    if (fd < 0) {
        perror("Failed to open GPIO file");
        return NULL;
    }

    // Create epoll instance
    epfd = epoll_create1(0);
    if (epfd < 0) {
        perror("Failed to create epoll instance");
        close(fd);
        return NULL;
    }

    // Add GPIO file to epoll
    ev.events = EPOLLPRI | EPOLLET;
    ev.data.fd = fd;
    if (epoll_ctl(epfd, EPOLL_CTL_ADD, fd, &ev) < 0) {
        perror("Failed to add GPIO file to epoll");
        close(fd);
        close(epfd);
        return NULL;
    }

    // Main loop
    while (1) {
        int nfds = epoll_wait(epfd, events, MAX_EVENTS, -1);
        if (nfds < 0) {
            perror("epoll_wait failed");
            break;
        }

        for (int n = 0; n < nfds; ++n) {
            if (events[n].data.fd == fd) {
                lseek(fd, 0, SEEK_SET);
                if (read(fd, buf, sizeof(buf)) > 0) {
                    if (buf[0] == '1') {
                        pthread_mutex_lock(&g_button_mutex);
                        g_button_pressed = 1;
                        pthread_mutex_unlock(&g_button_mutex);
                        sem_post(&g_button_sem);
                    }
                }
            }
        }
    }

    close(fd);
    close(epfd);
    return NULL;
}

void *sensor_thread(void *arg) {
    int16_t x, y, z;
    float temp;
    struct tm rtc_time;
    uint8_t eeprom_data[16];
    uint16_t eeprom_address = 0;

    while (1) {
        sem_wait(&g_button_sem);

        pthread_mutex_lock(&g_button_mutex);
        int button_pressed = g_button_pressed;
        pthread_mutex_unlock(&g_button_mutex);

        if (button_pressed) {
            pthread_mutex_lock(&g_i2c_mutex);

            // Read accelerometer
            if (read_accelerometer(g_i2c_fd, &x, &y, &z) < 0) {
                fprintf(stderr, "Failed to read accelerometer\n");
            }

            // Read temperature
            if (read_temperature(g_i2c_fd, &temp) < 0) {
                fprintf(stderr, "Failed to read temperature\n");
            }

            // Read RTC
            if (read_rtc(g_i2c_fd, &rtc_time) < 0) {
                fprintf(stderr, "Failed to read RTC\n");
            }

            pthread_mutex_unlock(&g_i2c_mutex);

            // Prepare data for EEPROM
            memcpy(eeprom_data, &x, sizeof(x));
            memcpy(eeprom_data + 2, &y, sizeof(y));
            memcpy(eeprom_data + 4, &z, sizeof(z));
            memcpy(eeprom_data + 6, &temp, sizeof(temp));
            memcpy(eeprom_data + 10, &rtc_time, sizeof(rtc_time));

            // Write to EEPROM
            sem_wait(&g_eeprom_sem);
            pthread_mutex_lock(&g_i2c_mutex);
            if (write_to_eeprom(g_i2c_fd, eeprom_address, eeprom_data, sizeof(eeprom_data)) < 0) {
                fprintf(stderr, "Failed to write to EEPROM\n");
            }
            pthread_mutex_unlock(&g_i2c_mutex);
            sem_post(&g_eeprom_sem);

            eeprom_address += sizeof(eeprom_data);

            pthread_mutex_lock(&g_button_mutex);
            g_button_pressed = 0;
            pthread_mutex_unlock(&g_button_mutex);

            printf("Data logged: Accel(%d,%d,%d) Temp(%.2f) Time(%02d:%02d:%02d)\n",
                   x, y, z, temp, rtc_time.tm_hour, rtc_time.tm_min, rtc_time.tm_sec);
        }
    }

    return NULL;
}

// The following functions remain unchanged
int read_accelerometer(int fd, int16_t *x, int16_t *y, int16_t *z) {
    // ... (same as before)
}

int read_temperature(int fd, float *temp) {
    // ... (same as before)
}

int read_rtc(int fd, struct tm *time) {
    // ... (same as before)
}

int write_to_eeprom(int fd, uint16_t address, uint8_t *data, size_t len) {
    // ... (same as before)
}
