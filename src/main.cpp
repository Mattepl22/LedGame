#include "gameFunction.h"

//Pin Led
#define RLED_PIN 8
#define YLED_PIN 9
#define GLED_PIN 10
#define BLED_PIN 11

//Pin Button
#define RBUTTON_PIN 4
#define YBUTTON_PIN 5
#define GBUTTON_PIN 6
#define BBUTTON_PIN 7

int level = 0;
bool answer = false, next = false;

byte array[10];

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
  next = true;

  //Inizializzo monitor seriale
  Serial.begin(115200);
}

void loop() {
  
  if (next && level <= 10) {
    if (!answer) {
      ledSequence(array, level);
      answer = true;
    } else {
      next = answerButton(array, level);
      level += 1;
      answer = false;
    }
  } else if (!next) {
    errorSequenceBlink();
    delay(1000);
    level = 1;
    next = true;
    answer = false;
  } else if (level > 10) {
    level = 1;
    answer = false;
  }
    
}
