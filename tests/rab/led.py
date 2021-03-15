import os, pyb
import time

machine = os.uname().machine
if "RA6M1_EK" in machine or "RA6M2_EK" in machine or "RA4W1_EK" in machine:
    leds = [pyb.LED(i) for i in range(1, 2)]
elif "RA4M1_EK" in machine or "RA4M1_Clicker" in machine:
    leds = [pyb.LED(i) for i in range(1, 2)]
else:
    print("SKIP")
    raise SystemExit

# test printing
for l in leds:
    print(l)

# test on and off
for l in leds:
    l.on()
    time.sleep_ms(100)
    l.off()
    time.sleep_ms(100)

# test toggle
for l in leds:
    l.toggle()
    time.sleep_ms(100)
