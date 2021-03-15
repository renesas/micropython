# sample_mikroe3469.py
# Read and print temperature and humidity
# RA4M1 Clicker: scl: P205, sda: P206
# EK-RA6M2: scl: P100, sda: P206
#

from pyb import I2C
import time

i2c = I2C(2)
i2c.init()

HDC_ADDR = 64
TEMP_REG = 0x00
HUM_REG = 0x01

i2c.send(bytearray([TEMP_REG]), HDC_ADDR)
time.sleep_ms(100)
data = i2c.recv(2, HDC_ADDR)
temperature = (int.from_bytes(data, "big") / 2 ** 16) * 165 - 40
print("temperature: " + str(temperature))

i2c.send(bytearray([HUM_REG]), HDC_ADDR)
time.sleep_ms(100)
data = i2c.recv(2, HDC_ADDR)
humidity = (int.from_bytes(data, "big") / 2 ** 16) * 100
print("humidity: " + str(humidity))
