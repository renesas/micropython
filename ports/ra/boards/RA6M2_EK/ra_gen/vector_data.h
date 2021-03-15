/* generated vector header file - do not edit */
#ifndef VECTOR_DATA_H
#define VECTOR_DATA_H
/* Number of interrupts allocated */
#ifndef VECTOR_DATA_IRQ_COUNT
#define VECTOR_DATA_IRQ_COUNT    (80)
#endif
/* ISR prototypes */
void spi_rxi_isr(void);
void spi_txi_isr(void);
void spi_tei_isr(void);
void spi_eri_isr(void);
void sci_uart_rxi_isr(void);
void sci_uart_txi_isr(void);
void sci_uart_tei_isr(void);
void sci_uart_eri_isr(void);
void rtc_alarm_periodic_isr(void);
void rtc_carry_isr(void);
void agt_int_isr(void);
void r_icu_isr(void);
void iic_master_rxi_isr(void);
void iic_master_txi_isr(void);
void iic_master_tei_isr(void);
void iic_master_eri_isr(void);

/* Vector table allocations */
#define VECTOR_NUMBER_SPI0_RXI ((IRQn_Type) 0) /* SPI0 RXI (Receive buffer full) */
#define VECTOR_NUMBER_SPI0_TXI ((IRQn_Type) 1) /* SPI0 TXI (Transmit buffer empty) */
#define VECTOR_NUMBER_SPI0_TEI ((IRQn_Type) 2) /* SPI0 TEI (Transmission complete event) */
#define VECTOR_NUMBER_SPI0_ERI ((IRQn_Type) 3) /* SPI0 ERI (Error) */
#define VECTOR_NUMBER_SPI1_RXI ((IRQn_Type) 4) /* SPI1 RXI (Receive buffer full) */
#define VECTOR_NUMBER_SPI1_TXI ((IRQn_Type) 5) /* SPI1 TXI (Transmit buffer empty) */
#define VECTOR_NUMBER_SPI1_TEI ((IRQn_Type) 6) /* SPI1 TEI (Transmission complete event) */
#define VECTOR_NUMBER_SPI1_ERI ((IRQn_Type) 7) /* SPI1 ERI (Error) */
#define VECTOR_NUMBER_SCI0_RXI ((IRQn_Type) 8) /* SCI0 RXI (Receive data full) */
#define VECTOR_NUMBER_SCI0_TXI ((IRQn_Type) 9) /* SCI0 TXI (Transmit data empty) */
#define VECTOR_NUMBER_SCI0_TEI ((IRQn_Type) 10) /* SCI0 TEI (Transmit end) */
#define VECTOR_NUMBER_SCI0_ERI ((IRQn_Type) 11) /* SCI0 ERI (Receive error) */
#define VECTOR_NUMBER_SCI1_RXI ((IRQn_Type) 12) /* SCI1 RXI (Received data full) */
#define VECTOR_NUMBER_SCI1_TXI ((IRQn_Type) 13) /* SCI1 TXI (Transmit data empty) */
#define VECTOR_NUMBER_SCI1_TEI ((IRQn_Type) 14) /* SCI1 TEI (Transmit end) */
#define VECTOR_NUMBER_SCI1_ERI ((IRQn_Type) 15) /* SCI1 ERI (Receive error) */
#define VECTOR_NUMBER_SCI2_RXI ((IRQn_Type) 16) /* SCI2 RXI (Received data full) */
#define VECTOR_NUMBER_SCI2_TXI ((IRQn_Type) 17) /* SCI2 TXI (Transmit data empty) */
#define VECTOR_NUMBER_SCI2_TEI ((IRQn_Type) 18) /* SCI2 TEI (Transmit end) */
#define VECTOR_NUMBER_SCI2_ERI ((IRQn_Type) 19) /* SCI2 ERI (Receive error) */
#define VECTOR_NUMBER_SCI3_RXI ((IRQn_Type) 20) /* SCI3 RXI (Received data full) */
#define VECTOR_NUMBER_SCI3_TXI ((IRQn_Type) 21) /* SCI3 TXI (Transmit data empty) */
#define VECTOR_NUMBER_SCI3_TEI ((IRQn_Type) 22) /* SCI3 TEI (Transmit end) */
#define VECTOR_NUMBER_SCI3_ERI ((IRQn_Type) 23) /* SCI3 ERI (Receive error) */
#define VECTOR_NUMBER_SCI4_RXI ((IRQn_Type) 24) /* SCI4 RXI (Received data full) */
#define VECTOR_NUMBER_SCI4_TXI ((IRQn_Type) 25) /* SCI4 TXI (Transmit data empty) */
#define VECTOR_NUMBER_SCI4_TEI ((IRQn_Type) 26) /* SCI4 TEI (Transmit end) */
#define VECTOR_NUMBER_SCI4_ERI ((IRQn_Type) 27) /* SCI4 ERI (Receive error) */
#define VECTOR_NUMBER_SCI5_RXI ((IRQn_Type) 28) /* SCI5 RXI (Received data full) */
#define VECTOR_NUMBER_SCI5_TXI ((IRQn_Type) 29) /* SCI5 TXI (Transmit data empty) */
#define VECTOR_NUMBER_SCI5_TEI ((IRQn_Type) 30) /* SCI5 TEI (Transmit end) */
#define VECTOR_NUMBER_SCI5_ERI ((IRQn_Type) 31) /* SCI5 ERI (Receive error) */
#define VECTOR_NUMBER_SCI6_RXI ((IRQn_Type) 32) /* SCI6 RXI (Received data full) */
#define VECTOR_NUMBER_SCI6_TXI ((IRQn_Type) 33) /* SCI6 TXI (Transmit data empty) */
#define VECTOR_NUMBER_SCI6_TEI ((IRQn_Type) 34) /* SCI6 TEI (Transmit end) */
#define VECTOR_NUMBER_SCI6_ERI ((IRQn_Type) 35) /* SCI6 ERI (Receive error) */
#define VECTOR_NUMBER_SCI7_RXI ((IRQn_Type) 36) /* SCI7 RXI (Received data full) */
#define VECTOR_NUMBER_SCI7_TXI ((IRQn_Type) 37) /* SCI7 TXI (Transmit data empty) */
#define VECTOR_NUMBER_SCI7_TEI ((IRQn_Type) 38) /* SCI7 TEI (Transmit end) */
#define VECTOR_NUMBER_SCI7_ERI ((IRQn_Type) 39) /* SCI7 ERI (Receive error) */
#define VECTOR_NUMBER_SCI8_RXI ((IRQn_Type) 40) /* SCI8 RXI (Received data full) */
#define VECTOR_NUMBER_SCI8_TXI ((IRQn_Type) 41) /* SCI8 TXI (Transmit data empty) */
#define VECTOR_NUMBER_SCI8_TEI ((IRQn_Type) 42) /* SCI8 TEI (Transmit end) */
#define VECTOR_NUMBER_SCI8_ERI ((IRQn_Type) 43) /* SCI8 ERI (Receive error) */
#define VECTOR_NUMBER_SCI9_RXI ((IRQn_Type) 44) /* SCI9 RXI (Received data full) */
#define VECTOR_NUMBER_SCI9_TXI ((IRQn_Type) 45) /* SCI9 TXI (Transmit data empty) */
#define VECTOR_NUMBER_SCI9_TEI ((IRQn_Type) 46) /* SCI9 TEI (Transmit end) */
#define VECTOR_NUMBER_SCI9_ERI ((IRQn_Type) 47) /* SCI9 ERI (Receive error) */
#define VECTOR_NUMBER_RTC_PERIOD ((IRQn_Type) 48) /* RTC PERIOD (Periodic interrupt) */
#define VECTOR_NUMBER_RTC_CARRY ((IRQn_Type) 49) /* RTC CARRY (Carry interrupt) */
#define VECTOR_NUMBER_AGT0_INT ((IRQn_Type) 50) /* AGT0 INT (AGT interrupt) */
#define VECTOR_NUMBER_AGT1_INT ((IRQn_Type) 51) /* AGT1 INT (AGT interrupt) */
#define VECTOR_NUMBER_ICU_IRQ0 ((IRQn_Type) 52) /* ICU IRQ0 (External pin interrupt 0) */
#define VECTOR_NUMBER_ICU_IRQ1 ((IRQn_Type) 53) /* ICU IRQ1 (External pin interrupt 1) */
#define VECTOR_NUMBER_ICU_IRQ2 ((IRQn_Type) 54) /* ICU IRQ2 (External pin interrupt 2) */
#define VECTOR_NUMBER_ICU_IRQ3 ((IRQn_Type) 55) /* ICU IRQ3 (External pin interrupt 3) */
#define VECTOR_NUMBER_ICU_IRQ4 ((IRQn_Type) 56) /* ICU IRQ4 (External pin interrupt 4) */
#define VECTOR_NUMBER_ICU_IRQ5 ((IRQn_Type) 57) /* ICU IRQ5 (External pin interrupt 5) */
#define VECTOR_NUMBER_ICU_IRQ6 ((IRQn_Type) 58) /* ICU IRQ6 (External pin interrupt 6) */
#define VECTOR_NUMBER_ICU_IRQ7 ((IRQn_Type) 59) /* ICU IRQ7 (External pin interrupt 7) */
#define VECTOR_NUMBER_ICU_IRQ8 ((IRQn_Type) 60) /* ICU IRQ8 (External pin interrupt 8) */
#define VECTOR_NUMBER_ICU_IRQ9 ((IRQn_Type) 61) /* ICU IRQ9 (External pin interrupt 9) */
#define VECTOR_NUMBER_ICU_IRQ10 ((IRQn_Type) 62) /* ICU IRQ10 (External pin interrupt 10) */
#define VECTOR_NUMBER_ICU_IRQ11 ((IRQn_Type) 63) /* ICU IRQ11 (External pin interrupt 11) */
#define VECTOR_NUMBER_ICU_IRQ12 ((IRQn_Type) 64) /* ICU IRQ12 (External pin interrupt 12) */
#define VECTOR_NUMBER_ICU_IRQ13 ((IRQn_Type) 65) /* ICU IRQ13 (External pin interrupt 13) */
#define VECTOR_NUMBER_ICU_IRQ14 ((IRQn_Type) 66) /* ICU IRQ14 (External pin interrupt 14) */
#define VECTOR_NUMBER_ICU_IRQ15 ((IRQn_Type) 67) /* ICU IRQ15 (External pin interrupt 15) */
#define VECTOR_NUMBER_IIC0_RXI ((IRQn_Type) 68) /* IIC0 RXI (Receive data full) */
#define VECTOR_NUMBER_IIC0_TXI ((IRQn_Type) 69) /* IIC0 TXI (Transmit data empty) */
#define VECTOR_NUMBER_IIC0_TEI ((IRQn_Type) 70) /* IIC0 TEI (Transmit end) */
#define VECTOR_NUMBER_IIC0_ERI ((IRQn_Type) 71) /* IIC0 ERI (Transfer error) */
#define VECTOR_NUMBER_IIC1_RXI ((IRQn_Type) 72) /* IIC1 RXI (Receive data full) */
#define VECTOR_NUMBER_IIC1_TXI ((IRQn_Type) 73) /* IIC1 TXI (Transmit data empty) */
#define VECTOR_NUMBER_IIC1_TEI ((IRQn_Type) 74) /* IIC1 TEI (Transmit end) */
#define VECTOR_NUMBER_IIC1_ERI ((IRQn_Type) 75) /* IIC1 ERI (Transfer error) */
#define VECTOR_NUMBER_IIC2_RXI ((IRQn_Type) 76) /* IIC2 RXI (Receive data full) */
#define VECTOR_NUMBER_IIC2_TXI ((IRQn_Type) 77) /* IIC2 TXI (Transmit data empty) */
#define VECTOR_NUMBER_IIC2_TEI ((IRQn_Type) 78) /* IIC2 TEI (Transmit end) */
#define VECTOR_NUMBER_IIC2_ERI ((IRQn_Type) 79) /* IIC2 ERI (Transfer error) */
typedef enum IRQn {
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
	SPI0_RXI_IRQn = 0, /* SPI0 RXI (Receive buffer full) */
	SPI0_TXI_IRQn = 1, /* SPI0 TXI (Transmit buffer empty) */
	SPI0_TEI_IRQn = 2, /* SPI0 TEI (Transmission complete event) */
	SPI0_ERI_IRQn = 3, /* SPI0 ERI (Error) */
	SPI1_RXI_IRQn = 4, /* SPI1 RXI (Receive buffer full) */
	SPI1_TXI_IRQn = 5, /* SPI1 TXI (Transmit buffer empty) */
	SPI1_TEI_IRQn = 6, /* SPI1 TEI (Transmission complete event) */
	SPI1_ERI_IRQn = 7, /* SPI1 ERI (Error) */
	SCI0_RXI_IRQn = 8, /* SCI0 RXI (Receive data full) */
	SCI0_TXI_IRQn = 9, /* SCI0 TXI (Transmit data empty) */
	SCI0_TEI_IRQn = 10, /* SCI0 TEI (Transmit end) */
	SCI0_ERI_IRQn = 11, /* SCI0 ERI (Receive error) */
	SCI1_RXI_IRQn = 12, /* SCI1 RXI (Received data full) */
	SCI1_TXI_IRQn = 13, /* SCI1 TXI (Transmit data empty) */
	SCI1_TEI_IRQn = 14, /* SCI1 TEI (Transmit end) */
	SCI1_ERI_IRQn = 15, /* SCI1 ERI (Receive error) */
	SCI2_RXI_IRQn = 16, /* SCI2 RXI (Received data full) */
	SCI2_TXI_IRQn = 17, /* SCI2 TXI (Transmit data empty) */
	SCI2_TEI_IRQn = 18, /* SCI2 TEI (Transmit end) */
	SCI2_ERI_IRQn = 19, /* SCI2 ERI (Receive error) */
	SCI3_RXI_IRQn = 20, /* SCI3 RXI (Received data full) */
	SCI3_TXI_IRQn = 21, /* SCI3 TXI (Transmit data empty) */
	SCI3_TEI_IRQn = 22, /* SCI3 TEI (Transmit end) */
	SCI3_ERI_IRQn = 23, /* SCI3 ERI (Receive error) */
	SCI4_RXI_IRQn = 24, /* SCI4 RXI (Received data full) */
	SCI4_TXI_IRQn = 25, /* SCI4 TXI (Transmit data empty) */
	SCI4_TEI_IRQn = 26, /* SCI4 TEI (Transmit end) */
	SCI4_ERI_IRQn = 27, /* SCI4 ERI (Receive error) */
	SCI5_RXI_IRQn = 28, /* SCI5 RXI (Received data full) */
	SCI5_TXI_IRQn = 29, /* SCI5 TXI (Transmit data empty) */
	SCI5_TEI_IRQn = 30, /* SCI5 TEI (Transmit end) */
	SCI5_ERI_IRQn = 31, /* SCI5 ERI (Receive error) */
	SCI6_RXI_IRQn = 32, /* SCI6 RXI (Received data full) */
	SCI6_TXI_IRQn = 33, /* SCI6 TXI (Transmit data empty) */
	SCI6_TEI_IRQn = 34, /* SCI6 TEI (Transmit end) */
	SCI6_ERI_IRQn = 35, /* SCI6 ERI (Receive error) */
	SCI7_RXI_IRQn = 36, /* SCI7 RXI (Received data full) */
	SCI7_TXI_IRQn = 37, /* SCI7 TXI (Transmit data empty) */
	SCI7_TEI_IRQn = 38, /* SCI7 TEI (Transmit end) */
	SCI7_ERI_IRQn = 39, /* SCI7 ERI (Receive error) */
	SCI8_RXI_IRQn = 40, /* SCI8 RXI (Received data full) */
	SCI8_TXI_IRQn = 41, /* SCI8 TXI (Transmit data empty) */
	SCI8_TEI_IRQn = 42, /* SCI8 TEI (Transmit end) */
	SCI8_ERI_IRQn = 43, /* SCI8 ERI (Receive error) */
	SCI9_RXI_IRQn = 44, /* SCI9 RXI (Received data full) */
	SCI9_TXI_IRQn = 45, /* SCI9 TXI (Transmit data empty) */
	SCI9_TEI_IRQn = 46, /* SCI9 TEI (Transmit end) */
	SCI9_ERI_IRQn = 47, /* SCI9 ERI (Receive error) */
	RTC_PERIOD_IRQn = 48, /* RTC PERIOD (Periodic interrupt) */
	RTC_CARRY_IRQn = 49, /* RTC CARRY (Carry interrupt) */
	AGT0_INT_IRQn = 50, /* AGT0 INT (AGT interrupt) */
	AGT1_INT_IRQn = 51, /* AGT1 INT (AGT interrupt) */
	ICU_IRQ0_IRQn = 52, /* ICU IRQ0 (External pin interrupt 0) */
	ICU_IRQ1_IRQn = 53, /* ICU IRQ1 (External pin interrupt 1) */
	ICU_IRQ2_IRQn = 54, /* ICU IRQ2 (External pin interrupt 2) */
	ICU_IRQ3_IRQn = 55, /* ICU IRQ3 (External pin interrupt 3) */
	ICU_IRQ4_IRQn = 56, /* ICU IRQ4 (External pin interrupt 4) */
	ICU_IRQ5_IRQn = 57, /* ICU IRQ5 (External pin interrupt 5) */
	ICU_IRQ6_IRQn = 58, /* ICU IRQ6 (External pin interrupt 6) */
	ICU_IRQ7_IRQn = 59, /* ICU IRQ7 (External pin interrupt 7) */
	ICU_IRQ8_IRQn = 60, /* ICU IRQ8 (External pin interrupt 8) */
	ICU_IRQ9_IRQn = 61, /* ICU IRQ9 (External pin interrupt 9) */
	ICU_IRQ10_IRQn = 62, /* ICU IRQ10 (External pin interrupt 10) */
	ICU_IRQ11_IRQn = 63, /* ICU IRQ11 (External pin interrupt 11) */
	ICU_IRQ12_IRQn = 64, /* ICU IRQ12 (External pin interrupt 12) */
	ICU_IRQ13_IRQn = 65, /* ICU IRQ13 (External pin interrupt 13) */
	ICU_IRQ14_IRQn = 66, /* ICU IRQ14 (External pin interrupt 14) */
	ICU_IRQ15_IRQn = 67, /* ICU IRQ15 (External pin interrupt 15) */
	IIC0_RXI_IRQn = 68, /* IIC0 RXI (Receive data full) */
	IIC0_TXI_IRQn = 69, /* IIC0 TXI (Transmit data empty) */
	IIC0_TEI_IRQn = 70, /* IIC0 TEI (Transmit end) */
	IIC0_ERI_IRQn = 71, /* IIC0 ERI (Transfer error) */
	IIC1_RXI_IRQn = 72, /* IIC1 RXI (Receive data full) */
	IIC1_TXI_IRQn = 73, /* IIC1 TXI (Transmit data empty) */
	IIC1_TEI_IRQn = 74, /* IIC1 TEI (Transmit end) */
	IIC1_ERI_IRQn = 75, /* IIC1 ERI (Transfer error) */
	IIC2_RXI_IRQn = 76, /* IIC2 RXI (Receive data full) */
	IIC2_TXI_IRQn = 77, /* IIC2 TXI (Transmit data empty) */
	IIC2_TEI_IRQn = 78, /* IIC2 TEI (Transmit end) */
	IIC2_ERI_IRQn = 79, /* IIC2 ERI (Transfer error) */
} IRQn_Type;
#endif /* VECTOR_DATA_H */
