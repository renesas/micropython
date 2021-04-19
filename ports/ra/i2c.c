/*
 * This file is part of the MicroPython project, http://micropython.org/
 *
 * The MIT License (MIT)
 *
 * Copyright (c) 2018 Damien P. George
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

#include "py/mperrno.h"
#include "py/mphal.h"
#include "py/runtime.h"
#include "i2c.h"

#if MICROPY_HW_ENABLE_HW_I2C

i2c_t i2c_obj[] = {
    {1, 8, 100000},
    {2, 8, 100000},
    {3, 8, 100000},
    {4, 8, 100000},
};

int i2c_init(i2c_t *i2c, mp_hal_pin_obj_t scl, mp_hal_pin_obj_t sda, uint32_t freq, uint16_t timeout_ms) {
    ra_i2c_init(i2c->i2c_id - 1, scl->pin, sda->pin, freq, timeout_ms);
    return 0;
}

int i2c_start_addr(i2c_t *i2c, int rd_wrn, uint16_t addr, size_t next_len, bool stop) {
    i2c->addr = addr;
    return 0;
}

// next_len = 0 or N (>=2)
int i2c_read(i2c_t *i2c, uint8_t *dest, size_t len, size_t next_len) {
    bool flag;
    xaction_t action;
    xaction_unit_t unit;
    ra_i2c_xunit_init(&unit, (uint8_t *)dest, (uint32_t)len, true, (void *)NULL);
    ra_i2c_xaction_init(&action, (xaction_unit_t *)&unit, 1, i2c->freq, (uint32_t)i2c->addr);
    flag = ra_i2c_action_execute(i2c->i2c_id - 1, &action, false, 100);
    return flag? 0:1;
}

// next_len = 0 or N
int i2c_write(i2c_t *i2c, const uint8_t *src, size_t len, size_t next_len) {
    bool flag;
    xaction_t action;
    xaction_unit_t unit;
    ra_i2c_xunit_init(&unit, (uint8_t *)src, (uint32_t)len, false, (void *)NULL);
    ra_i2c_xaction_init(&action, (xaction_unit_t *)&unit, 1, i2c->freq, (uint32_t)i2c->addr);
    flag = ra_i2c_action_execute(i2c->i2c_id - 1, &action, false, 100);
    return flag? 0:1;
}

bool i2c_ready(i2c_t *i2c, uint16_t i2c_addr) {
    uint8_t dummy;
    i2c->addr = i2c_addr;
    int ret = i2c_read(i2c, &dummy, 1, 0);
    if (ret == 0) {
        return true;
    } else {
        return false;
    }
}

STATIC const uint8_t i2c_available =
    0
    #if defined(MICROPY_HW_I2C1_SCL)
    | 1 << 1
    #endif
    #if defined(MICROPY_HW_I2C2_SCL)
    | 1 << 2
    #endif
    #if defined(MICROPY_HW_I2C3_SCL)
    | 1 << 3
    #endif
    #if defined(MICROPY_HW_I2C4_SCL)
    | 1 << 4
    #endif
;

int i2c_find_peripheral(mp_obj_t id) {
    int i2c_id = 0;
    if (mp_obj_is_str(id)) {
        const char *port = mp_obj_str_get_str(id);
        if (0) {
        #ifdef MICROPY_HW_I2C1_NAME
        } else if (strcmp(port, MICROPY_HW_I2C1_NAME) == 0) {
            i2c_id = 1;
        #endif
        #ifdef MICROPY_HW_I2C2_NAME
        } else if (strcmp(port, MICROPY_HW_I2C2_NAME) == 0) {
            i2c_id = 2;
        #endif
        #ifdef MICROPY_HW_I2C3_NAME
        } else if (strcmp(port, MICROPY_HW_I2C3_NAME) == 0) {
            i2c_id = 3;
        #endif
        #ifdef MICROPY_HW_I2C4_NAME
        } else if (strcmp(port, MICROPY_HW_I2C4_NAME) == 0) {
            i2c_id = 4;
        #endif
        } else {
            mp_raise_msg_varg(&mp_type_ValueError, MP_ERROR_TEXT("I2C(%s) doesn't exist"), port);
        }
    } else {
        i2c_id = mp_obj_get_int(id);
        if (i2c_id < 1 || i2c_id >= 8 * sizeof(i2c_available) || !(i2c_available & (1 << i2c_id))) {
            mp_raise_msg_varg(&mp_type_ValueError, MP_ERROR_TEXT("I2C(%d) doesn't exist"), i2c_id);
        }
    }

    // check if the I2C is reserved for system use or not
    if (MICROPY_HW_I2C_IS_RESERVED(i2c_id)) {
        mp_raise_msg_varg(&mp_type_ValueError, MP_ERROR_TEXT("I2C(%d) is reserved"), i2c_id);
    }

    return i2c_id;
}

#endif // MICROPY_HW_ENABLE_HW_I2C
