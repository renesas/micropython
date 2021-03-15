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

#include <stdio.h>
#include <stdint.h>
#include "hal_data.h"
#include "ra_config.h"
#include "ra_gpio.h"
#include "ra_icu.h"
#include "ra_int.h"
#include "ra_timer.h"
#include "ra_utils.h"
#include "ra_i2c.h"

#if !defined(RA_PRI_I2C)
#define RA_PRI_I2C (8)
#endif

#if defined(__GNUC__)
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wconversion"
#pragma GCC diagnostic ignored "-Wimplicit-function-declaration"
#pragma GCC diagnostic ignored "-Wunused-variable"
#endif

extern volatile uint32_t uwTick;

static R_IIC0_Type *i2c_regs[] = {
    (R_IIC0_Type *)0x40053000,
    (R_IIC0_Type *)0x40053100,
};

static const ra_af_pin_t scl_pins[] = {
    { 7, 0, P204 },
    { 7, 0, P400 },
    { 7, 1, P100 },
    { 7, 1, P205 },
};
#define SCL_PINS_SIZE sizeof(scl_pins) / sizeof(ra_af_pin_t)

static const ra_af_pin_t sda_pins[] = {
    { 7, 0, P401 },
    { 7, 0, P407 },
    { 7, 1, P101 },
    { 7, 1, P206 },
};
#define SDA_PINS_SIZE sizeof(sda_pins) / sizeof(ra_af_pin_t)

static const uint8_t ra_i2c_ch_to_rxirq[] = {
    #if defined(VECTOR_NUMBER_IIC0_RXI)
    VECTOR_NUMBER_IIC0_RXI,
    #else
    VECTOR_NUMBER_NONE,
    #endif
    #if defined(VECTOR_NUMBER_IIC1_RXI)
    VECTOR_NUMBER_IIC1_RXI,
    #else
    VECTOR_NUMBER_NONE,
    #endif
};
static const uint8_t ra_i2c_ch_to_txirq[] = {
    #if defined(VECTOR_NUMBER_IIC0_TXI)
    VECTOR_NUMBER_IIC0_TXI,
    #else
    VECTOR_NUMBER_NONE,
    #endif
    #if defined(VECTOR_NUMBER_IIC1_TXI)
    VECTOR_NUMBER_IIC1_TXI,
    #else
    VECTOR_NUMBER_NONE,
    #endif
};
static const uint8_t ra_i2c_ch_to_teirq[] = {
    #if defined(VECTOR_NUMBER_IIC0_TEI)
    VECTOR_NUMBER_IIC0_TEI,
    #else
    VECTOR_NUMBER_NONE,
    #endif
    #if defined(VECTOR_NUMBER_IIC1_TEI)
    VECTOR_NUMBER_IIC1_TEI,
    #else
    VECTOR_NUMBER_NONE,
    #endif
};
static const uint8_t ra_i2c_ch_to_erirq[] = {
    #if defined(VECTOR_NUMBER_IIC0_ERI)
    VECTOR_NUMBER_IIC0_ERI,
    #else
    VECTOR_NUMBER_NONE,
    #endif
    #if defined(VECTOR_NUMBER_IIC1_ERI)
    VECTOR_NUMBER_IIC1_ERI,
    #else
    VECTOR_NUMBER_NONE,
    #endif
};

static uint32_t timeouts[] = {
    RA_I2C_DEF_TIMEOUT,
    RA_I2C_DEF_TIMEOUT,
};
static xaction_t *current_xaction;
static xaction_unit_t *current_xaction_unit;
static uint8_t pclk_div[8] = {
    1, 2, 4, 8, 16, 32, 64, 128
};

bool ra_i2c_find_af_ch(uint32_t scl, uint32_t sda, uint8_t *ch) {
    bool find = false;
    uint8_t scl_ch;
    uint8_t sda_ch;
    find = ra_af_find_ch((ra_af_pin_t *)&scl_pins, SCL_PINS_SIZE, scl, &scl_ch);
    if (find) {
        find = ra_af_find_ch((ra_af_pin_t *)&sda_pins, SDA_PINS_SIZE, sda, &sda_ch);
        if (find) {
            find = (scl_ch == sda_ch);
            if (find) {
                *ch = scl_ch;
            } else {
                *ch = 0;
            }
        }
    }
    return find;
}

static void ra_i2c_clear_line(uint32_t ch) {
    R_IIC0_Type *i2c_reg = i2c_regs[ch];
    if (i2c_reg->ICCR1_b.SDAI == 0) {
        int32_t t = 10;
        while (t-- > 0) {
            i2c_reg->ICCR1_b.CLO = 1;
            uint32_t timeout = RA_I2C_TIMEOUT_BUS_BUSY;
            while (i2c_reg->ICCR1_b.CLO == 1) {
                if (timeout-- == 0) {
                    break;
                }
            }
            if (i2c_reg->ICCR1_b.SDAI == 1) {
                break;
            }
        }
    }
}

static void ra_i2c_module_start(uint32_t ch) {
    if (ch == 0) {
        ra_mstpcrb_start(R_MSTP_MSTPCRB_MSTPB9_Msk);
    } else {
        ra_mstpcrb_start(R_MSTP_MSTPCRB_MSTPB8_Msk);
    }
}

static void ra_i2c_module_stop(uint32_t ch) {
    if (ch == 0) {
        ra_mstpcrb_stop(R_MSTP_MSTPCRB_MSTPB9_Msk);
    } else {
        ra_mstpcrb_stop(R_MSTP_MSTPCRB_MSTPB8_Msk);
    }
}

static void ra_i2c_set_pin(uint8_t pin) {
    ra_gpio_config(pin, GPIO_MODE_AF_OD, 0, AF_I2C);
}

void ra_i2c_enable(uint32_t ch) {
    R_BSP_IrqEnable((IRQn_Type const)ra_i2c_ch_to_rxirq[ch]);
    R_BSP_IrqEnable((IRQn_Type const)ra_i2c_ch_to_txirq[ch]);
    R_BSP_IrqEnable((IRQn_Type const)ra_i2c_ch_to_teirq[ch]);
    R_BSP_IrqEnable((IRQn_Type const)ra_i2c_ch_to_erirq[ch]);
}

void ra_i2c_disable(uint32_t ch) {
    R_BSP_IrqDisable((IRQn_Type const)ra_i2c_ch_to_rxirq[ch]);
    R_BSP_IrqDisable((IRQn_Type const)ra_i2c_ch_to_txirq[ch]);
    R_BSP_IrqDisable((IRQn_Type const)ra_i2c_ch_to_teirq[ch]);
    R_BSP_IrqDisable((IRQn_Type const)ra_i2c_ch_to_erirq[ch]);
}

void ra_i2c_priority(uint32_t ch, uint32_t ipl) {
    R_BSP_IrqCfg((IRQn_Type const)ra_i2c_ch_to_rxirq[ch], ipl, (void *)NULL);
    R_BSP_IrqCfg((IRQn_Type const)ra_i2c_ch_to_txirq[ch], ipl, (void *)NULL);
    R_BSP_IrqCfg((IRQn_Type const)ra_i2c_ch_to_teirq[ch], ipl, (void *)NULL);
    R_BSP_IrqCfg((IRQn_Type const)ra_i2c_ch_to_erirq[ch], ipl, (void *)NULL);
}


// ToDo: need to properly implement
static void ra_i2c_clock_calc(uint32_t baudrate, uint8_t *cks, uint8_t *brh, uint8_t *brl);
static void ra_i2c_clock_calc(uint32_t baudrate, uint8_t *cks, uint8_t *brh, uint8_t *brl) {
    #if defined(RA4M1)
    if (baudrate >= 400000) {
        // assume clock is 400000Hz (PCLKB 32MHz)
        *cks = 1;
        *brh = 9;
        *brl = 20;
    } else {
        // assume clock is 100000Hz (PCLKB 32MHz)
        *cks = 3;
        *brh = 15;
        *brl = 18;
    }
    #elif defined(RA4W1)
    if (baudrate >= 400000) {
        // assume clock is 400000Hz (PCLKB 32MHz)
        *cks = 1;
        *brh = 9;
        *brl = 20;
    } else {
        // assume clock is 100000Hz (PCLKB 32MHz)
        *cks = 3;
        *brh = 15;
        *brl = 18;
    }
    #elif defined(RA6M1)
    // PCLKB 60MHz SCLE=0
    if (baudrate >= 1000000) {
        *cks = 0;
        *brh = 15;
        *brl = 29;
    } else if (baudrate >= 400000) {
        // assume clock is 400000Hz (PCLKB 32MHz)
        *cks = 2;
        *brh = 8;
        *brl = 19;
    } else {
        // assume clock is 100000Hz (PCLKB 32MHz)
        *cks = 4;
        *brh = 14;
        *brl = 17;
    }
    #elif defined(RA6M2)
    // PCLKB 60MHz SCLE=0
    if (baudrate >= RA_I2C_CLOCK_MAX) {
        *cks = 0;
        *brh = 15;
        *brl = 29;
    } else if (baudrate >= 400000) {
        // assume clock is 400000Hz
        *cks = 2;
        *brh = 8;
        *brl = 19;
    } else {
        // assume clock is 100000Hz
        *cks = 4;
        *brh = 14;
        *brl = 17;
    }
    #else
    #error "CMSIS MCU Series is not specified."
    #endif
}

void ra_i2c_set_baudrate(uint32_t ch, uint32_t baudrate) {
    R_IIC0_Type *i2c_reg = i2c_regs[ch];
    uint8_t cks;
    uint8_t brh;
    uint8_t brl;
    ra_i2c_clock_calc(baudrate, &cks, &brh, &brl);
    i2c_reg->ICMR1_b.CKS = cks;
    i2c_reg->ICBRH_b.BRH = brh;
    i2c_reg->ICBRL_b.BRL = brl;
}

void ra_i2c_init(uint32_t ch, uint32_t scl, uint32_t sda, uint32_t baudrate, uint32_t timeout_ms) {
    R_IIC0_Type *i2c_reg = i2c_regs[ch];
    timeouts[ch] = timeout_ms;
    ra_i2c_module_start(ch);
    ra_i2c_set_pin(scl);
    ra_i2c_set_pin(sda);
    ra_i2c_priority(ch, RA_PRI_I2C);
    i2c_reg->ICCR1_b.ICE = 0;     // I2C disable
    i2c_reg->ICCR1_b.IICRST = 1;  // I2C internal reset
    i2c_reg->ICCR1_b.ICE = 1;     // I2C enable
    ra_i2c_set_baudrate(ch, baudrate);
    i2c_reg->ICSER = 0x00;          // I2C reset bus status enable register
    i2c_reg->ICMR3_b.ACKWP = 0x01;  // I2C allow to write ACKBT (transfer acknowledge bit)
    i2c_reg->ICIER = 0xF0;          // b0: Disable Time Out interrupt */
                                    // b1: Disable Arbitration Lost interrupt */
                                    // b2: Disable Start Condition Detection Interrupt */
                                    // b3: Disable Stop condition detection interrupt */
                                    // b4: Disable NACK reception interrupt */
                                    // b5: Enable Receive Data Full Interrupt */
                                    // b6: Enable Transmit End Interrupt */
                                    // b7: Enable Transmit Data Empty Interrupt */
    i2c_reg->ICCR1_b.IICRST = 0;    // I2C internal reset
    ra_i2c_clear_line(ch);
    return;
}

void ra_i2c_deinit(uint32_t ch) {
    R_IIC0_Type *i2c_reg = i2c_regs[ch];
    i2c_reg->ICIER = 0;        // I2C interrupt disable
    i2c_reg->ICCR1_b.ICE = 0;  // I2C disable
    ra_i2c_module_stop(ch);
    return;
}

void ra_i2c_read_last_byte(uint32_t ch) {
    R_IIC0_Type *i2c_reg = i2c_regs[ch];
    xaction_t *action = current_xaction;
    xaction_unit_t *unit = &action->units[action->m_current];
    while ((i2c_reg->ICSR2_b.RDRF) == 0) {
        ;
    }
    action->m_current++;
    if (action->m_current == action->m_num_of_units) {
        i2c_reg->ICSR2_b.STOP = 0;
        i2c_reg->ICCR2_b.SP = 1;
        ra_i2c_xunit_read_byte(ch, unit);
        i2c_reg->ICMR3_b.WAIT = 0;
        uint32_t timeout = RA_I2C_TIMEOUT_STOP_CONDITION;
        while (true) {
            if (i2c_reg->ICSR2_b.STOP != 0) {
                action->m_status = RA_I2C_STATUS_Completed;
                break;
            }
            if (timeout-- == 0) {
                action->m_status = RA_I2C_STATUS_Aborted;
                break;
            }
        }
        i2c_reg->ICSR2_b.NACKF = 0;
        i2c_reg->ICSR2_b.STOP = 0;
    } else {
        ra_i2c_xunit_read_byte(ch, unit);
        ra_i2c_xaction_start(ch, action, true);
    }
}

void ra_i2c_stop_confition(uint32_t ch) {
    R_IIC0_Type *i2c_reg = i2c_regs[ch];
    i2c_reg->ICSR2_b.NACKF = 0;
    i2c_reg->ICSR2_b.STOP = 0;
    i2c_reg->ICCR2_b.SP = 1;
    uint32_t timeout = RA_I2C_TIMEOUT_STOP_CONDITION;
    while (i2c_reg->ICSR2_b.STOP == 0) {
        if (timeout-- == 0) {
            break;
        }
    }
    i2c_reg->ICSR2_b.STOP = 0;
}

void ra_i2c_abort(uint32_t ch) {
    R_IIC0_Type *i2c_reg = i2c_regs[ch];
    xaction_t *action = current_xaction;
    ra_i2c_stop_confition(ch);
    i2c_reg->ICIER = 0x00;
    while (0x00 != i2c_reg->ICIER) {
        ;
    }
    (void)i2c_reg->ICDRR;  // dummy read
    i2c_reg->ICCR1_b.ICE = 0;
    action->m_status = RA_I2C_STATUS_Aborted;
}

void ra_i2c_xaction_start(uint32_t ch, xaction_t *action, bool repeated_start) {
    uint8_t address;
    uint32_t timeout;
    R_IIC0_Type *i2c_reg = i2c_regs[ch];

    current_xaction = action;
    current_xaction_unit = &action->units[action->m_current];
    xaction_unit_t *unit = current_xaction_unit;

    uint8_t cks;
    uint8_t brh;
    uint8_t brl;
    ra_i2c_clock_calc(action->m_clock, &cks, &brh, &brl);
    uint32_t state = ra_disable_irq();
    i2c_reg->ICCR1_b.ICE = 0;  // I2C disable
    i2c_reg->ICMR1_b.CKS = cks;
    i2c_reg->ICBRH_b.BRH = brh;
    i2c_reg->ICBRL_b.BRL = brl;
    i2c_reg->ICIER = 0xF0;     // I2C bus enable
    i2c_reg->ICCR1_b.ICE = 1;  // I2C enable
    address = 0xFE & (action->m_address << 1);
    address |= unit->m_fread ? 0x1 : 0x0;
    i2c_reg->ICCR2_b.MST = 1;  // I2C master
    i2c_reg->ICCR2_b.TRS = 1;  // I2C transmit
    if (repeated_start) {
        timeout = RA_I2C_TIMEOUT_BUS_BUSY;
        while (i2c_reg->ICCR2_b.BBSY == 0) {
            if (timeout-- == 0) {
                break;
            }
        }
        i2c_reg->ICCR2_b.RS = 1;  // I2C repeatedstart condition
        while (i2c_reg->ICCR2_b.RS == 1) {
            ;
        }
        // while (i2c_reg->ICSR2_b.TDRE == 0) { ; }
    } else {
        timeout = RA_I2C_TIMEOUT_BUS_BUSY;
        while (i2c_reg->ICCR2_b.BBSY) {
            if (timeout-- == 0) {
                ra_i2c_abort(ch);
                return;
            }
        }
        i2c_reg->ICCR2_b.ST = 1;  // I2C start condition
        timeout = RA_I2C_TIMEOUT_BUS_BUSY;
        while (true) {
            if (i2c_reg->ICSR2_b.TDRE != 0) {
                break;
            }
            if (timeout-- == 0) {
                ra_i2c_abort(ch);
                return;
            }
        }
    }
    i2c_reg->ICDRT = address;  // I2C send slave address
                               // TODO: handling 10 bit address
    timeout = RA_I2C_TIMEOUT_BUS_BUSY;
    while (true) {
        if (i2c_reg->ICSR2_b.TDRE != 0) {
            break;
        }
        if (timeout-- == 0) {
            ra_i2c_abort(ch);
            return;
        }
    }
    if (!unit->m_fread) {
        i2c_reg->ICIER |= 0xc0; /* TIE | TEIE */
    } else {
        timeout = RA_I2C_TIMEOUT_BUS_BUSY;
        while (true) {
            if (i2c_reg->ICSR2_b.RDRF == 1) {
                if (i2c_reg->ICSR2_b.NACKF == 1) {
                    ra_i2c_abort(ch);
                    return;
                }
                break;
            }
            if (timeout-- == 0) {
                ra_i2c_abort(ch);
                return;
            }
        }
        i2c_reg->ICIER |= 0x38; /* RIE | NAKIE | SPIE */
        if (unit->m_bytes_transfer == 1) {
            i2c_reg->ICMR3_b.WAIT = 1;
            i2c_reg->ICMR3_b.ACKBT = 1;
        }
        (void)i2c_reg->ICDRR;  // dummy read
    }
    action->m_status = RA_I2C_STATUS_Processing;
    ra_i2c_enable(ch);
    ra_enable_irq(state);
}

void ra_i2c_xaction_stop(uint32_t ch) {
    uint32_t state = ra_disable_irq();
    R_IIC0_Type *i2c_reg = i2c_regs[ch];
    ra_i2c_disable(ch);
    i2c_reg->ICIER = 0x00;
    i2c_reg->ICCR1_b.ICE = 0;
    current_xaction = (xaction_t *)NULL;
    current_xaction_unit = (xaction_unit_t *)NULL;
    ra_enable_irq(state);
}

void ra_i2c_xunit_write_byte(uint32_t ch, xaction_unit_t *unit) {
    R_IIC0_Type *i2c_reg = i2c_regs[ch];
    while (i2c_reg->ICSR2_b.TDRE == 0) {
        ;
    }
    i2c_reg->ICDRT = unit->buf[unit->m_bytes_transferred];
    ++unit->m_bytes_transferred;
    --unit->m_bytes_transfer;
}

void ra_i2c_xunit_read_byte(uint32_t ch, xaction_unit_t *unit) {
    R_IIC0_Type *i2c_reg = i2c_regs[ch];
    uint8_t data = i2c_reg->ICDRR;
    unit->buf[unit->m_bytes_transferred] = data;
    ++unit->m_bytes_transferred;
    --unit->m_bytes_transfer;
}

void ra_i2c_xunit_init(xaction_unit_t *unit, uint8_t *buf, uint32_t size, bool fread, void *next) {
    unit->m_bytes_transferred = 0;
    unit->m_bytes_transfer = size;
    unit->m_fread = fread;
    unit->buf = buf;
    unit->next = (void *)next;
}

void ra_i2c_xaction_init(xaction_t *action, xaction_unit_t *units, uint32_t size, uint32_t clock, uint32_t address) {
    action->units = units;
    action->m_num_of_units = size;
    action->m_current = 0;
    action->m_clock = clock;
    action->m_address = address;
    action->m_status = RA_I2C_STATUS_Idle;
}

static void ra_i2c_iceri_isr(uint32_t ch) {
    R_IIC0_Type *i2c_reg = i2c_regs[ch];
    // Check Timeout
    if ((i2c_reg->ICSR2_b.TMOF != 0) && (i2c_reg->ICIER_b.TMOIE != 0)) {
        i2c_reg->ICSR2_b.TMOF = 0;
    }
    // Check Arbitration Lost
    if ((i2c_reg->ICSR2_b.AL != 0) && (i2c_reg->ICIER_b.ALIE != 0)) {
        i2c_reg->ICSR2_b.AL = 0;
    }
    // Check stop condition detection
    if ((i2c_reg->ICSR2_b.STOP != 0) && (i2c_reg->ICIER_b.SPIE != 0)) {
        i2c_reg->ICSR2_b.STOP = 0;
    }
    // Check NACK reception
    if ((i2c_reg->ICSR2_b.NACKF != 0) && (i2c_reg->ICIER_b.NAKIE != 0)) {
        uint8_t dummy;
        i2c_reg->ICSR2_b.NACKF = 0;
    }
    // Check start condition detection
    if ((i2c_reg->ICSR2_b.START != 0) && (i2c_reg->ICIER_b.STIE != 0)) {
        i2c_reg->ICSR2_b.START = 0;
    }
}

static void ra_i2c_icrxi_isr(uint32_t ch) {
    R_IIC0_Type *i2c_reg = i2c_regs[ch];
    xaction_unit_t *unit = current_xaction_unit;
    xaction_t *xaction = current_xaction;
    while (i2c_reg->ICSR2_b.RDRF == 0) {
        ;
    }
    if (unit->m_bytes_transfer > 2) {
        if (unit->m_bytes_transfer == 3) {
            i2c_reg->ICMR3_b.WAIT = 1;
        }
        ra_i2c_xunit_read_byte(ch, unit);
    } else if (unit->m_bytes_transfer == 2) {
        i2c_reg->ICMR3_b.ACKBT = 1;
        ra_i2c_xunit_read_byte(ch, unit);
    } else {
        ra_i2c_read_last_byte(ch);
    }
}

static void ra_i2c_ictxi_isr(uint32_t ch) {
    R_IIC0_Type *i2c_reg = i2c_regs[ch];
    xaction_unit_t *unit = current_xaction_unit;
    // GLOBAL_LOCK(irq);
    if (unit->m_bytes_transfer) {
        ra_i2c_xunit_write_byte(ch, unit);
        if ((unit->m_bytes_transfer == 0) && (unit->next != (void *)NULL)) {
            current_xaction_unit = (xaction_unit_t *)unit->next;
        }
    } else {
        i2c_reg->ICIER_b.TIE = 0;
    }
}

static void ra_i2c_ictei_isr(uint32_t ch) {
    R_IIC0_Type *i2c_reg = i2c_regs[ch];
    xaction_t *action = current_xaction;
    xaction_unit_t *unit = current_xaction_unit;
    i2c_reg->ICIER_b.TEIE = 0;
    action->m_current++;
    if (action->m_current == action->m_num_of_units) {
        ra_i2c_stop_confition(ch);
        // xAction->Signal(I2C_HAL_XACTION::c_Status_Completed );
        action->m_status = RA_I2C_STATUS_Completed;
    } else {
        ra_i2c_xaction_start(ch, action, true);
    }
}

void iic_master_rxi_isr(void) {
    IRQn_Type irq = R_FSP_CurrentIrqGet();
    uint8_t ch = irq_to_ch[(uint32_t)irq];
    ra_i2c_icrxi_isr((uint32_t)ch);
    R_BSP_IrqStatusClear(irq);
}

void iic_master_txi_isr(void) {
    IRQn_Type irq = R_FSP_CurrentIrqGet();
    uint8_t ch = irq_to_ch[(uint32_t)irq];
    ra_i2c_ictxi_isr((uint32_t)ch);
    R_BSP_IrqStatusClear(irq);
}

void iic_master_tei_isr(void) {
    IRQn_Type irq = R_FSP_CurrentIrqGet();
    uint8_t ch = irq_to_ch[(uint32_t)irq];
    ra_i2c_ictei_isr((uint32_t)ch);
    R_BSP_IrqStatusClear(irq);
}

void iic_master_eri_isr(void) {
    IRQn_Type irq = R_FSP_CurrentIrqGet();
    uint8_t ch = irq_to_ch[(uint32_t)irq];
    ra_i2c_iceri_isr((uint32_t)ch);
    R_BSP_IrqStatusClear(irq);
}

bool ra_i2c_action_execute(uint32_t ch, xaction_t *action, bool repeated_start, uint32_t timeout_ms) {
    bool flag = false;
    timeouts[ch] = timeout_ms;
    uint32_t start = uwTick;
    ra_i2c_xaction_start(ch, action, repeated_start);
    while (true) {
        if (action->m_status == RA_I2C_STATUS_Completed) {
            flag = true;
            break;
        }
        if (action->m_status == RA_I2C_STATUS_Aborted) {
            break;
        }
        if (uwTick - start > timeout_ms) {
            break;
        }
    }
    ra_i2c_xaction_stop(ch);
    return flag;
}

