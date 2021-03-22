CMSIS_MCU = RA4W1
MCU_SERIES = m4
MCU_NUMBER = R7FA4W1AD2CNG
LD_FILES = boards/RA4W1_EK/ra4w1_ek.ld
START_FILE = boards/RA4W1_EK/ra/fsp/src/bsp/cmsis/Device/RENESAS/Source/startup.c

# MicroPython settings
MICROPY_VFS_FAT = 1
MICROPY_PY_USSL=0
MICROPY_SSL_MBEDTLS=0
MICROPY_PY_ESP8266=0

# comment out -> don't include default frozen modules because MCU is tight on flash space
# FROZEN_MANIFEST ?=
