#ifndef GAMEFUNCTION_H
#define GAMEFUNCTION_H

#include <Arduino.h>

//Costruisco le due strutture
struct ledPin{
    byte pin1;
    byte pin2;
    byte pin3;
    byte pin4;
};

struct buttonPin{
    byte pin1;
    byte pin2;
    byte pin3;
    byte pin4;
};

//Faccio in modo che possa accedere alle strutture nel main
extern struct ledPin led;
extern struct buttonPin button;

void initLed();
void initButton();

void ledSequence(byte *array, int level);
bool answerButton(const byte *answerArray, int level);

void WLBlink(int type, int duration);
void ledSequence_ONE(int duration);
void ledSequence_TWO(int duration);
void ledSequence_THREE(int duration);

#endif