#include "gameFunction.h"

//Pin Led
#define RLED_PIN 4
#define YLED_PIN 6
#define GLED_PIN 8
#define BLED_PIN 10

//Pin Button
#define RBUTTON_PIN 5
#define YBUTTON_PIN 7
#define GBUTTON_PIN 9
#define BBUTTON_PIN 11

int level = 0;
bool answer = false, next = false, startup = false;

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

  randomSeed(millis() + analogRead(A0));

  level = 1;
  answer = false;
  next = true;

  startup = true;

  //Inizializzo monitor seriale
  Serial.begin(115200);
}

void loop() {

  if (startup) {
    WLBlink(1, 500);
    next = true;
    level = 1;
    answer = false;
  }


  if (next && level <= 10 && !answer) {
    ledSequence(array, level);
    answer = true;
    for (int index = 0; index < level; index++){
      Serial.print(array[index]);
      Serial.print(" ");
    }
    Serial.println();
  } else if (next && level <= 10 && answer) {
    next = answerButton(array, level);
    level += 1;
    answer = false;
    delay(1000);
  } else if (!next && !startup) {
    WLBlink(3, 1000);
    delay(1000);
    level = 1;
    next = true;
    answer = false;
    startup = true;
    delay(1000);
  } else if (level > 10) {
    WLBlink(2, 500);
    level = 1;
    answer = false;
    startup = true;
    delay(1000);
  }

}
