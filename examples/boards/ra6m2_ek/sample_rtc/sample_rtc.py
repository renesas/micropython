from pyb import RTC

rtc = RTC()
rtc.datetime((2021, 1, 16, 12, 10, 48, 0, 0))  # set a specific date and time
rtc.datetime()  # get date and time

ms = 2000
rtc.wakeup(ms)
pyb.stop()
rtc.wakeup(None)

# rtc feature of machine module is not supported for RA MCU
# rtc = machine.RTC()
# rtc.init((2021, 1, 16, 12, 10, 0, 0, 0))
# print(rtc.now())
