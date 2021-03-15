from pyb import Pin, ExtInt


def callback(e):
    return print("intr")


ext = ExtInt(Pin(Pin.cpu.P105, Pin.IN, Pin.PULL_UP), ExtInt.IRQ_RISING, Pin.PULL_UP, callback)
