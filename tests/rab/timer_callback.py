# check callback feature of the timer class

import pyb
from pyb import Timer
import time

# callback function that disables the callback when called
def cb1(t):
    print("cb1")
    t.callback(None)


# callback function that disables the timer when called
def cb2(t):
    print("cb2")
    t.deinit()


# create a timer with a callback, using callback(None) to stop
tim = Timer(1, freq=100, callback=cb1)
time.sleep_ms(2)
print("before cb1")
time.sleep_ms(15)

# create a timer with a callback, using deinit to stop
tim = Timer(2, freq=100, callback=cb2)
time.sleep_ms(2)
print("before cb2")
time.sleep_ms(15)
