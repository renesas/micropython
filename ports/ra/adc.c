/*
 * This file is part of the MicroPython project, http://micropython.org/
 *
 * The MIT License (MIT)
 *
 * Copyright (c) 2013, 2014 Damien P. George
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
#include <string.h>

#include "py/runtime.h"
#include "py/binary.h"
#include "py/mphal.h"
#include "adc.h"
#include "pin.h"
#include "timer.h"
#include "ra_adc.h"

#if MICROPY_HW_ENABLE_ADC

/// \moduleref pyb
/// \class ADC - analog to digital conversion: read analog values on a pin
///
/// Usage:
///
///     adc = pyb.ADC(pin)              # create an analog object from a pin
///     val = adc.read()                # read an analog value
///
///     adc = pyb.ADCAll(resolution)    # creale an ADCAll object
///     val = adc.read_channel(channel) # read the given channel
///     val = adc.read_core_temp()      # read MCU temperature
///     val = adc.read_core_vbat()      # read MCU VBAT
///     val = adc.read_core_vref()      # read MCU VREF

/* ADC defintions */

typedef struct _pyb_obj_adc_t {
    mp_obj_base_t base;
    mp_obj_t pin_name;
    int pin_idx;
    int resolution;
    int channel;
    ADC_HandleTypeDef handle;
} pyb_obj_adc_t;

// convert user-facing channel number into internal channel number
static inline uint32_t adc_get_internal_channel(uint32_t channel) {
    return channel;
}

STATIC uint32_t adc_config_and_read_channel(ADC_HandleTypeDef *adcHandle, uint32_t channel) {
    return (uint32_t)ra_adc_all_read_ch(channel);
}

/******************************************************************************/
/* MicroPython bindings : adc object (single channel)                         */

STATIC void adc_print(const mp_print_t *print, mp_obj_t self_in, mp_print_kind_t kind) {
    pyb_obj_adc_t *self = MP_OBJ_TO_PTR(self_in);
    mp_print_str(print, "<ADC on ");
    mp_obj_print_helper(print, self->pin_name, PRINT_STR);
    mp_printf(print, " channel=%u>", self->channel);
}

/// \classmethod \constructor(pin)
/// Create an ADC object associated with the given pin.
/// This allows you to then read analog values on that pin.
STATIC mp_obj_t adc_make_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *args) {
    pyb_obj_adc_t *o = m_new_obj(pyb_obj_adc_t);
    // check number of arguments
    mp_arg_check_num(n_args, n_kw, 1, 1, false);

    // 1st argument is the pin name
    mp_obj_t pin_obj = args[0];
    int8_t resolution = 0;
    int8_t channel = 0;
    int32_t pin_idx = -1;
    if (mp_obj_is_int(pin_obj)) {
        pin_idx = mp_obj_get_int(pin_obj);
    } else {
        const pin_obj_t *pin = pin_find(pin_obj);
        pin_idx = (int)pin->pin;
    }
    bool find = ra_adc_pin_to_ch((uint32_t)pin_idx, (uint8_t *)&channel);
    if (!find) {
        mp_raise_msg_varg(&mp_type_ValueError, MP_ERROR_TEXT("Pin(%d) does not have ADC capabilities"), pin_idx);
    }
    resolution = ra_adc_get_resolution();
    ra_adc_init();
    memset(o, 0, sizeof(*o));
    o->base.type = &pyb_adc_type;
    o->pin_name = pin_obj;
    o->pin_idx = pin_idx;
    o->resolution = (int)resolution;
    o->channel = (int)channel;
    ra_adc_enable((uint8_t)pin_idx);
    return MP_OBJ_FROM_PTR(o);
}

/// \method read()
/// Read the value on the analog pin and return it.  The returned value
/// will be between 0 and 4095.
STATIC mp_obj_t adc_read(mp_obj_t self_in) {
    pyb_obj_adc_t *self = MP_OBJ_TO_PTR(self_in);
    int value = (int)ra_adc_read((uint8_t)self->pin_idx);
    return mp_obj_new_int(value);
}
STATIC MP_DEFINE_CONST_FUN_OBJ_1(adc_read_obj, adc_read);

STATIC const mp_rom_map_elem_t adc_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR_read), MP_ROM_PTR(&adc_read_obj) },
};

STATIC MP_DEFINE_CONST_DICT(adc_locals_dict, adc_locals_dict_table);

const mp_obj_type_t pyb_adc_type = {
    { &mp_type_type },
    .name = MP_QSTR_ADC,
    .print = adc_print,
    .make_new = adc_make_new,
    .locals_dict = (mp_obj_dict_t *)&adc_locals_dict,
};

/******************************************************************************/
/* adc all object                                                             */

typedef struct _pyb_adc_all_obj_t {
    mp_obj_base_t base;
    ADC_HandleTypeDef handle;
} pyb_adc_all_obj_t;

void adc_init_all(pyb_adc_all_obj_t *adc_all, uint32_t resolution, uint32_t en_mask) {
    ra_adc_init();
    ra_adc_all(resolution, en_mask);
}

int adc_get_resolution(ADC_HandleTypeDef *adcHandle) {
    return (int)ra_adc_get_resolution();
}

int adc_read_core_temp(ADC_HandleTypeDef *adcHandle) {
    int v = (int)ra_adc_read_itemp();
    return v;
}

#if MICROPY_PY_BUILTINS_FLOAT
// correction factor for reference value
STATIC volatile float adc_refcor = 1.0f;

float adc_read_core_temp_float(ADC_HandleTypeDef *adcHandle) {
    float temp = ra_adc_read_ftemp();
    return temp;
}

float adc_read_core_vbat(ADC_HandleTypeDef *adcHandle) {
    return 3.3f;
}

float adc_read_core_vref(ADC_HandleTypeDef *adcHandle) {
    float ref = ra_adc_read_fref();
    return ref;
}
#endif

/******************************************************************************/
/* MicroPython bindings : adc_all object                                      */

STATIC mp_obj_t adc_all_make_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *args) {
    // check number of arguments
    mp_arg_check_num(n_args, n_kw, 1, 2, false);

    // make ADCAll object
    pyb_adc_all_obj_t *o = m_new_obj(pyb_adc_all_obj_t);
    o->base.type = &pyb_adc_all_type;
    mp_int_t res = mp_obj_get_int(args[0]);
    uint32_t en_mask = 0xffffffff;
    if (n_args > 1) {
        en_mask = mp_obj_get_int(args[1]);
    }
    adc_init_all(o, res, en_mask);

    return MP_OBJ_FROM_PTR(o);
}

STATIC mp_obj_t adc_all_read_channel(mp_obj_t self_in, mp_obj_t channel) {
    pyb_adc_all_obj_t *self = MP_OBJ_TO_PTR(self_in);
    uint32_t chan = adc_get_internal_channel(mp_obj_get_int(channel));
    uint32_t data = adc_config_and_read_channel(&self->handle, chan);
    return mp_obj_new_int(data);
}
STATIC MP_DEFINE_CONST_FUN_OBJ_2(adc_all_read_channel_obj, adc_all_read_channel);

STATIC mp_obj_t adc_all_read_core_temp(mp_obj_t self_in) {
    pyb_adc_all_obj_t *self = MP_OBJ_TO_PTR(self_in);
    #if MICROPY_PY_BUILTINS_FLOAT
    float data = adc_read_core_temp_float(&self->handle);
    return mp_obj_new_float(data);
    #else
    int data = adc_read_core_temp(&self->handle);
    return mp_obj_new_int(data);
    #endif
}
STATIC MP_DEFINE_CONST_FUN_OBJ_1(adc_all_read_core_temp_obj, adc_all_read_core_temp);

#if MICROPY_PY_BUILTINS_FLOAT
STATIC mp_obj_t adc_all_read_core_vbat(mp_obj_t self_in) {
    pyb_adc_all_obj_t *self = MP_OBJ_TO_PTR(self_in);
    float data = adc_read_core_vbat(&self->handle);
    return mp_obj_new_float(data);
}
STATIC MP_DEFINE_CONST_FUN_OBJ_1(adc_all_read_core_vbat_obj, adc_all_read_core_vbat);

STATIC mp_obj_t adc_all_read_core_vref(mp_obj_t self_in) {
    pyb_adc_all_obj_t *self = MP_OBJ_TO_PTR(self_in);
    float data = adc_read_core_vref(&self->handle);
    return mp_obj_new_float(data);
}
STATIC MP_DEFINE_CONST_FUN_OBJ_1(adc_all_read_core_vref_obj, adc_all_read_core_vref);

STATIC mp_obj_t adc_all_read_vref(mp_obj_t self_in) {
    pyb_adc_all_obj_t *self = MP_OBJ_TO_PTR(self_in);
    adc_read_core_vref(&self->handle);
    return mp_obj_new_float(3.3 * adc_refcor);
}
STATIC MP_DEFINE_CONST_FUN_OBJ_1(adc_all_read_vref_obj, adc_all_read_vref);
#endif

STATIC const mp_rom_map_elem_t adc_all_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR_read_channel), MP_ROM_PTR(&adc_all_read_channel_obj) },
    { MP_ROM_QSTR(MP_QSTR_read_core_temp), MP_ROM_PTR(&adc_all_read_core_temp_obj) },
    #if MICROPY_PY_BUILTINS_FLOAT
    { MP_ROM_QSTR(MP_QSTR_read_core_vbat), MP_ROM_PTR(&adc_all_read_core_vbat_obj) },
    { MP_ROM_QSTR(MP_QSTR_read_core_vref), MP_ROM_PTR(&adc_all_read_core_vref_obj) },
    { MP_ROM_QSTR(MP_QSTR_read_vref), MP_ROM_PTR(&adc_all_read_vref_obj) },
    #endif
};

STATIC MP_DEFINE_CONST_DICT(adc_all_locals_dict, adc_all_locals_dict_table);

const mp_obj_type_t pyb_adc_all_type = {
    { &mp_type_type },
    .name = MP_QSTR_ADCAll,
    .make_new = adc_all_make_new,
    .locals_dict = (mp_obj_dict_t *)&adc_all_locals_dict,
};

#endif // MICROPY_HW_ENABLE_ADC
