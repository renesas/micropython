from pyb import Pin, SDCard
import os

sd = SDCard()
os.mount(sd, "/sd")
os.listdir("/sd")

f = open("data.txt", "w")
f.write("some data")
f.close()


p103_out = Pin("P103", Pin.OUT_PP)
p103_out.high()
