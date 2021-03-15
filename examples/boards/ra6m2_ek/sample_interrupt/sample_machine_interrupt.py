from machine import Pin


def callback(p):
    print(" pin change", p)
    return


p0 = Pin(Pin.cpu.P105, Pin.IN)

p0.irq(trigger=Pin.IRQ_FALLING, handler=callback)
