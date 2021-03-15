# sample_spi_serial_flash.py
# execute READ IDENTICATION command
#
from machine import Pin, SPI

spi = SPI(1, baudrate=4000000)
cs = Pin.cpu.P103
cs.init(cs.OUT, True)

cmd = bytearray(4)
id = bytearray(4)
cmd[0] = 0x9F
cs.low()
spi.write_readinto(cmd, id)
cs.high()

# print("".join("\\x%02x" % i for i in cmd))
# print("".join("\\x%02x" % i for i in id))

print("Manufacturer ID: %02x" % id[1])
print("Memory type    : %02x" % id[2])
print("Memory capacity: %02x" % id[3])
