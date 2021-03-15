import pyb, time

led = pyb.LED(1)
while True:
    led.toggle()
    time.sleep_ms(1000)
