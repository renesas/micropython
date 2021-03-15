# check basic functionality of the timer class

import pyb
from pyb import Timer

tim = Timer(1)
tim = Timer(1, freq=200)
print(tim.freq())

# Setting and printing frequency
tim = Timer(2, freq=100)
print(tim.freq())
tim.freq(2)
print("{:.3f}".format(tim.freq()))
