#include <stdint.h>
#include <gpio.h>

void main(void){
    
    // DDRB |= (1<<5);
    GPIO_PORTB->DDR |= (1<<5);


    while(1){
        // PINB |= (1<<5);
        GPIO_PORTB->PIN |= (1<<5);
        for (volatile uint32_t i = 0; i < 100000; i++);
    }

}