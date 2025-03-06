#include <stdint.h>

//==============================  defines  ==============================

#define PINB    (*(volatile uint8_t *) 0x23)
#define DDRB    (*(volatile uint8_t *) 0x24)
#define PORTB   (*(volatile uint8_t *) 0x25)

#define PINC    (*(volatile uint8_t *) 0x26)
#define DDRC    (*(volatile uint8_t *) 0x27)
#define PORTC   (*(volatile uint8_t *) 0x28)

#define PIND    (*(volatile uint8_t *) 0x29)
#define DDRD    (*(volatile uint8_t *) 0x2A)
#define PORTD   (*(volatile uint8_t *) 0x2B)

#define GPIO_PORTB ((volatile GPIO_Port *) 0x23)
#define GPIO_PORTC ((volatile GPIO_Port *) 0x26)
#define GPIO_PORTD ((volatile GPIO_Port *) 0x29)

#define INPUT 0
#define OUTPUT 1

#define PULL_UP 1
#define PULL_DOWN 0

#define HIGH 1
#define LOW 0

//============================== variables ==============================

/**
    @brief struct for interacting with a GPIO port

    @param PIN : PIN regiser, used to read the current state of pins. 
    Can be used to toggle pins by writing a 1 to the corresponding bit.

    @param DDR : Data Direction Register, used to set the mode of the pin.
    1 = Output mode. 0 = Input mode.

    @param PORT : PORT register, 
    INPUT : 0 = Pull Down, 1 = Pull Up
    OUTPUT : 1 = HIGH, 0 = LOW
*/
typedef struct
{
    uint8_t PIN; 
    uint8_t DDR;
    uint8_t PORT;
}GPIO_Port;


/**
    @brief Struct for interacting with single GPIO pins.

    @param mode  mode of the pin. OUTPUT = 1, INPUT = 0
    @param number  number of the pin. eg. PB5 number = 5
    @param port  GPIO port of the pin. eg PB5 port = GPIO_PORTB
*/
typedef struct
{
    uint8_t mode;   
    uint8_t number;
    uint8_t port;
}GPIO_Pin;


//============================== Functions ==============================

void setMode(GPIO_Pin *pin, uint8_t mode);
void setPull(GPIO_Pin *pin, uint8_t pull);

void setPin(GPIO_Pin *pin, uint8_t value);
void togglePin(GPIO_Pin *pin);

uint8_t readPin(GPIO_Pin *pin);
