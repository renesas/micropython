from pyb import Pin, ExtInt


def callback1(e):
    return print("Pushed switch 1")


def callback2(e):
    return print("Pushed switch 2")


ext1 = ExtInt(Pin(Pin.cpu.P304, Pin.IN, Pin.PULL_UP), ExtInt.IRQ_RISING, Pin.PULL_UP, callback1)

ext2 = ExtInt(Pin(Pin.cpu.P301, Pin.IN, Pin.PULL_UP), ExtInt.IRQ_RISING, Pin.PULL_UP, callback2)
