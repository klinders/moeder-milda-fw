/*
 * MIT License
 *
 * Copyright (c) 2020 klinders
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */
#include "Led.h"
#include <mbed.h>


LowPowerTicker led_ticker;
uint32_t led_counter = 0;

Led red_led(LED1);
Led orange_led(LED2);
Led blue_led(LED3);
Led usb_led(LED_USB);
// Array of all LED objects
Led *all_leds[] = {
    &red_led,
    &orange_led,
    &blue_led,
    &usb_led
};

static void led_handler(void);

void Led::on(void){
    Led::blink_state = Led::BLINK_NONE;
    Led::_high();
}

void Led::off(void){
    Led::blink_state = Led::BLINK_NONE;
    Led::_low();
}

void Led::_toggle(void){
    if(Led::_read()){
        Led::_low();
    }else{
        Led::_high();
    }
}

void Led::toggle(void){
    Led::blink_state = Led::BLINK_NONE;
    Led::_toggle();
}

void Led::_low(void){
    Led::output.write(0);
    Led::last_toggle = led_counter;
}

void Led::_high(void){
    Led::output.write(1);
    Led::last_toggle = led_counter;
}

bool Led::_read(){
    return Led::output.read();
}

void Led::blink(void){
    Led::blink_state = Led::BLINK_NORMAL;
}

void Led::blink_fast(void){
    Led::blink_state = Led::BLINK_FAST;
}

void Led::strike(void){
    Led::blink_state = Led::BLINK_STRIKE;
}

void Led::update(void){
    switch (Led::blink_state)
    {
    case Led::BLINK_NORMAL:
        if(led_counter - Led::last_toggle > 100){
            Led::_toggle();
        }
        break;
    case Led::BLINK_FAST:
        if(led_counter - Led::last_toggle > 20){
            Led::_toggle();
        }
        break;
    case Led::BLINK_STRIKE:
        if(Led::_read()){
            if(led_counter - last_toggle > 1){
                Led::_low();
            }
        }else{
            if(led_counter - last_toggle > 500){
                Led::_high();
            }
        }
    default:
        break;
    }
}

Led::Led(PinName pin):output(DigitalOut(pin))
{

}

void led_handler(void){
    for(int i = 0; i < LED_COUNT;i++){
        all_leds[i]->update();
    }
    led_counter++;
}

void led_init(void){
    // Attach interupt every 100ms
    led_ticker.attach_us(&led_handler, 10000);
}