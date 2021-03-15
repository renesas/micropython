import pyb

# test basic functionality
ext = pyb.ExtInt("P302", pyb.ExtInt.IRQ_FALLING, pyb.Pin.PULL_UP, lambda l: print("line:", l))
ext.disable()
ext.enable()
# print(ext.line())
# ext.swint()

# test swint while disabled, then again after re-enabled
ext.disable()
# ext.swint()
ext.enable()
# ext.swint()

# disable now that the test is finished
ext.disable()
