#include <common.h>
#include <serial.h>

#define TEST_STRING "UART Loopback Test"
#define BUFFER_SIZE 64

int uart_loopback_test(int uart_dev)
{
    char tx_buffer[BUFFER_SIZE] = TEST_STRING;
    char rx_buffer[BUFFER_SIZE] = {0};
    int ret, i;

    // Initialize the UART
    ret = serial_init();
    if (ret) {
        printf("UART initialization failed\n");
        return -1;
    }

    // Select the UART device
    ret = serial_assign(uart_dev);
    if (ret) {
        printf("Failed to assign UART device\n");
        return -1;
    }

    // Send the test string
    for (i = 0; i < strlen(tx_buffer); i++) {
        serial_putc(tx_buffer[i]);
    }

    // Receive the echoed data
    for (i = 0; i < strlen(tx_buffer); i++) {
        rx_buffer[i] = serial_getc();
    }

    // Compare sent and received data
    if (strcmp(tx_buffer, rx_buffer) == 0) {
        printf("UART Loopback Test Passed\n");
        return 0;
    } else {
        printf("UART Loopback Test Failed\n");
        printf("Sent: %s\n", tx_buffer);
        printf("Received: %s\n", rx_buffer);
        return -1;
    }
}

void All_Test_Cases(void)
{
    // ... (previous tests)

    printf("UART Loopback Test\n");
    HD44780_Str_XY(0,1,"UART Loopback");
    ret = uart_loopback_test(CONFIG_SYS_NS16550_COM1);
    if (ret != 0) {
        printf("UART Loopback Test FAIL\n");
        HD44780_Str_XY(0,1,"UART Test FAIL");
    } else {
        printf("UART Loopback Test PASS\n");
        HD44780_Str_XY(0,1,"UART Test PASS");
    }

    // ... (remaining tests)
}