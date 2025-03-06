MEMORY
{
    FLASH (rx)      : ORIGIN = 0x000000,    LENGTH = 32K
    RAM (rwx)       : ORIGIN = 0x800100,    LENGTH = 2K     
}

ENTRY(Reset_Handler);

__ram_end = ORIGIN(RAM) + LENGTH(RAM);

SECTIONS
{
    .isr_vector :
    {
        . = ALIGN(2);

        KEEP(*.isr_vector);

        . = ALIGN(2);
    } > FLASH

    .text :
    {
        . = ALIGN(2);
        __text_start = .;

        *(.text)

        . = ALIGN(2);
        __text_end = .;
    } > FLASH

    .data : 
    {
        . = ALIGN(2);
        __data_start = .;

        *(.data)

        . = ALIGN(2);
        __data_end = .;
    } > RAM AT> FLASH

    .bss (NOLOAD) :
    {
        . = ALIGN(2);
        __bss_start = .;

        *(.bss)

        *(COMMON)

        . = ALIGN(2);
        __bss_end = .;
    } > RAM

    .rodata :       /*where readonly data is stored*/
    {
        . = ALIGN(2);
        __rodata_start = .;

        *(.rodata)

        . = ALIGN(2);
        __rodata_end = .;
    } >FLASH
}
