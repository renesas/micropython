from pyb import Pin, ADC

adc = ADC(Pin("P000"))
while True:
    val = adc.read()
    print(val)
    pyb.delay(500)
