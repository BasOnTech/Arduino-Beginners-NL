/*
   Bas on Tech - 4x4 Membraan Keypad
   Deze les is onderdeel van de lessen op https://arduino-lessen.nl

   (c) Copyright 2020 - Bas van Dijk / Bas on Tech
   Deze code en inhoud van de lessen mag zonder schriftelijke toestemming
   niet voor commerciele doeleinden worden gebruikt

   YouTube:    https://www.youtube.com/c/BasOnTechNL
   Facebook:   https://www.facebook.com/BasOnTechChannel
   Instagram:  https://www.instagram.com/BasOnTech
   Twitter:    https://twitter.com/BasOnTech

   ---------------------------------------------------------------------------
*/

#include <Keypad.h>

const byte ROWS = 4; // vier rijen
const byte COLS = 4; // vier kolommen

// Knoppen koppelen aan een array voor de Keymap instantie
char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte colPins[ROWS] = {5, 4, 3, 2}; // Pinnen gebruikt voor de rijen van het keypad
byte rowPins[COLS] = {9, 8, 7, 6}; // Pinnen gebruikt voor de kolommen van het keypad

// Initialiseer het Keypad
Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

void setup() {
  Serial.begin(9600);   // Initialiseer de seriele monitor
}

void loop() {

  // Lees de ingedrukte knop uit
  char button = customKeypad.getKey();

  if (button) {
    Serial.println(button);
  }
}
