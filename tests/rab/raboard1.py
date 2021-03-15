# basic tests of pyb module

import pyb
import time
import machine

# test delay

time.sleep_ms(-1)
time.sleep_ms(0)
time.sleep_ms(1)

start = time.ticks_ms()
time.sleep_ms(17)
print((time.ticks_ms() - start) // 5)  # should print 3

# test udelay

time.sleep_us(-1)
time.sleep_us(0)
time.sleep_us(1)

start = time.ticks_ms()
time.sleep_us(17000)
print((time.ticks_ms() - start) // 5)  # should print 3

# other

pyb.disable_irq()
pyb.enable_irq()

# print(pyb.have_cdc())

# pyb.sync()

print(len(machine.unique_id()))

pyb.wfi()

# pyb.fault_debug(True)
# pyb.fault_debug(False)
