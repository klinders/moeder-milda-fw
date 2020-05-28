#include <mbed.h>
#include <RH_RF95.h>
#include <mildabus.h>

#include "gpio.h"
#include "lora.h"

void mama_initialize(void);

int main() {

  mama_initialize();

  while(1) {
    // put your main code here, to run repeatedly:
    thread_sleep_for(1000);
  }
}

void mama_initialize(){
  gpio_init();
  mildabus_prepare();
  lora_init();
}