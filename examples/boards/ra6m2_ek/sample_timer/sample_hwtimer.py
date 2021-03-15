from pyb import Timer

tim = Timer(2)
tim.init(freq=100, callback=lambda t: print(2))
