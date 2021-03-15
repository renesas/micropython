/* generated vector source file - do not edit */
#include "bsp_api.h"
/* Do not build these data structures if no interrupts are currently allocated because IAR will have build errors. */
#if VECTOR_DATA_IRQ_COUNT > 0
        BSP_DONT_REMOVE const fsp_vector_t g_vector_table[BSP_ICU_VECTOR_MAX_ENTRIES] BSP_PLACE_IN_SECTION(BSP_SECTION_APPLICATION_VECTORS) =
        {
                        [0] = adc_scan_end_isr, /* ADC0 SCAN END (A/D scan end interrupt) */
            [1] = sci_uart_rxi_isr, /* SCI0 RXI (Receive data full) */
            [2] = sci_uart_txi_isr, /* SCI0 TXI (Transmit data empty) */
            [3] = sci_uart_tei_isr, /* SCI0 TEI (Transmit end) */
            [4] = sci_uart_eri_isr, /* SCI0 ERI (Receive error) */
            [5] = ctsu_write_isr, /* CTSU WRITE (Write request interrupt) */
            [6] = ctsu_read_isr, /* CTSU READ (Measurement data transfer request interrupt) */
            [7] = ctsu_end_isr, /* CTSU END (Measurement end interrupt) */
            [8] = r_icu_isr, /* ICU IRQ6 (External pin interrupt 6) */
            [9] = r_icu_isr, /* ICU IRQ5 (External pin interrupt 5) */
            [10] = r_icu_isr, /* ICU IRQ9 (External pin interrupt 9) */
            [11] = spi_rxi_isr, /* SPI0 RXI (Receive buffer full) */
            [12] = spi_txi_isr, /* SPI0 TXI (Transmit buffer empty) */
            [13] = spi_tei_isr, /* SPI0 TEI (Transmission complete event) */
            [14] = spi_eri_isr, /* SPI0 ERI (Error) */
            [15] = fcu_frdyi_isr, /* FCU FRDYI (Flash ready interrupt) */
            [16] = rtc_alarm_periodic_isr, /* RTC PERIOD (Periodic interrupt) */
            [17] = rtc_carry_isr, /* RTC CARRY (Carry interrupt) */
            [18] = sci_uart_rxi_isr, /* SCI1 RXI (Received data full) */
            [19] = sci_uart_txi_isr, /* SCI1 TXI (Transmit data empty) */
            [20] = sci_uart_tei_isr, /* SCI1 TEI (Transmit end) */
            [21] = sci_uart_eri_isr, /* SCI1 ERI (Receive error) */
            [22] = sci_uart_rxi_isr, /* SCI9 RXI (Received data full) */
            [23] = sci_uart_txi_isr, /* SCI9 TXI (Transmit data empty) */
            [24] = sci_uart_tei_isr, /* SCI9 TEI (Transmit end) */
            [25] = sci_uart_eri_isr, /* SCI9 ERI (Receive error) */
            [26] = agt_int_isr, /* AGT0 INT (AGT interrupt) */
            [27] = agt_int_isr, /* AGT1 INT (AGT interrupt) */
        };
        const bsp_interrupt_event_t g_interrupt_event_link_select[BSP_ICU_VECTOR_MAX_ENTRIES] =
        {
            [0] = BSP_PRV_IELS_ENUM(EVENT_ADC0_SCAN_END), /* ADC0 SCAN END (A/D scan end interrupt) */
            [1] = BSP_PRV_IELS_ENUM(EVENT_SCI0_RXI), /* SCI0 RXI (Receive data full) */
            [2] = BSP_PRV_IELS_ENUM(EVENT_SCI0_TXI), /* SCI0 TXI (Transmit data empty) */
            [3] = BSP_PRV_IELS_ENUM(EVENT_SCI0_TEI), /* SCI0 TEI (Transmit end) */
            [4] = BSP_PRV_IELS_ENUM(EVENT_SCI0_ERI), /* SCI0 ERI (Receive error) */
            [5] = BSP_PRV_IELS_ENUM(EVENT_CTSU_WRITE), /* CTSU WRITE (Write request interrupt) */
            [6] = BSP_PRV_IELS_ENUM(EVENT_CTSU_READ), /* CTSU READ (Measurement data transfer request interrupt) */
            [7] = BSP_PRV_IELS_ENUM(EVENT_CTSU_END), /* CTSU END (Measurement end interrupt) */
            [8] = BSP_PRV_IELS_ENUM(EVENT_ICU_IRQ6), /* ICU IRQ6 (External pin interrupt 6) */
            [9] = BSP_PRV_IELS_ENUM(EVENT_ICU_IRQ5), /* ICU IRQ5 (External pin interrupt 5) */
            [10] = BSP_PRV_IELS_ENUM(EVENT_ICU_IRQ9), /* ICU IRQ9 (External pin interrupt 9) */
            [11] = BSP_PRV_IELS_ENUM(EVENT_SPI0_RXI), /* SPI0 RXI (Receive buffer full) */
            [12] = BSP_PRV_IELS_ENUM(EVENT_SPI0_TXI), /* SPI0 TXI (Transmit buffer empty) */
            [13] = BSP_PRV_IELS_ENUM(EVENT_SPI0_TEI), /* SPI0 TEI (Transmission complete event) */
            [14] = BSP_PRV_IELS_ENUM(EVENT_SPI0_ERI), /* SPI0 ERI (Error) */
            [15] = BSP_PRV_IELS_ENUM(EVENT_FCU_FRDYI), /* FCU FRDYI (Flash ready interrupt) */
            [16] = BSP_PRV_IELS_ENUM(EVENT_RTC_PERIOD), /* RTC PERIOD (Periodic interrupt) */
            [17] = BSP_PRV_IELS_ENUM(EVENT_RTC_CARRY), /* RTC CARRY (Carry interrupt) */
            [18] = BSP_PRV_IELS_ENUM(EVENT_SCI1_RXI), /* SCI1 RXI (Received data full) */
            [19] = BSP_PRV_IELS_ENUM(EVENT_SCI1_TXI), /* SCI1 TXI (Transmit data empty) */
            [20] = BSP_PRV_IELS_ENUM(EVENT_SCI1_TEI), /* SCI1 TEI (Transmit end) */
            [21] = BSP_PRV_IELS_ENUM(EVENT_SCI1_ERI), /* SCI1 ERI (Receive error) */
            [22] = BSP_PRV_IELS_ENUM(EVENT_SCI9_RXI), /* SCI9 RXI (Received data full) */
            [23] = BSP_PRV_IELS_ENUM(EVENT_SCI9_TXI), /* SCI9 TXI (Transmit data empty) */
            [24] = BSP_PRV_IELS_ENUM(EVENT_SCI9_TEI), /* SCI9 TEI (Transmit end) */
            [25] = BSP_PRV_IELS_ENUM(EVENT_SCI9_ERI), /* SCI9 ERI (Receive error) */
            [26] = BSP_PRV_IELS_ENUM(EVENT_AGT0_INT), /* AGT0 INT (AGT interrupt) */
            [27] = BSP_PRV_IELS_ENUM(EVENT_AGT1_INT), /* AGT1 INT (AGT interrupt) */
        };
        #endif
