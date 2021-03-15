import pyb, time

led1 = pyb.LED(1)
led2 = pyb.LED(2)
while True:
    led1.toggle()
    time.sleep_ms(200)
    led1.toggle()
    time.sleep_ms(200)
    led2.toggle()
    time.sleep_ms(200)
    led2.toggle()
    time.sleep_ms(200)
