/******************************************************************************
 * Copyright by ams AG                                                        *
 * All rights are reserved.                                                   *
 *                                                                            *
 * IMPORTANT - PLEASE READ CAREFULLY BEFORE COPYING, INSTALLING OR USING      *
 * THE SOFTWARE.                                                              *
 *                                                                            *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS        *
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT          *
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS          *
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT   *
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,      *
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT           *
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,      *
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY      *
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT        *
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE      *
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.       *
 ******************************************************************************/

/******************************************************************************
 *                                 INCLUDES                                   *
 ******************************************************************************/

#include <stddef.h>
#include <string.h>

#include "as7050_typedefs.h"
#include "error_codes.h"
#include "raw_app.h"

/******************************************************************************
 *                                DEFINITIONS                                 *
 ******************************************************************************/

/*!
 * \brief Maximum size of a raw data output excluding ::HEADER_SIZE. The total maximum size of a raw data output is this
 *        value plus ::HEADER_SIZE.
 */
#define MAX_RAW_DATA_SIZE 146

#define MAX_ACC_DATA_NUM 20
#define SEC_IN_US 1000000
#define HEADER_SIZE 3
#define MAX_RAW_PACKAGES_NUM 5
#define RAW_DATA_SAMPLE_SIZE 3

enum raw_state {
    RAW_STATE_UNINITIALIZED = 0,
    RAW_STATE_CONFIGURATION,
    RAW_STATE_PROCESSING,
};

struct raw_config {
    uint8_t state; /*!< See ::raw_state */
    uint8_t
        is_acc_streaming; /*!< != 0 means that accelerometer data will be put into the raw package. Can be configured */
    uint8_t incoming_sample_size; /*!< size of one sample in bytes (3 or 4) */
    /*! raw data structure for the ring buffer which will be sent out */
    volatile struct send_data_struct {
        uint8_t adc_data_num;                /*!< number of ADC data inside the raw data buffer */
        uint8_t acc_data_num;                /*!< number of accelerometer data inside the raw data buffer */
        uint8_t agc_status_num;              /*!< number of AGC status information entries inside the raw data buffer */
        uint8_t raw_data[MAX_RAW_DATA_SIZE]; /*!< data buffer for ADC, ACC and AGC */
    } send_data[MAX_RAW_PACKAGES_NUM];
    volatile uint32_t send_data_sizes[MAX_RAW_PACKAGES_NUM]; /*!< total size of the complete raw data package (excludes
                                                               the ::HEADER_SIZE) */
    vs_acc_data_t acc_data[MAX_ACC_DATA_NUM];                /*!< intermediate buffer for accelerometer data */
    uint8_t max_adc_data; /*!< maximum number of ADC data to fullfill the requirement to send data at least every 1
                             second */
    volatile uint8_t write_pointer; /*!< write pointer of the send_data ring buffer (::send_data_struct) */
    volatile uint8_t read_pointer;  /*!< read pointer of the send_data ring buffer (::send_data_struct) */
    agc_status_t last_agc_statuses[AGC_MAX_CHANNEL_CNT]; /*!< save the latest received used AGC status information to
                                                         compare with new one */
    uint8_t last_agc_statuses_num;
};

/******************************************************************************
 *                                  GLOBALS                                   *
 ******************************************************************************/

static volatile struct raw_config g_raw_config = {0};

/******************************************************************************
 *                               LOCAL FUNCTIONS                              *
 ******************************************************************************/

static err_code_t copy_agc_and_acc_data_to_send_buffer(uint8_t write_pointer)
{
    if (MAX_RAW_PACKAGES_NUM <= write_pointer) {
        return ERR_ARGUMENT;
    }

    uint32_t write_idx = g_raw_config.send_data[write_pointer].adc_data_num * RAW_DATA_SAMPLE_SIZE;

    /* Copy ACC data to send buffer */
    if (g_raw_config.is_acc_streaming) {
        const uint32_t acc_size = g_raw_config.send_data[write_pointer].acc_data_num * sizeof(vs_acc_data_t);
        memcpy((void *)&g_raw_config.send_data[write_pointer].raw_data[write_idx], (void *)&g_raw_config.acc_data,
               acc_size);
        write_idx += acc_size;
    }

    /* Copy AGC data to send buffer */
    if (g_raw_config.send_data[write_pointer].agc_status_num) {
        memcpy((void *)&g_raw_config.send_data[g_raw_config.write_pointer].raw_data[write_idx],
               (void *)&g_raw_config.last_agc_statuses, sizeof(agc_status_t) * g_raw_config.last_agc_statuses_num);
    }

    return ERR_SUCCESS;
}

static uint8_t is_write_package_available(void)
{
    if ((g_raw_config.write_pointer + 1) == g_raw_config.read_pointer ||
        (0 == g_raw_config.read_pointer && (MAX_RAW_PACKAGES_NUM - 1) == g_raw_config.write_pointer)) {
        return FALSE;
    }

    return TRUE;
}

static uint8_t is_read_package_available(void)
{
    return (g_raw_config.write_pointer != g_raw_config.read_pointer);
}

static void increase_pointer(volatile uint8_t *p_pointer)
{
    if (p_pointer) {
        (*p_pointer)++;

        if (MAX_RAW_PACKAGES_NUM == *p_pointer) {
            *p_pointer = 0;
        }
    }
}

static err_code_t configure_sample_period(uint32_t sample_period_us)
{
    if (0 == sample_period_us) {
        return ERR_ARGUMENT;
    }

    /* calculate the maximum data for 1s */
    const uint32_t samples_per_second = SEC_IN_US / sample_period_us;
    const uint8_t max_adc_data = MAX_RAW_DATA_SIZE / RAW_DATA_SAMPLE_SIZE;

    if (max_adc_data <= samples_per_second) {
        g_raw_config.max_adc_data = max_adc_data;
    } else if (0 == samples_per_second) {
        g_raw_config.max_adc_data = 1;
    } else {
        g_raw_config.max_adc_data = samples_per_second;
    }

    return ERR_SUCCESS;
}

static err_code_t prepare_calculation(void)
{
    uint8_t i;

    for (i = 0; i < MAX_RAW_PACKAGES_NUM; i++) {
        g_raw_config.send_data[i].adc_data_num = 0;
        g_raw_config.send_data[i].acc_data_num = 0;
        g_raw_config.send_data[i].agc_status_num = 0;
        g_raw_config.send_data_sizes[i] = 0;
    }
    g_raw_config.write_pointer = 0;
    g_raw_config.read_pointer = 0;
    memset((void *)&g_raw_config.last_agc_statuses, 0xFF, sizeof(g_raw_config.last_agc_statuses));

    g_raw_config.last_agc_statuses_num = 0;

    return ERR_SUCCESS;
}

static err_code_t finalize_output_data(void)
{
    M_CHECK_SUCCESS(copy_agc_and_acc_data_to_send_buffer(g_raw_config.write_pointer));

    if (!is_write_package_available()) {
        return ERR_OVERFLOW;
    }

    increase_pointer(&g_raw_config.write_pointer);

    return ERR_SUCCESS;
}

/******************************************************************************
 *                             GLOBAL FUNCTIONS                               *
 ******************************************************************************/

err_code_t raw_app_initialize(void)
{
    M_CHECK_SUCCESS(raw_app_shutdown());

    g_raw_config.state = RAW_STATE_CONFIGURATION;
    return ERR_SUCCESS;
}

err_code_t raw_app_configure(const void *p_config, uint8_t size)
{
    M_CHECK_NULL_POINTER(p_config);
    M_CHECK_SIZE(size, sizeof(raw_app_configuration_t));

    if (g_raw_config.state != RAW_STATE_CONFIGURATION) {
        return ERR_PERMISSION;
    }

    g_raw_config.is_acc_streaming = (((const raw_app_configuration_t *)p_config)->include_acc ? TRUE : FALSE);
    return ERR_SUCCESS;
}

err_code_t raw_app_start(uint32_t signal_sample_period_us, uint8_t sample_size)
{
    if (g_raw_config.state != RAW_STATE_CONFIGURATION) {
        return ERR_PERMISSION;
    }
    if ((3u != sample_size) && (4u != sample_size)) {
        return ERR_ARGUMENT;
    }

    g_raw_config.incoming_sample_size = sample_size;

    M_CHECK_SUCCESS(configure_sample_period(signal_sample_period_us));
    M_CHECK_SUCCESS(prepare_calculation());

    g_raw_config.state = RAW_STATE_PROCESSING;
    return ERR_SUCCESS;
}

err_code_t raw_app_set_input(const uint8_t *p_fifo_data, uint16_t fifo_data_size, const agc_status_t *p_agc_statuses,
                             uint8_t agc_statuses_num, const vs_acc_data_t *p_acc_data, uint8_t acc_data_num,
                             uint8_t ext_event_num, bio_execution_status_t *p_result)
{
    M_UNUSED_PARAM(ext_event_num);

    uint32_t input_data_size;
    uint8_t transmit_agc_statuses = FALSE;
    err_code_t result;
    uint16_t i;

    if (g_raw_config.state != RAW_STATE_PROCESSING) {
        return ERR_PERMISSION;
    }

    M_CHECK_NULL_POINTER(p_fifo_data);
    M_CHECK_NULL_POINTER(p_result);
    if (0 < agc_statuses_num) {
        M_CHECK_NULL_POINTER(p_agc_statuses);
    }
    if (g_raw_config.last_agc_statuses_num > 0 && agc_statuses_num != g_raw_config.last_agc_statuses_num) {
        return ERR_ARGUMENT;
    }
    if (0 < acc_data_num) {
        M_CHECK_NULL_POINTER(p_acc_data);
    }
    if (0 == fifo_data_size) {
        return ERR_ARGUMENT;
    }

    /* Check if changed agc data was received */
    transmit_agc_statuses = FALSE;
    if (agc_statuses_num > 0) {
        if (0 == g_raw_config.last_agc_statuses_num) {
            /* First time AGC statuses are received, always transmit them */
            transmit_agc_statuses = TRUE;
        } else if (memcmp((void *)&g_raw_config.last_agc_statuses, p_agc_statuses,
                          sizeof(agc_status_t) * agc_statuses_num)) {
            /* AGC statuses are different from previously transmitted AGC statuses, transmit if there is at least one
             * state value other than ::AGC_STATE_UNCHANGED in the new AGC statuses. This causes AGC statuses not to be
             * transmitted if, for example, a LED current was increased before and its state now changed back to
             * ::AGC_STATE_UNCHANGED. (assuming that there are no other changes in the AGC statuses) */
            for (i = 0; i < agc_statuses_num; i++) {
                if (((p_agc_statuses[i].pd_offset_change != AGC_STATE_UNCHANGED) &&
                     (p_agc_statuses[i].pd_offset_change != AGC_STATE_NOT_CONTROLLED)) ||
                    ((p_agc_statuses[i].led_change != AGC_STATE_UNCHANGED) &&
                     (p_agc_statuses[i].led_change != AGC_STATE_NOT_CONTROLLED))) {
                    transmit_agc_statuses = TRUE;
                }
            }
        }
    }

    /* Calculate the size of the data that is appended to the output during this invocation of the function. This size
     * is the sum of the FIFO data (with alignment byte removed), the size of the accelerometer data, and the size of
     * the AGC status informations. It doesn't include the size of the output data header. */
    input_data_size = (fifo_data_size) + (g_raw_config.is_acc_streaming ? sizeof(vs_acc_data_t) * acc_data_num : 0) +
                      (transmit_agc_statuses ? sizeof(agc_status_t) * agc_statuses_num : 0);
    if (4 == g_raw_config.incoming_sample_size) {
        /* reduce size to 3byte per sample, alignment byte will be removed */
        input_data_size -= fifo_data_size / g_raw_config.incoming_sample_size;
    }

    /* Check if the data can be appended to the current output data instance or whether a new instance needs to be
     * created. Data cannot be appended in any of the following cases:
     * - Size of the output (excluding the header) would exceed ::MAX_RAW_DATA_SIZE size after appending the new data
     * - Current output buffer shall be sent as soon new AGC status information is available
     *   (Rule will be ignored for the first package)
     * - Intermediate accelerometer sample buffer would not be able to hold all samples after appending the new data */
    if (((MAX_RAW_DATA_SIZE - g_raw_config.send_data_sizes[g_raw_config.write_pointer]) < input_data_size) ||
        (transmit_agc_statuses && g_raw_config.last_agc_statuses_num) ||
        ((MAX_ACC_DATA_NUM - g_raw_config.send_data[g_raw_config.write_pointer].acc_data_num) < acc_data_num)) {
        result = finalize_output_data();
    } else {
        result = ERR_SUCCESS;
    }

    /* Copy data */
    if (ERR_SUCCESS == result) {
        /* Copy ADC data to send buffer */
        if (4 == g_raw_config.incoming_sample_size) {
            for (i = 0; i < fifo_data_size / 4; i += 4) {
                memcpy(
                    (void *)(g_raw_config.send_data[g_raw_config.write_pointer].raw_data +
                             (g_raw_config.send_data[g_raw_config.write_pointer].adc_data_num * RAW_DATA_SAMPLE_SIZE)),
                    p_fifo_data + (4 * i), 3);
                g_raw_config.send_data[g_raw_config.write_pointer].adc_data_num++;
            }
        } else {
            memcpy((void *)(g_raw_config.send_data[g_raw_config.write_pointer].raw_data +
                            (g_raw_config.send_data[g_raw_config.write_pointer].adc_data_num * RAW_DATA_SAMPLE_SIZE)),
                   p_fifo_data, fifo_data_size);

            g_raw_config.send_data[g_raw_config.write_pointer].adc_data_num += fifo_data_size / RAW_DATA_SAMPLE_SIZE;
        }

        /* Copy AGC data to temporary buffer */
        if (transmit_agc_statuses) {
            memcpy((void *)&g_raw_config.last_agc_statuses, p_agc_statuses, sizeof(agc_status_t) * agc_statuses_num);
            g_raw_config.last_agc_statuses_num = agc_statuses_num;
            g_raw_config.send_data[g_raw_config.write_pointer].agc_status_num = agc_statuses_num;
        }

        /* Copy ACC data to temporary buffer */
        if (g_raw_config.is_acc_streaming) {
            if (MAX_ACC_DATA_NUM >= g_raw_config.send_data[g_raw_config.write_pointer].acc_data_num + acc_data_num) {
                memcpy((void *)&g_raw_config.acc_data[g_raw_config.send_data[g_raw_config.write_pointer].acc_data_num],
                       p_acc_data, acc_data_num * sizeof(p_acc_data[0]));
                g_raw_config.send_data[g_raw_config.write_pointer].acc_data_num += acc_data_num;
            } else {
                /* overflow */
                result = ERR_OVERFLOW;
            }
        }
    }

    if (ERR_SUCCESS == result) {
        g_raw_config.send_data_sizes[g_raw_config.write_pointer] += input_data_size;

        /* Check if the data needs to be sent. Data is sent in any of the following cases:
         * - The ADC sample count threshold to ensure that an output is generated at least every second on average is
         *   reached
         * - The output has reached its maximum size */
        if ((g_raw_config.max_adc_data <= g_raw_config.send_data[g_raw_config.write_pointer].adc_data_num) ||
            (MAX_RAW_DATA_SIZE <= g_raw_config.send_data_sizes[g_raw_config.write_pointer])) {
            result = finalize_output_data();
        } else {
            result = ERR_SUCCESS;
        }
    }

    *p_result = (is_read_package_available() ? BIO_OUTPUT_STATUS_DATA_AVAILABLE : BIO_OUTPUT_STATUS_DATA_UNAVAILABLE);

    return result;
}

err_code_t raw_app_execute(bio_output_status_t *p_result)
{
    if (g_raw_config.state != RAW_STATE_PROCESSING) {
        return ERR_PERMISSION;
    }

    M_CHECK_NULL_POINTER(p_result);

    *p_result = (is_read_package_available() ? BIO_OUTPUT_STATUS_DATA_AVAILABLE : BIO_OUTPUT_STATUS_DATA_UNAVAILABLE);

    return ERR_SUCCESS;
}

err_code_t raw_app_get_output(void *p_dest, uint16_t *p_size)
{
    if (g_raw_config.state != RAW_STATE_PROCESSING) {
        return ERR_PERMISSION;
    }

    M_CHECK_NULL_POINTER(p_dest);
    M_CHECK_NULL_POINTER(p_size);

    if (!is_read_package_available()) {
        return ERR_NO_DATA;
    }

    if (*p_size < g_raw_config.send_data_sizes[g_raw_config.read_pointer] + HEADER_SIZE) {
        return ERR_SIZE;
    }

    /* Copy raw data */
    *p_size = g_raw_config.send_data_sizes[g_raw_config.read_pointer] + HEADER_SIZE;
    memcpy(p_dest, (uint8_t *)&g_raw_config.send_data[g_raw_config.read_pointer], *p_size);

    g_raw_config.send_data[g_raw_config.read_pointer].adc_data_num = 0;
    g_raw_config.send_data[g_raw_config.read_pointer].acc_data_num = 0;
    g_raw_config.send_data[g_raw_config.read_pointer].agc_status_num = 0;
    g_raw_config.send_data_sizes[g_raw_config.read_pointer] = 0;

    increase_pointer(&g_raw_config.read_pointer);

    return ERR_SUCCESS;
}

err_code_t raw_app_stop(void)
{
    if (RAW_STATE_UNINITIALIZED == g_raw_config.state) {
        return ERR_PERMISSION;
    }

    g_raw_config.state = RAW_STATE_CONFIGURATION;

    return ERR_SUCCESS;
}

err_code_t raw_app_shutdown(void)
{
    memset((void *)&g_raw_config, 0, sizeof(g_raw_config));

    return ERR_SUCCESS;
}
