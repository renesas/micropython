from pyb import Pin, ADC, ADCAll

# bit0:  AN000
# bit28: AN028
# bit29: temperature sensor
# bit30: core vref
# 0x60000003 -> AN000, AN001, AN016, temperature and core vref
ch_mask = 0x60010003
adcall = ADCAll(12, ch_mask)
i = 0
bit = 1
while i < 32:
    if (ch_mask & bit) != 0:
        v = adcall.read_channel(i)
        l = "AN{0:03d} = {1:d}".format(i, v)
        print(l)
    i += 1
    bit = bit << 1

print("core temperature (c): " + str(adcall.read_core_temp()))
print("core vref (v): " + str(adcall.read_core_vref()))
print("vref (v): " + str(adcall.read_vref()))

adc = ADC(Pin("P500"))
while True:
    val = adc.read()
    print(val)
    pyb.delay(500)
