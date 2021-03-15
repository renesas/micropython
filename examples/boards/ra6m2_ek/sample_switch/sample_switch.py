import pyb

sw = pyb.Switch()  # create a switch object
sw.value()  # get state (True if pressed, False otherwise)
sw()  # shorthand notation to get the switch state

pyb.Switch().callback(lambda: pyb.LED(1).toggle())
