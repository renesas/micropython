/* generated vector source file - do not edit */
#include "bsp_api.h"
/* Do not build these data structures if no interrupts are currently allocated because IAR will have build errors. */
#if VECTOR_DATA_IRQ_COUNT > 0
        BSP_DONT_REMOVE const fsp_vector_t g_vector_table[BSP_ICU_VECTOR_MAX_ENTRIES] BSP_PLACE_IN_SECTION(BSP_SECTION_APPLICATION_VECTORS) =
        {
                        [0] = sci_uart_rxi_isr, /* SCI0 RXI (Receive data full) */
            [1] = sci_uart_txi_isr, /* SCI0 TXI (Transmit data empty) */
            [2] = sci_uart_tei_isr, /* SCI0 TEI (Transmit end) */
            [3] = sci_uart_eri_isr, /* SCI0 ERI (Receive error) */
            [4] = sci_uart_rxi_isr, /* SCI1 RXI (Received data full) */
            [5] = sci_uart_txi_isr, /* SCI1 TXI (Transmit data empty) */
            [6] = sci_uart_tei_isr, /* SCI1 TEI (Transmit end) */
            [7] = sci_uart_eri_isr, /* SCI1 ERI (Receive error) */
            [8] = sci_uart_rxi_isr, /* SCI4 RXI (Received data full) */
            [9] = sci_uart_txi_isr, /* SCI4 TXI (Transmit data empty) */
            [10] = sci_uart_tei_isr, /* SCI4 TEI (Transmit end) */
            [11] = sci_uart_eri_isr, /* SCI4 ERI (Receive error) */
            [12] = sci_uart_rxi_isr, /* SCI9 RXI (Received data full) */
            [13] = sci_uart_txi_isr, /* SCI9 TXI (Transmit data empty) */
            [14] = sci_uart_tei_isr, /* SCI9 TEI (Transmit end) */
            [15] = sci_uart_eri_isr, /* SCI9 ERI (Receive error) */
            [16] = rtc_alarm_periodic_isr, /* RTC PERIOD (Periodic interrupt) */
            [17] = rtc_carry_isr, /* RTC CARRY (Carry interrupt) */
            [18] = agt_int_isr, /* AGT0 INT (AGT interrupt) */
            [19] = agt_int_isr, /* AGT1 INT (AGT interrupt) */
            [20] = r_icu_isr, /* ICU IRQ0 (External pin interrupt 0) */
            [21] = r_icu_isr, /* ICU IRQ1 (External pin interrupt 1) */
            [22] = r_icu_isr, /* ICU IRQ2 (External pin interrupt 2) */
            [23] = r_icu_isr, /* ICU IRQ3 (External pin interrupt 3) */
            [24] = r_icu_isr, /* ICU IRQ4 (External pin interrupt 4) */
            [25] = spi_rxi_isr, /* SPI0 RXI (Receive buffer full) */
            [26] = spi_txi_isr, /* SPI0 TXI (Transmit buffer empty) */
            [27] = spi_tei_isr, /* SPI0 TEI (Transmission complete event) */
            [28] = spi_eri_isr, /* SPI0 ERI (Error) */
        };
        const bsp_interrupt_event_t g_interrupt_event_link_select[BSP_ICU_VECTOR_MAX_ENTRIES] =
        {
            [0] = BSP_PRV_IELS_ENUM(EVENT_SCI0_RXI), /* SCI0 RXI (Receive data full) */
            [1] = BSP_PRV_IELS_ENUM(EVENT_SCI0_TXI), /* SCI0 TXI (Transmit data empty) */
            [2] = BSP_PRV_IELS_ENUM(EVENT_SCI0_TEI), /* SCI0 TEI (Transmit end) */
            [3] = BSP_PRV_IELS_ENUM(EVENT_SCI0_ERI), /* SCI0 ERI (Receive error) */
            [4] = BSP_PRV_IELS_ENUM(EVENT_SCI1_RXI), /* SCI1 RXI (Received data full) */
            [5] = BSP_PRV_IELS_ENUM(EVENT_SCI1_TXI), /* SCI1 TXI (Transmit data empty) */
            [6] = BSP_PRV_IELS_ENUM(EVENT_SCI1_TEI), /* SCI1 TEI (Transmit end) */
            [7] = BSP_PRV_IELS_ENUM(EVENT_SCI1_ERI), /* SCI1 ERI (Receive error) */
            [8] = BSP_PRV_IELS_ENUM(EVENT_SCI4_RXI), /* SCI4 RXI (Received data full) */
            [9] = BSP_PRV_IELS_ENUM(EVENT_SCI4_TXI), /* SCI4 TXI (Transmit data empty) */
            [10] = BSP_PRV_IELS_ENUM(EVENT_SCI4_TEI), /* SCI4 TEI (Transmit end) */
            [11] = BSP_PRV_IELS_ENUM(EVENT_SCI4_ERI), /* SCI4 ERI (Receive error) */
            [12] = BSP_PRV_IELS_ENUM(EVENT_SCI9_RXI), /* SCI9 RXI (Received data full) */
            [13] = BSP_PRV_IELS_ENUM(EVENT_SCI9_TXI), /* SCI9 TXI (Transmit data empty) */
            [14] = BSP_PRV_IELS_ENUM(EVENT_SCI9_TEI), /* SCI9 TEI (Transmit end) */
            [15] = BSP_PRV_IELS_ENUM(EVENT_SCI9_ERI), /* SCI9 ERI (Receive error) */
            [16] = BSP_PRV_IELS_ENUM(EVENT_RTC_PERIOD), /* RTC PERIOD (Periodic interrupt) */
            [17] = BSP_PRV_IELS_ENUM(EVENT_RTC_CARRY), /* RTC CARRY (Carry interrupt) */
            [18] = BSP_PRV_IELS_ENUM(EVENT_AGT0_INT), /* AGT0 INT (AGT interrupt) */
            [19] = BSP_PRV_IELS_ENUM(EVENT_AGT1_INT), /* AGT1 INT (AGT interrupt) */
            [20] = BSP_PRV_IELS_ENUM(EVENT_ICU_IRQ0), /* ICU IRQ0 (External pin interrupt 0) */
            [21] = BSP_PRV_IELS_ENUM(EVENT_ICU_IRQ1), /* ICU IRQ1 (External pin interrupt 1) */
            [22] = BSP_PRV_IELS_ENUM(EVENT_ICU_IRQ2), /* ICU IRQ2 (External pin interrupt 2) */
            [23] = BSP_PRV_IELS_ENUM(EVENT_ICU_IRQ3), /* ICU IRQ3 (External pin interrupt 3) */
            [24] = BSP_PRV_IELS_ENUM(EVENT_ICU_IRQ4), /* ICU IRQ4 (External pin interrupt 4) */
            [25] = BSP_PRV_IELS_ENUM(EVENT_SPI0_RXI), /* SPI0 RXI (Receive buffer full) */
            [26] = BSP_PRV_IELS_ENUM(EVENT_SPI0_TXI), /* SPI0 TXI (Transmit buffer empty) */
            [27] = BSP_PRV_IELS_ENUM(EVENT_SPI0_TEI), /* SPI0 TEI (Transmission complete event) */
            [28] = BSP_PRV_IELS_ENUM(EVENT_SPI0_ERI), /* SPI0 ERI (Error) */
        };
        #endif
