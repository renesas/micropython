#define MICROPY_HW_BOARD_NAME       "RA4W1_EK"
#define MICROPY_HW_MCU_NAME         "RA4W1"
#define MICROPY_HW_MCU_SYSCLK       32000000
#define MICROPY_HW_MCU_PCLK         32000000

#define MICROPY_EMIT_THUMB          (1)
#define MICROPY_EMIT_INLINE_THUMB   (1)
#define MICROPY_PY_BUILTINS_COMPLEX (1)
#define MICROPY_PY_GENERATOR_PEND_THROW (1)
#define MICROPY_PY_MATH             (1)
#define MICROPY_PY_FRAMEBUF         (1)
#define MICROPY_PY_USOCKET          (0)
#define MICROPY_PY_NETWORK          (0)
#define MICROPY_PY_STM              (0)
#define MICROPY_PY_PYB_LEGACY       (1)
#define MICROPY_PY_UHEAPQ           (1)
#define MICROPY_PY_UTIMEQ           (1)

#define MICROPY_PY_THREAD           (1)

#define MICROPY_HW_ENABLE_INTERNAL_FLASH_STORAGE (1)
#define MICROPY_HW_ENABLE_RTC       (1)
#define MICROPY_HW_RTC_SOURCE       (1)     // 0: subclock, 1: LOCO (32.768khz)
#define MICROPY_HW_ENABLE_ADC       (1)

#define MICROPY_HW_HAS_SWITCH       (1)
#define MICROPY_HW_HAS_FLASH        (1)
#define MICROPY_HW_ENABLE_SDCARD    (1)
#define MICROPY_HW_SDCARD_MOUNT_AT_BOOT (0)
#define MICROPY_HW_ENABLE_SERVO     (0)
#define MICROPY_HW_ENABLE_RA_USB    (0)
#define MICROPY_HW_ETH_RA           (0)

// UART config
#define MICROPY_HW_UART1_TX         (pin_P101)
#define MICROPY_HW_UART1_RX         (pin_P100)
// #define MICROPY_HW_UART2_CTS        (pin_P103)
#define MICROPY_HW_UART2_TX         (pin_P213)
#define MICROPY_HW_UART2_RX         (pin_P212)
// #define MICROPY_HW_UART2_CTS        (pin_P101)
#define MICROPY_HW_UART5_TX         (pin_P205)
#define MICROPY_HW_UART5_RX         (pin_P206)
// #define MICROPY_HW_UART5_CTS        (pin_P407)
#define MICROPY_HW_UART_REPL        PYB_UART_5
#define MICROPY_HW_UART_REPL_BAUD   115200

// I2C busses
#define MICROPY_HW_I2C1_NAME "X"
#define MICROPY_HW_I2C1_SCL         (pin_P204)
#define MICROPY_HW_I2C1_SDA         (pin_P407)
#define MICROPY_HW_I2C2_NAME "Y"
#define MICROPY_HW_I2C2_SCL         (pin_P205)
#define MICROPY_HW_I2C2_SDA         (pin_P206)

// SPI busses
#define MICROPY_HW_SPI1_NAME "X"
#define MICROPY_HW_SPI1_NSS         (pin_P103)
#define MICROPY_HW_SPI1_SCK         (pin_P102)
#define MICROPY_HW_SPI1_MISO        (pin_P100)
#define MICROPY_HW_SPI1_MOSI        (pin_P101)
#define MICROPY_HW_SPI2_NAME "Y"
#define MICROPY_HW_SPI2_NSS         (pin_P108)
#define MICROPY_HW_SPI2_SCK         (pin_P111)
#define MICROPY_HW_SPI2_MISO        (pin_P110)
#define MICROPY_HW_SPI2_MOSI        (pin_P109)
// USRSW is pulled low. Pressing the button makes the input go high.
#define MICROPY_HW_USRSW_PIN        (pin_P402)
#define MICROPY_HW_USRSW_PULL       (GPIO_NOPULL)
#define MICROPY_HW_USRSW_EXTI_MODE  (GPIO_MODE_IT_FALLING)
#define MICROPY_HW_USRSW_PRESSED    (0)

// LEDs
#define MICROPY_HW_LED1             (pin_P106)
#define MICROPY_HW_LED2             (pin_P404)
#define MICROPY_HW_LED_ON(pin)      mp_hal_pin_high(pin)
#define MICROPY_HW_LED_OFF(pin)     mp_hal_pin_low(pin)
#define MICROPY_HW_LED_TOGGLE(pin)  mp_hal_pin_toggle(pin)
#if MICROPY_HW_ENABLE_SDCARD
// SD card detect switch
//#define MICROPY_HW_SDCARD_DETECT_PIN        (pin_P402)
#define MICROPY_HW_SDCARD_DETECT_PULL       (GPIO_PULLUP)
#define MICROPY_HW_SDCARD_DETECT_PRESENT    (0)
#define MICROPY_HW_SDCARD_SPI_CH            (0)
#define MICROPY_HW_SDCARD_SPI_CS            (pin_P204)
#define MICROPY_HW_SDCARD_SPI_CK            (pin_P102)
#define MICROPY_HW_SDCARD_SPI_MOSI          (pin_P101)
#define MICROPY_HW_SDCARD_SPI_MISO          (pin_P100)
#endif

//#define MICROPY_HW_ENABLE_DAC   (0)

//#define MICROPY_HW_HAS_ESP8266              (0)
//#define MICROPY_HW_ESP8266_UART_CH          1
//#define MICROPY_HW_ESP8266_UART_BAUD        115200
//#define MICROPY_HW_ESP8266_EN               (pin_P400)

//#define MICROPY_PY_PYB_TWITTER      (0)
//#define MICROPY_PY_PYB_FONT         (0)
//#define MICROPY_PY_PYB_UNICODE_FONT (0)
//#define MICROPY_PY_PYB_LCDSPI       (0)

//#define MICROPY_HW_LCDSPI_CLK   (pin_P102)
//#define MICROPY_HW_LCDSPI_MOSI  (pin_P101)
//#define MICROPY_HW_LCDSPI_MISO  (pin_P100)
//#define MICROPY_HW_LCDSPI_CS    (pin_P502)
//#define MICROPY_HW_LCDSPI_RESET (pin_P501)
//#define MICROPY_HW_LCDSPI_RS    (pin_P014)

