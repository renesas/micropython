.. _ra_quickref:

Quick reference for the RA port
===============================

As of Mar-2021, RA4M1 Clicker board and EK-RA6M2 board are officially supported.

Below is a quick reference for the RA port.  If it is your first time working
with this board please consider reading the following sections first:

.. toctree::
   :maxdepth: 1

   general.rst
   tutorial/index.rst


General board control
---------------------

"rab" module is the micropython module specific for RA boards. 
"rab" module is internally defined as alias of "pyb" module.  
"rab" and "pyb" are the same module for RA MCU port of MicroPython.
However some of "Pyboard" features are not implemented for RA MCU port.

See :mod:`pyb`. ::

    import pyb

    pyb.repl_uart(pyb.UART(1, 9600)) # duplicate REPL on UART(1)
    pyb.wfi() # pause CPU, waiting for interrupt
    pyb.freq() # get CPU and bus frequencies
    #pyb.freq(60000000) # set CPU freq to 60MHz
    pyb.stop() # stop CPU, waiting for external interrupt

Delay and timing
----------------

Use the :mod:`time <utime>` module::

    import time

    time.sleep(1)           # sleep for 1 second
    time.sleep_ms(500)      # sleep for 500 milliseconds
    time.sleep_us(10)       # sleep for 10 microseconds
    start = time.ticks_ms() # get value of millisecond counter
    delta = time.ticks_diff(time.ticks_ms(), start) # compute time difference

Internal LEDs
-------------

See :ref:`pyb.LED <pyb.LED>`. ::

    from pyb import LED

    led = LED(1) # The number of LEDs depends on the supported boards.
    led.toggle()
    led.on()
    led.off()

Internal switch
---------------

See :ref:`pyb.Switch <pyb.Switch>`. ::

    from pyb import Switch

    sw = Switch()
    sw.value() # returns True or False
    sw.callback(lambda: pyb.LED(1).toggle())

Pins and GPIO
-------------

See :ref:`pyb.Pin <pyb.Pin>`. ::

    from pyb import Pin

    p_out = Pin('P100', Pin.OUT_PP)
    p_out.high()
    p_out.low()

    p_in = Pin('P100', Pin.IN, Pin.PULL_UP)
    p_in.value() # get value, 0 or 1

    Pin.PULL_DOWN is not supportd for the RA port.

External interrupts
-------------------

See :ref:`pyb.ExtInt <pyb.ExtInt>`. ::

    from pyb import Pin, ExtInt

    callback = lambda e: print("intr")
    ext = ExtInt(Pin('P105'), ExtInt.IRQ_RISING, Pin.PULL_NONE, callback)

Timers
------

See :ref:`pyb.Timer <pyb.Timer>`. ::

    So far Timer feature is not supported yet.
    Please use software timer which machine module supports.

    from machine import Timer
    tim = Timer(-1)
    tim.init(period=2000, mode=Timer.PERIODIC, callback=lambda t: print(2))

RTC (real time clock)
---------------------

See :ref:`pyb.RTC <pyb.RTC>` ::

    from pyb import RTC

    rtc = RTC()
    rtc.datetime((2017, 8, 23, 1, 12, 48, 0, 0)) # set a specific date and time
    rtc.datetime() # get date and time

ADC (analog to digital conversion)
----------------------------------

See :ref:`pyb.Pin <pyb.Pin>` and :ref:`pyb.ADC <pyb.ADC>`. ::

    from pyb import Pin, ADC
    adc = ADC(Pin('P505'))
    adc.read() # read value, 0-4095

UART (serial bus)
-----------------

See :ref:`pyb.UART <pyb.UART>`. ::

    from pyb import UART

    uart = UART(1, 9600)
    uart.write('hello')
    uart.read(5) # read up to 5 bytes

SPI bus
-------

See :ref:`pyb.SPI <pyb.SPI>`. ::

    from pyb import SPI

    spi = SPI(1, SPI.MASTER, baudrate=200000, polarity=1, phase=0)
    spi.send('hello')
    spi.recv(5) # receive 5 bytes on the bus
    spi.send_recv('hello') # send and receive 5 bytes

I2C bus
-------

Software I2C is also available by explicitly specifying the
``scl`` and ``sda`` pins instead of the bus name.  For more details see
:ref:`machine.I2C <machine.I2C>`. ::

    from machine import I2C

    # Pin assignment is different between boards
    i2c = I2C(scl='P100', sda='P205', freq=100000)  # create software I2C object

    i2c.scan()                          # returns list of slave addresses
    i2c.writeto(0x42, 'hello')          # write 5 bytes to slave with address 0x42
    i2c.readfrom(0x42, 5)               # read 5 bytes from slave

    i2c.readfrom_mem(0x42, 0x10, 2)     # read 2 bytes from slave 0x42, slave memory 0x10
    i2c.writeto_mem(0x42, 0x10, 'xy')   # write 2 bytes to slave 0x42, slave memory 0x10

