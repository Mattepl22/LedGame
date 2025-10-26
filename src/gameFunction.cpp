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

//Sequenza led e blink
void ledSequence(byte *array, int level) {
    array[level - 1] = (byte)random(1, 5);

    for (int index = 0; index < level; index++) {
        switch (array[index]) {
           case 1:
                digitalWrite(led.pin1, 1);
                delay(500);
                digitalWrite(led.pin1, 0);
                break;
            case 2:
                digitalWrite(led.pin2, 1);
                delay(500);
                digitalWrite(led.pin2, 0);
                break;
            case 3:
                digitalWrite(led.pin3, 1);
                delay(500);
                digitalWrite(led.pin3, 0);
                break;
            case 4:
                digitalWrite(led.pin4, 1);
                delay(500);
                digitalWrite(led.pin4, 0);
                break;
            default:
                break; 
        }

        if (index < level - 1) {
            digitalWrite(led.pin1, 0);
            digitalWrite(led.pin2, 0);
            digitalWrite(led.pin3, 0);
            digitalWrite(led.pin4, 0);
            delay(500);
        }
        
    }

    digitalWrite(led.pin1, 0);
    digitalWrite(led.pin2, 0);
    digitalWrite(led.pin3, 0);
    digitalWrite(led.pin4, 0);
    
}

//Attendo pressione pulsanti e confronto con risposta
bool answerButton(const byte *answerArray, int level) {

    int index = 0;

    while (index < level) {
        // Pin1
        if (!digitalRead(button.pin1)) {
            digitalWrite(led.pin1, true);
            while(!digitalRead(button.pin1)) {

            }
            digitalWrite(led.pin1, false);
            delay(50);
            if (answerArray[index] == 1) {
                index += 1;
            } else {
                return false;
            }
        }

        // Pin2
        if (!digitalRead(button.pin2)) {
            digitalWrite(led.pin2, true);
            while(!digitalRead(button.pin2)) {

            }
            digitalWrite(led.pin2, false);
            delay(50);
            if (answerArray[index] == 2) {
                index += 1;
            } else {
                return false;
            }
        }

        // Pin3
        if (!digitalRead(button.pin3)) {
            digitalWrite(led.pin3, true);
            while(!digitalRead(button.pin3)) {

            }
            digitalWrite(led.pin3, false);
            delay(50);
            if (answerArray[index] == 3) {
                index += 1;
            } else {
                return false;
            }
        }

        // Pin4
        if (!digitalRead(button.pin4)) {
            digitalWrite(led.pin4, true);
            while(!digitalRead(button.pin4)) {

            }
            digitalWrite(led.pin4, false);
            delay(50);
            if (answerArray[index] == 4) {
                index += 1;
            } else {
                return false;
            }
        }


    }

    return true;
    
}

void ledSequnce_ONE(int duration) {
    //Accendo tutti i led
    digitalWrite(led.pin1, true);
    delay(duration);
    digitalWrite(led.pin2, true);
    delay(duration);
    digitalWrite(led.pin3, true);
    delay(duration);
    digitalWrite(led.pin4, true);
    delay(duration);

    //Spengo tutti i led
    digitalWrite(led.pin4, false);
    delay(duration);
    digitalWrite(led.pin3, false);
    delay(duration);
    digitalWrite(led.pin2, false);
    delay(duration);
    digitalWrite(led.pin1, false);
    delay(duration);
}

void ledSequence_TWO(int duration) {
    //Accendo te spengo tutti i led in sequenza
    digitalWrite(led.pin1, true);
    delay(duration);
    digitalWrite(led.pin1, false);
    delay(duration);

    digitalWrite(led.pin2, true);
    delay(duration);
    digitalWrite(led.pin2, false);
    delay(duration);

    digitalWrite(led.pin3, true);
    delay(duration);
    digitalWrite(led.pin3, false);
    delay(duration);

    digitalWrite(led.pin4, true);
    delay(duration);
    digitalWrite(led.pin4, false);
    delay(duration);
  
    //Accendo tutti i led insieme e li spengo per 2 volte
    for (int index = 0; index < 2; index++) {
        digitalWrite(led.pin1, 1);
        digitalWrite(led.pin2, 1);
        digitalWrite(led.pin3, 1);
        digitalWrite(led.pin4, 1);

        delay(duration);

        digitalWrite(led.pin1, 0);
        digitalWrite(led.pin2, 0);
        digitalWrite(led.pin3, 0);
        digitalWrite(led.pin4, 0);

        delay(duration);
    }
    
}

void ledSequence_THREE(int duration) {
    for (int index = 0; index < 3; index++) {
        digitalWrite(led.pin1, 1);
        digitalWrite(led.pin2, 1);
        digitalWrite(led.pin3, 1);
        digitalWrite(led.pin4, 1);

        delay(duration);

        digitalWrite(led.pin1, 0);
        digitalWrite(led.pin2, 0);
        digitalWrite(led.pin3, 0);
        digitalWrite(led.pin4, 0);

        delay(duration);
    }
}

void WLBlink(int type, int duration) {
    // Fa illuminare i led con una certa sequenza a seconda del tipo che gli indico
    /* 
    1 -> Start
    2 -> Vittoria
    3 -> Errore
    */

    switch (type)
    {
    case 1:
        ledSequence_ONE(duration);
        break;

    case 2:
        ledSequence_TWO(duration);
        break;

    case 3:
        ledSequence_THREE(duration);
        break;
    
    default:
        break;
    }
}