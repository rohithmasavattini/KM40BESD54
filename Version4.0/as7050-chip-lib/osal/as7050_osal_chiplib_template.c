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

/*
This template shall help to implement your own OSAL
which can be called by the AS7050 Chip Library.
All code lines which start with '// TODO' must be replaced by your own implementation.
*/

/******************************************************************************
 *                                 INCLUDES                                   *
 ******************************************************************************/

#include "as7050_osal_chiplib.h"
#include "error_codes.h"

/******************************************************************************
 *                                DEFINITIONS                                 *
 ******************************************************************************/

/*! internal structure which saves OSAL internal parameter */
struct device_config {
    volatile uint8_t init_done;                /*!< TRUE when ::as7050_osal_initialize was successful called */
    volatile as7050_osal_interrupt_t callback; /*!< Pointer to the registered callback function of the Chip Library */
};

/******************************************************************************
 *                                  GLOBALS                                   *
 ******************************************************************************/

/*! I2C address of the AS7050 */
static const uint8_t g_i2c_address = 0x55;

/*! Instance of the device configuration */
static struct device_config g_device_config = {0};

/******************************************************************************
 *                               LOCAL FUNCTIONS                              *
 ******************************************************************************/

/*! Interrupt service routine of the interrupt pin */
static void interrupt_callback()
{
    err_code_t result;
    uint8_t pin_state = 0;

    if (NULL != g_device_config.callback) {
        do {
            /* Calls the Chip Library callback function registered by as7050_osal_register_int_handler */
            result = g_device_config.callback();

            /* Read the pin state because it could be high again */
            if (ERR_SUCCESS == result) {
                // TODO result = get_int_pin_state(&pin_state);
            }

        } while ((ERR_SUCCESS == result) && pin_state);
    }
}

/******************************************************************************
 *                             GLOBAL FUNCTIONS                               *
 ******************************************************************************/

err_code_t as7050_osal_initialize(const char *p_interface_desc)
{
    err_code_t result = ERR_SUCCESS;

    /* Shutdown OSAL interface in case there is one already opened */
    if (g_device_config.init_done) {
        as7050_osal_shutdown();
    }

    /* Configure IF_SEL pin for I2C, if present on board */
    // TODO if (RETURN_CODE_OK != set_if_sel_to_low())
    {
        result = ERR_SYSTEM_CONFIG;
    }

    /* Configure I2C */
    // TODO if ((ERR_SUCCESS == result) && (RETURN_CODE_OK != i2c_init())
    {
        result = ERR_SYSTEM_CONFIG;
    }

    /* Configure interrupt pin: Call function interrupt_callback on rising edge */
    // TODO if ((ERR_SUCCESS == result) && (RETURN_CODE_OK != int_pin_init(TRIG_RISING, interrupt_callback))
    {
        result = ERR_SYSTEM_CONFIG;
    }

    if (ERR_SUCCESS == result) {
        g_device_config.init_done = TRUE;
    } else {
        as7050_osal_shutdown();
    }

    return result;
}

err_code_t as7050_osal_write_registers(uint8_t address, uint8_t number, uint8_t *p_values)
{
    if (FALSE == g_device_config.init_done) {
        return ERR_PERMISSION;
    }

    M_CHECK_NULL_POINTER(p_values);

    /* Call the platform-specifc I2C transmit function */
    // TODO if (RETURN_CODE_OK != i2c_write(g_i2c_address, address, number, p_values)
    {
        return ERR_DATA_TRANSFER;
    }

    return ERR_SUCCESS;
}

err_code_t as7050_osal_read_registers(uint8_t address, uint8_t number, uint8_t *p_values)
{
    if (FALSE == g_device_config.init_done) {
        return ERR_PERMISSION;
    }

    M_CHECK_NULL_POINTER(p_values);

    /* Call the platform-specifc I2C receive function */
    // TODO if (RETURN_CODE_OK != i2c_read(g_i2c_address, address, number, p_values)
    {
        return ERR_DATA_TRANSFER;
    }

    return ERR_SUCCESS;
}

err_code_t as7050_osal_register_int_handler(as7050_osal_interrupt_t callback_function)
{
    if (FALSE == g_device_config.init_done) {
        return ERR_PERMISSION;
    }

    g_device_config.callback = callback_function;

    return ERR_SUCCESS;
}

err_code_t as7050_osal_get_ms_tick(uint32_t *p_tick_ms)
{
    if (FALSE == g_device_config.init_done) {
        return ERR_PERMISSION;
    }

    M_CHECK_NULL_POINTER(p_tick_ms);

    /* Call the platform-specific command to read current millisecond timestamp */
    // TODO if (RETURN_CODE_OK != get_microseconds(p_tick_ms))
    {
        return ERR_TIMER_ACCESS;
    }

    return ERR_SUCCESS;
}

err_code_t as7050_osal_shutdown(void)
{
    /* Clean up of system resources */

    /* Deactivate interrupt pin */
    // TODO int_pin_shutdown();

    /* Disable I2C */
    // TODO i2c_shutdown();

    /* Deactivate IF_SEL pin, if present on board */
    // TODO set_if_sel_shutdown();

    memset(&g_device_config, 0, sizeof(g_device_config));

    return ERR_SUCCESS;
}
