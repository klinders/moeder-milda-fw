#include <mbed.h>

int main() {

  // put your setup code here, to run once:
  DigitalOut myLed(LED2);
  while(1) {
    // put your main code here, to run repeatedly:
    myLed.write(1);
    thread_sleep_for(100);
    myLed.write(0);
    thread_sleep_for(1000);
  }
}