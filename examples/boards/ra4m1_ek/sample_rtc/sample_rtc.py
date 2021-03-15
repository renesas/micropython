from pyb import RTC

rtc = RTC()
rtc.datetime((2021, 1, 16, 12, 10, 48, 0, 0))  # set a specific date and time
rtc.datetime()  # get date and time

# rtc feature of machine module is not supported for RA MCU
# rtc = machine.RTC()
# rtc.init((2021, 1, 16, 12, 10, 0, 0, 0))
# print(rtc.now())
