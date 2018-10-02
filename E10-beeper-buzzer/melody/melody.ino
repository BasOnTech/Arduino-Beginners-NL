 /*
  * Bas on Tech - Beeper / buzzer
  * Deze les is onderdeel van de lessen op https://arduino-lessen.nl
  *  
  * (c) Copyright 2018 - Bas van Dijk / Bas on Tech
  * Deze code en inhoud van de lessen mag zonder schriftelijke toestemming 
  * niet voor commerciele doeleinden worden gebruikt
  * 
  * YouTube:    https://www.youtube.com/c/BasOnTechNL
  * Facebook:   https://www.facebook.com/BasOnTechChannel
  * Instagram:  https://www.instagram.com/BasOnTech
  * Twitter:    https://twitter.com/BasOnTech
  * 
  */

// Importeer de toonhoogstes van de noten
#include "pitches.h"

// stel de variable "buzzerPin" op pin 12
int buzzPin = 12;             

// noten van de melodie
int melody[] = {
  NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
};

// duur van de noten: 4 = kwart noot, 8 = achtste noot etc.
int noteDurations[] = {
  4, 8, 8, 4, 4, 4, 4, 4
};

void setup(void) {
  pinMode(buzzPin, OUTPUT);         // stel de buzzerPin in als uitvoer
}

void loop() {
  playMelody();                     // voer "playMelody" functie uit
  delay(10000);                     // wacht 10 seconden
}

void playMelody() {
  
  /* stap langs alle noten in melody[]
   *
   * In de video staat hier nog sizeof(melody) Het is echter gebleken dat sizeof een verkeerde waarde
   * kan teruggeven waardoor er een geheugenfout ontstaat. Hierdoor kan de buzzer na de melodie nog
   * een bibberend geluid blijven geven. De 8 staat voor het totaal aantal noten.
   */
  for (int i = 0; i < 8; i++) {

    // om de lengte van de noten te berekenen nemen we 1 seconden en delen deze door het type noot
    // bijv. een kwart noot = 1000 / 4, een achtste noot = 1000/8, etc. 
    int noteDuration = 1000 / noteDurations[i];

    // Roep tone() aan met de huidige noot van de melodie en de lengte van de huidige noot.
    tone(buzzPin, melody[i], noteDuration);

    // om de noten te onderscheiden stellen we een minimale tijd tussen twee noten in
    // het is gebleken dat de nootlengte plus 30% goed werkt, vandaar de 1.30
    int pauseBetweenNotes = noteDuration * 1.30;

    // pauzeer voor de berekende duur
    delay(pauseBetweenNotes);
    
    // stop het spelen van de huidige noot
    noTone(buzzPin);
  }
}