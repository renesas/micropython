from pyb import UART

uart1 = UART(1, 9600)
uart1.write("from RA4M1_EK board")
