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

#include "agc_hal.h"
#include "as7050_extract.h"
#include "as7050_interface.h"
#include "as7050_osal_chiplib.h"
#include "as7050_typedefs.h"
#include "error_codes.h"

/******************************************************************************
 *                                DEFINITIONS                                 *
 ******************************************************************************/

/******************************************************************************
 *                                  GLOBALS                                   *
 ******************************************************************************/

static as7050_meas_config_t g_meas_config;
static uint8_t g_led_groups[AS7050_CHANNEL_ECG];

/******************************************************************************
 *                               LOCAL FUNCTIONS                              *
 ******************************************************************************/

/******************************************************************************
 *                             GLOBAL FUNCTIONS                               *
 ******************************************************************************/

err_code_t agc_hal_initialize(void *p_config, uint16_t size)
{
    uint8_t i;
    err_code_t result = ERR_SUCCESS;

    M_CHECK_NULL_POINTER(p_config);
    M_CHECK_SIZE(sizeof(as7050_meas_config_t), size);

    memcpy(&g_meas_config, p_config, sizeof(as7050_meas_config_t));

    for (i = AS7050_CHANNEL_PPG_1; (i <= AS7050_CHANNEL_ECG) && (ERR_SUCCESS == result); i++) {
        result = as7050_ifce_get_channel_led_config(i, &g_led_groups[i - AS7050_CHANNEL_PPG_1]);
    }

    if (ERR_SUCCESS != result) {
        agc_hal_shutdown();
    }

    return result;
}

err_code_t agc_hal_set_led_current(agc_channel_id_t channel_id, uint8_t led_current)
{
    err_code_t result = ERR_SUCCESS;
    uint8_t led_current_group;
    uint8_t i = 0;

    if (0 == g_meas_config.sample_size) {
        return ERR_PERMISSION;
    }

    if ((AS7050_CHANNEL_PPG_1 > channel_id) || (AS7050_CHANNEL_ECG < channel_id)) {
        return ERR_ARGUMENT;
    }

    led_current_group = g_led_groups[channel_id - AS7050_CHANNEL_PPG_1];

    while (led_current_group && (ERR_SUCCESS == result)) {
        if (led_current_group & 0x01) {
            /* LED channels are independent from PPG samples, but this API uses the PPG channel enum to refer to LED
             * channels, i.e. AS7050_CHANNEL_PPG_1 refers to the first LED channel */
            result = as7050_ifce_set_led_current((as7050_channel_t)((int)AS7050_CHANNEL_PPG_1 + i), led_current);
        }
        led_current_group >>= 1;
        i++;
    }
    return result;
}

err_code_t agc_hal_set_pd_offset(agc_channel_id_t channel_id, uint8_t pd_offset)
{
    as7050_pd_offset_config_t pd_offset_config;

    if (0 == g_meas_config.sample_size) {
        return ERR_PERMISSION;
    }

    pd_offset_config.channel_type = channel_id;
    pd_offset_config.pd_offset = pd_offset;
    return as7050_ifce_set_pd_offset(&pd_offset_config, 1);
}

err_code_t agc_hal_extract_samples(agc_channel_id_t channel_id, const uint8_t *p_fifo_data, uint16_t fifo_data_size,
                                   int32_t *p_chan_data, uint16_t *p_chan_data_num)
{
    if (0 == g_meas_config.sample_size) {
        return ERR_PERMISSION;
    }

    if (channel_id < AS7050_CHANNEL_PPG_1 || channel_id > AS7050_CHANNEL_ECG) {
        return ERR_ARGUMENT;
    }

    return as7050_ifce_extract_samples(g_meas_config.fifo_map, g_meas_config.sample_size,
                                       1 << (channel_id - AS7050_CHANNEL_PPG_1), p_fifo_data, fifo_data_size,
                                       (uint32_t *)p_chan_data, p_chan_data_num);
}

err_code_t agc_hal_get_sampling_period_us(agc_channel_id_t channel_id, uint32_t *p_sampling_period)
{
    if (0 == g_meas_config.sample_size) {
        return ERR_PERMISSION;
    }

    if (channel_id < AS7050_CHANNEL_PPG_1 || channel_id > AS7050_CHANNEL_ECG) {
        return ERR_ARGUMENT;
    }

    M_CHECK_NULL_POINTER(p_sampling_period);

    if (AS7050_CHANNEL_ECG == channel_id) {
        *p_sampling_period = g_meas_config.ecg_sample_period_us;
    } else {
        *p_sampling_period = g_meas_config.ppg_sample_period_us;
    }

    return ERR_SUCCESS;
}

err_code_t agc_hal_shutdown()
{
    memset(&g_meas_config, 0, sizeof(g_meas_config));
    return ERR_SUCCESS;
}
