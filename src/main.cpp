#include "gameFunction.h"

#define RED_PIN 2
#define YELLOW_PIN 3
#define GREEN_PIN 4
#define BLUE_PIN 5

void setup() {
  //Assegno i pin led alla struttura
  led.pin1 = RED_PIN;
  led.pin2 = YELLOW_PIN;
  led.pin3 = GREEN_PIN;
  led.pin4 = BLUE_PIN;

  initLed();
}

void loop() {
  
}
