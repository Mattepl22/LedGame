#include "gameFunction.h"

//Pin Led
#define RLED_PIN 2
#define YLED_PIN 3
#define GLED_PIN 4
#define BLED_PIN 5

//Pin Button
#define RBUTTON_PIN 8
#define YBUTTON_PIN 9
#define GBUTTON_PIN 10
#define BBUTTON_PIN 11

int level;
bool blink, answer;

byte array[10];
byte oldArray[10];

void setup() {
  //Assegno i pin led alla struttura
  led.pin1 = RLED_PIN;
  led.pin2 = YLED_PIN;
  led.pin3 = GLED_PIN;
  led.pin4 = BLED_PIN;

  //Assegno i pin button alla struttura
  button.pin1 = RBUTTON_PIN;
  button.pin2 = YBUTTON_PIN;
  button.pin3 = GBUTTON_PIN;
  button.pin4 = BBUTTON_PIN;

  //Inizializzazione dei pin
  initLed();
  initButton();

  randomSeed(millis());

  level = 1;
  answer = false;
  blink = false;

  //Inizializzo monitor seriale
  Serial.begin(115200);
}

void loop() {
  if (!blink && !answer) {
    ledSequence(array, oldArray, level);
    blink = true;
    answer = false;
  } else if (blink && !answer) {
    blinkSequence(array, level);
    blink = false;
    answer = true;
  }
}
