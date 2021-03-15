/* generated vector header file - do not edit */
#ifndef VECTOR_DATA_H
#define VECTOR_DATA_H
/* Number of interrupts allocated */
#ifndef VECTOR_DATA_IRQ_COUNT
#define VECTOR_DATA_IRQ_COUNT    (28)
#endif
/* ISR prototypes */
void adc_scan_end_isr(void);
void sci_uart_rxi_isr(void);
void sci_uart_txi_isr(void);
void sci_uart_tei_isr(void);
void sci_uart_eri_isr(void);
void ctsu_write_isr(void);
void ctsu_read_isr(void);
void ctsu_end_isr(void);
void r_icu_isr(void);
void spi_rxi_isr(void);
void spi_txi_isr(void);
void spi_tei_isr(void);
void spi_eri_isr(void);
void fcu_frdyi_isr(void);
void rtc_alarm_periodic_isr(void);
void rtc_carry_isr(void);
void agt_int_isr(void);

/* Vector table allocations */
#define VECTOR_NUMBER_ADC0_SCAN_END ((IRQn_Type) 0) /* ADC0 SCAN END (A/D scan end interrupt) */
#define VECTOR_NUMBER_SCI0_RXI ((IRQn_Type) 1) /* SCI0 RXI (Receive data full) */
#define VECTOR_NUMBER_SCI0_TXI ((IRQn_Type) 2) /* SCI0 TXI (Transmit data empty) */
#define VECTOR_NUMBER_SCI0_TEI ((IRQn_Type) 3) /* SCI0 TEI (Transmit end) */
#define VECTOR_NUMBER_SCI0_ERI ((IRQn_Type) 4) /* SCI0 ERI (Receive error) */
#define VECTOR_NUMBER_CTSU_WRITE ((IRQn_Type) 5) /* CTSU WRITE (Write request interrupt) */
#define VECTOR_NUMBER_CTSU_READ ((IRQn_Type) 6) /* CTSU READ (Measurement data transfer request interrupt) */
#define VECTOR_NUMBER_CTSU_END ((IRQn_Type) 7) /* CTSU END (Measurement end interrupt) */
#define VECTOR_NUMBER_ICU_IRQ6 ((IRQn_Type) 8) /* ICU IRQ6 (External pin interrupt 6) */
#define VECTOR_NUMBER_ICU_IRQ5 ((IRQn_Type) 9) /* ICU IRQ5 (External pin interrupt 5) */
#define VECTOR_NUMBER_ICU_IRQ9 ((IRQn_Type) 10) /* ICU IRQ9 (External pin interrupt 9) */
#define VECTOR_NUMBER_SPI0_RXI ((IRQn_Type) 11) /* SPI0 RXI (Receive buffer full) */
#define VECTOR_NUMBER_SPI0_TXI ((IRQn_Type) 12) /* SPI0 TXI (Transmit buffer empty) */
#define VECTOR_NUMBER_SPI0_TEI ((IRQn_Type) 13) /* SPI0 TEI (Transmission complete event) */
#define VECTOR_NUMBER_SPI0_ERI ((IRQn_Type) 14) /* SPI0 ERI (Error) */
#define VECTOR_NUMBER_FCU_FRDYI ((IRQn_Type) 15) /* FCU FRDYI (Flash ready interrupt) */
#define VECTOR_NUMBER_RTC_PERIOD ((IRQn_Type) 16) /* RTC PERIOD (Periodic interrupt) */
#define VECTOR_NUMBER_RTC_CARRY ((IRQn_Type) 17) /* RTC CARRY (Carry interrupt) */
#define VECTOR_NUMBER_SCI1_RXI ((IRQn_Type) 18) /* SCI1 RXI (Received data full) */
#define VECTOR_NUMBER_SCI1_TXI ((IRQn_Type) 19) /* SCI1 TXI (Transmit data empty) */
#define VECTOR_NUMBER_SCI1_TEI ((IRQn_Type) 20) /* SCI1 TEI (Transmit end) */
#define VECTOR_NUMBER_SCI1_ERI ((IRQn_Type) 21) /* SCI1 ERI (Receive error) */
#define VECTOR_NUMBER_SCI9_RXI ((IRQn_Type) 22) /* SCI9 RXI (Received data full) */
#define VECTOR_NUMBER_SCI9_TXI ((IRQn_Type) 23) /* SCI9 TXI (Transmit data empty) */
#define VECTOR_NUMBER_SCI9_TEI ((IRQn_Type) 24) /* SCI9 TEI (Transmit end) */
#define VECTOR_NUMBER_SCI9_ERI ((IRQn_Type) 25) /* SCI9 ERI (Receive error) */
#define VECTOR_NUMBER_AGT0_INT ((IRQn_Type) 26) /* AGT0 INT (AGT interrupt) */
#define VECTOR_NUMBER_AGT1_INT ((IRQn_Type) 27) /* AGT1 INT (AGT interrupt) */
typedef enum IRQn
{
    Reset_IRQn = -15,
    NonMaskableInt_IRQn = -14,
    HardFault_IRQn = -13,
    MemoryManagement_IRQn = -12,
    BusFault_IRQn = -11,
    UsageFault_IRQn = -10,
    SecureFault_IRQn = -9,
    SVCall_IRQn = -5,
    DebugMonitor_IRQn = -4,
    PendSV_IRQn = -2,
    SysTick_IRQn = -1,
    ADC0_SCAN_END_IRQn = 0, /* ADC0 SCAN END (A/D scan end interrupt) */
    SCI0_RXI_IRQn = 1, /* SCI0 RXI (Receive data full) */
    SCI0_TXI_IRQn = 2, /* SCI0 TXI (Transmit data empty) */
    SCI0_TEI_IRQn = 3, /* SCI0 TEI (Transmit end) */
    SCI0_ERI_IRQn = 4, /* SCI0 ERI (Receive error) */
    CTSU_WRITE_IRQn = 5, /* CTSU WRITE (Write request interrupt) */
    CTSU_READ_IRQn = 6, /* CTSU READ (Measurement data transfer request interrupt) */
    CTSU_END_IRQn = 7, /* CTSU END (Measurement end interrupt) */
    ICU_IRQ6_IRQn = 8, /* ICU IRQ6 (External pin interrupt 6) */
    ICU_IRQ5_IRQn = 9, /* ICU IRQ5 (External pin interrupt 5) */
    ICU_IRQ9_IRQn = 10, /* ICU IRQ9 (External pin interrupt 9) */
    SPI0_RXI_IRQn = 11, /* SPI0 RXI (Receive buffer full) */
    SPI0_TXI_IRQn = 12, /* SPI0 TXI (Transmit buffer empty) */
    SPI0_TEI_IRQn = 13, /* SPI0 TEI (Transmission complete event) */
    SPI0_ERI_IRQn = 14, /* SPI0 ERI (Error) */
    FCU_FRDYI_IRQn = 15, /* FCU FRDYI (Flash ready interrupt) */
    RTC_PERIOD_IRQn = 16, /* RTC PERIOD (Periodic interrupt) */
    RTC_CARRY_IRQn = 17, /* RTC CARRY (Carry interrupt) */
    SCI1_RXI_IRQn = 18, /* SCI1 RXI (Received data full) */
    SCI1_TXI_IRQn = 19, /* SCI1 TXI (Transmit data empty) */
    SCI1_TEI_IRQn = 20, /* SCI1 TEI (Transmit end) */
    SCI1_ERI_IRQn = 21, /* SCI1 ERI (Receive error) */
    SCI9_RXI_IRQn = 22, /* SCI9 RXI (Received data full) */
    SCI9_TXI_IRQn = 23, /* SCI9 TXI (Transmit data empty) */
    SCI9_TEI_IRQn = 24, /* SCI9 TEI (Transmit end) */
    SCI9_ERI_IRQn = 25, /* SCI9 ERI (Receive error) */
    AGT0_INT_IRQn = 26, /* AGT0 INT (AGT interrupt) */
    AGT1_INT_IRQn = 27, /* AGT1 INT (AGT interrupt) */
} IRQn_Type;
#endif /* VECTOR_DATA_H */
