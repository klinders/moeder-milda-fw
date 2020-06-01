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

CAN can1(CAN1_RX, CAN1_TX);
DigitalOut led_1(LED1);
DigitalOut led_2(LED2);
// Setup Mildabus in master mode
Mildabus bus1(&can1, true);

void mama_initialize(void);

int main() {

  mama_initialize();
  led_1.write(1);
  //led_2.write(1);
  while(1) {
    // put your main code here, to run repeatedly:
  }
}

void mama_initialize(){
  gpio_init();
  bus1.prepare();
  lora_init();
  
}