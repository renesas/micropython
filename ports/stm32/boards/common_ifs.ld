/* Memory layout for internal flash storage configuration:

    FLASH_ISR   .isr_vector

    FLASH_TEXT  .text
    FLASH_TEXT  .data

    RAM         .data
    RAM         .bss
    RAM         .heap
    RAM         .stack
*/

ENTRY(Reset_Handler)

REGION_ALIAS("FLASH_ISR", FLASH_START);
REGION_ALIAS("FLASH_COMMON", FLASH_TEXT);

/* define output sections */
SECTIONS
{
    INCLUDE common_isr.ld
    INCLUDE common_isr_extratext.ld
    INCLUDE common_text.ld
    INCLUDE common_extratext_data_in_flash.ld
    INCLUDE common_bss_heap_stack.ld
}
