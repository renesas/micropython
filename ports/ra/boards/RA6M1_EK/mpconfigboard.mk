CMSIS_MCU = RA6M1
MCU_SERIES = m33
MCU_NUMBER = R7FA6M1AB3CFP
LD_FILES = boards/RA6M1_EK/ra6m1_ek.ld
START_FILE = boards/ra6m1_ek/ra/fsp/src/bsp/cmsis/Device/RENESAS/Source/startup.c

# MicroPython settings
MICROPY_VFS_FAT = 1
MICROPY_PY_USSL=0
MICROPY_SSL_MBEDTLS=0
MICROPY_PY_ESP8266=0

# comment out -> don't include default frozen modules because MCU is tight on flash space
# FROZEN_MANIFEST ?=
