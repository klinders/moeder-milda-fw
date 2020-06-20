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
#include <mbed.h>
#include <RH_RF95.h>
#include <Mildabus.h>

#include "gpio.h"
#include "lora.h"

Mildabus bus1(CAN1_RX, CAN1_TX, true, 0, true);
MB_Subscription* s;

void initialize(void);
void event(MB_Message&);

int main() {

	initialize();
	int count = 0;
	while(1) {
		// put your main code here, to run repeatedly:
		if(button.read()){
			bus1.send(MB_Event::LIGHTS_ON);
			wait_ms(200);
			count++;
			if(count == 10){
				bus1.unsubscribe(s);
			}
		}
	}
}

void initialize(){
	gpioInit();
	blue_led.blink_fast();
	bus1.getConnected();
	s = bus1.subscribe(callback(&event), MB_Message::ALL);

	//blue_led.off();
	//lora_init();
}

void event(MB_Message& m){
	red_led.toggle();
}