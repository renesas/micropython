/*
 * The MIT License (MIT)
 *
 * Copyright (c) 2021 Renesas Electronics Corporation
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#ifndef RA_RA_I2C_H_
#define RA_RA_I2C_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stdbool.h>

#define RA_I2C_DEF_TIMEOUT              1000    // 1000 ms
#define RA_I2C_TIMEOUT_STOP_CONDITION   100000  // counts
#define RA_I2C_TIMEOUT_BUS_BUSY         100000  // counts
#define RA_I2C_CLOCK_MAX                1000000 // counts

enum
{
    RA_I2C_STATUS_Idle = 1,
    RA_I2C_STATUS_Scheduled = 2,
    RA_I2C_STATUS_Processing = 3,
    RA_I2C_STATUS_Completed = 4,
    RA_I2C_STATUS_Aborted = 5,
    RA_I2C_STATUS_Cancelled = 6,
};

typedef struct {
    uint32_t m_bytes_transferred;
    uint32_t m_bytes_transfer;
    bool m_fread;
    uint8_t *buf;
    void *next;
} xaction_unit_t;

typedef struct {
    xaction_unit_t *units;
    uint32_t m_num_of_units;
    uint32_t m_current;
    uint32_t m_clock;
    uint32_t m_address;
    volatile uint32_t m_status;
} xaction_t;

bool ra_i2c_find_af_ch(uint32_t scl, uint32_t sda, uint8_t *ch);
// static void ra_i2c_clear_line(uint32_t ch);
#if defined(DEBUG_I2C_REG_DUMP)
static void i2c_reg_dump(uint32_t ch);
#endif
// static void ra_i2c_module_start(uint32_t ch);
// static void ra_i2c_module_stop(uint32_t ch);
// static void ra_i2c_set_pin(uint8_t pin);
void ra_i2c_enable(uint32_t ch);
void ra_i2c_disable(uint32_t ch);
void ra_i2c_priority(uint32_t ch, uint32_t ipl);
void ra_i2c_set_baudrate(uint32_t ch, uint32_t baudrate);
void ra_i2c_init(uint32_t ch, uint32_t scl, uint32_t sda, uint32_t baudrate, uint32_t timeout_ms);
void ra_i2c_deinit(uint32_t ch);
void ra_i2c_read_last_byte(uint32_t ch);
void ra_i2c_stop_confition(uint32_t ch);
void ra_i2c_abort(uint32_t ch);
void ra_i2c_xaction_start(uint32_t ch, xaction_t *xaction, bool repeated_start);
void ra_i2c_xaction_stop(uint32_t ch);
void ra_i2c_get_clock(uint32_t rateKhz, uint8_t *clockRate, uint8_t *clockRate2);
void ra_i2c_xunit_write_byte(uint32_t ch, xaction_unit_t *unit);
void ra_i2c_xunit_read_byte(uint32_t ch, xaction_unit_t *unit);
void ra_i2c_xunit_init(xaction_unit_t *unit, uint8_t *buf, uint32_t size, bool fread, void *next);
void ra_i2c_xaction_init(xaction_t *action, xaction_unit_t *units, uint32_t size, uint32_t clock, uint32_t address);
// static void ra_i2c_iceri_isr(uint32_t ch);
// static void ra_i2c_icrxi_isr(uint32_t ch);
// static void ra_i2c_ictxi_isr(uint32_t ch);
// static void ra_i2c_ictei_isr(uint32_t ch);
void iic_master_rxi_isr(void);
void iic_master_txi_isr(void);
void iic_master_tei_isr(void);
void iic_master_eri_isr(void);
bool ra_i2c_action_execute(uint32_t ch, xaction_t *action, bool repeated_start, uint32_t timeout_ms);

#ifdef __cplusplus
}
#endif

#endif /* RA_RA_I2C_H_ */
