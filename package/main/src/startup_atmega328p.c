#include <stdint.h>

#define SPH (*(uint8_t *) 0x3E)
#define SPL (*(uint8_t *) 0x3D)

void Reset_Handler(void);

uint16_t isr_vector[] __attribute__((section(".isr_vector"))) = {   //interupt vector table
    (uint16_t) &Reset_Handler,
};

extern void main(void);
extern uint16_t __text_end, __data_start, __data_end, __bss_start, __bss_end, __ram_end;

void Reset_Handler(void){
    // setting stack pointer
    SPH = (__ram_end >> 8);
    SPL = (__ram_end & 0x00FF);

    //copy data section into SRAM
    uint16_t data_size = ((uint16_t)&__data_end - (uint16_t)&__data_start);     //size of data section divided by 2 because flash is word addressed
    uint16_t *flash_data = (uint16_t *)&__text_end;    //uint16 because flash is 16k * 16bit
    uint8_t *sram_data = (uint8_t *)&__data_start;       //uint8 because ram is 2k * 8bit

    for (uint16_t i = 0, j = 0; i < (data_size/2); i++, j+=2){
        uint8_t flash_low = (flash_data[i] & (0x00FF));
        uint8_t flash_high = ((flash_data[i] & (0xFF00))>>8);

        sram_data[j] = flash_low;
        sram_data[j+1] = flash_high;
    }

    //clear .bss
    uint16_t bss_size = ((uint16_t)&__bss_end - (uint16_t)&__bss_start);
    uint8_t * bss = (uint8_t *)&__bss_start;

    for (uint16_t i = 0; i < bss_size; i++){
        bss[i] = 0;
    }

    //call main
    main();

    while(1);
}