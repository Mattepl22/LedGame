#include "gameFunction.h"

//Do il nome alla struttura da usare nel main.cpp
struct ledPin led;
struct buttonPin button;

//Inizializzazione pin Led
void initLed() {
    pinMode(led.pin1, OUTPUT);
    pinMode(led.pin2, OUTPUT);
    pinMode(led.pin3, OUTPUT);
    pinMode(led.pin4, OUTPUT);

    digitalWrite(led.pin1, 0);
    digitalWrite(led.pin2, 0);
    digitalWrite(led.pin3, 0);
    digitalWrite(led.pin4, 0);
}

//Inizializzazione pin Button
void initButton() {
    pinMode(button.pin1, INPUT_PULLUP);
    pinMode(button.pin2, INPUT_PULLUP);
    pinMode(button.pin3, INPUT_PULLUP);
    pinMode(button.pin4, INPUT_PULLUP);
}