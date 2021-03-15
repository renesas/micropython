import os
from pyb import UART

machine = os.uname().machine
if (
    "RA6M2_EK" in machine
    or "RA4M1_EK" in machine
    or "RA4W1_EK" in machine
    or "RA6M1_EK" in machine
):
    uart_id = 3
elif "RA4M1_Clicker" in machine:
    uart_id = 1
else:
    print("SKIP")
    raise SystemExit

uart = UART(uart_id)
uart = UART(uart_id, 9600)
uart = UART(uart_id, 9600, bits=8, parity=None, stop=1)
# print(uart)

uart.init(2400)
# print(uart)

print(uart.any())
print(uart.write("123"))
print(uart.write(b"abcd"))
print(uart.writechar(1))

# make sure this method exists
uart.sendbreak()

# non-blocking mode
uart = UART(uart_id, 9600, timeout=0)
print(uart.write(b"1"))
print(uart.write(b"abcd"))
print(uart.writechar(1))
print(uart.read(100))

# set rxbuf
uart.init(9600, rxbuf=8)
# print(uart)
uart.init(9600, rxbuf=0)
# print(uart)

# set read_buf_len (legacy, use rxbuf instead)
uart.init(9600, read_buf_len=4)
# print(uart)
uart.init(9600, read_buf_len=0)
# print(uart)
