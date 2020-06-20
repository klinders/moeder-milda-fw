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
#ifndef LED_H
#define LED_H
#include <mbed.h>

class Led
{
private:
    DigitalOut output;
    enum bl{
        BLINK_NONE,
        BLINK_NORMAL,
        BLINK_FAST,
        BLINK_STRIKE
    } blink_state;
    uint32_t last_toggle;
    void _high(void);
    void _low(void);
    bool _read(void);
    void _toggle(void);
public:
    Led(PinName pin);
    void on(void);
    void off(void);
    void toggle(void);
    void blink(void);
    void blink_fast(void);
    void strike(void);
    void update(void);
};

void led_init(void);

// Amount of LED pins connected
#define LED_COUNT 4

// Define the LED objects
extern Led red_led;
extern Led orange_led;
extern Led blue_led;
extern Led usb_led;

#endif