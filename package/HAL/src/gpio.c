#include <stdint.h>
#include <gpio.h>
//==============================  defines  ==============================



//============================== variables ==============================



//============================== Functions ==============================
//public

/**
 * @brief This Function sets the mode for a pin.
 *
 * The mode of a pin is set by writing a bit to the DDRx register.
 * 
 * @param pin pointer to struct of pin you want to set mode for.
 * @param mode mode which to set pin. 1 = output, 0 = input
 *
 * @return None
 */
void setMode(GPIO_Pin *pin, uint8_t mode){
    if(mode != 0)mode = 1;

    pin->port->DDR |= (mode << pin->number);
}

/**
 * @brief This function sets the internal Pull Up / Down for an input pin.
 * 
 * The Pull UP / Down ressitor is set by writing a bit to the PORTx register.
 * 
 * @param pin pointer to struct of pin you want to set mode for.
 * @param pull integer value of what pull pin should have. 1 = Pull Up, 0 = Pull Down
 * 
 * @return None
 */
void setPull(GPIO_Pin *pin, uint8_t pull){
    if (pull != 0)pull = 1;
    if ((pin->port->DDR & (1<<pin->number)) == 0){
        pin->port->PORT |= 
    }

}

/**
 * @brief This Function sets the state of an output pin
 * 
 * @param pin pointer to struct of pin you want to set a state for.
 * @param value integer value of what the pin should be set to.
 * 
 * @return None
 */
void setPin(GPIO_Pin *pin, uint8_t value){

}

/**
 * @brief This function toggles and output pin
 * 
 * @param pin pointer to struct of pin you want to toggle for.
 * 
 * @return None
 */
void togglePin(GPIO_Pin *pin){

}

/**
 * @brief This function reads the value of a pin.
 * 
 * @param pin pointer to struct of pin you want to read state from.
 * 
 * @return None
 */
uint8_t readPin(GPIO_Pin *pin){

}
//private

/**
 * @brief Initializes all gpio registers.
 *
 * This function is called at the start of the programm to set all GPIO pins to a fixed state.
 * All GPIO pins are set to output mode and set to LOW
 * 
 * @param None
 * @return None
 *
*/
static void GPIO_init(){
    GPIO_PORTB->DDR = 0xFF;
    GPIO_PORTC->DDR = 0xFF;
    GPIO_PORTD->DDR = 0xFF;

    GPIO_PORTB->PORT = 0x00;
    GPIO_PORTC->PORT = 0x00;
    GPIO_PORTD->PORT = 0x00;
}

