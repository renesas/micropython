import machine
import time

i2c = machine.I2C(scl=machine.Pin.cpu.P205, sda=machine.Pin.cpu.P206)

HDC_ADDR = 64
TEMP_REG = 0x00
HUM_REG = 0x01

i2c.writeto(HDC_ADDR, bytearray([TEMP_REG]))
time.sleep_ms(100)
data = i2c.readfrom(HDC_ADDR, 2)
temperature = (int.from_bytes(data, "big") / 2 ** 16) * 165 - 40
print("temperature: " + str(temperature))

i2c.writeto(HDC_ADDR, bytearray([HUM_REG]))
time.sleep_ms(100)
data = i2c.readfrom(HDC_ADDR, 2)
humidity = (int.from_bytes(data, "big") / 2 ** 16) * 100
print("humidity: " + str(humidity))
