#include "gpio.h"
#include <mbed.h>

void gpio_toggle(DigitalOut pin){
    pin.write(!pin.read());
}

void gpio_init(void){
    
}