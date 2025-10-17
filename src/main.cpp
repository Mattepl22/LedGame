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

int level = 0;
bool blink = false, answer = false, next = false;

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
  next = true;

  //Inizializzo monitor seriale
  Serial.begin(115200);
}

void loop() {
  if (next){
    if (!blink && !answer) {
      ledSequence(array, oldArray, level);
      blink = true;
      answer = false;
    } else if (blink && !answer) {
      blinkSequence(array, level);
      blink = false;
      answer = true;
    } else if (!blink && answer) {
      next = answerButton(array, level);
      level += 1;
      blink = false;
      answer = false;
    }
  } else {
    //Accendo e spengo tutti i led per tre volte.
    //Alla terza volta spengo i led per 2 secondi e poi riparto dal livello 1
    errorSequenceBlink();
    delay(1000);
    level = 1;
    next = true;
  }
  
}
