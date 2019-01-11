/*
 * Bas on Tech - 8 segment LED display
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
 * ----------------------------------------------------------------------
 * 
 * LedControl bibliotheek: https://github.com/wayoda/LedControl
 * 
 */

// Gebruik de LedControl bibliotheek
#include "LedControl.h"

// Initialiseer de LedControl bibliotheek met
// pin 7 op DIN, 
// pin 6 op Clk, 
// pin 5 op LOAD
// aantal displays 1
LedControl lc = LedControl(7, 6, 5, 1);

int i = 0;

void setup() {
  // De MAX72XX chip staat in power-safe mode bij het opstarten
  // deze maken we wakker met shutdown van apparaat 0
  lc.shutdown(0, false);

  // Stel de helderheid van het scherm op apparaat 0 in met een waarde van 0 tot 15
  lc.setIntensity(0, 5);
  
  // Maak scherm schoon van apparaat 0
  lc.clearDisplay(0);
}

// Toont een nummer van maximaal 4 getallen, dus 0...9999
void printNumber(int number) {  
    int ones;      // eenheden
    int tens;      // tientallen
    int hundreds;  // honderdtallen
    int thousands; // duizendtallen

    // Bepaal uit hoeveel enen het getal bestaat
    // door de rest te nemen als het getal door 10 gedeeld wordt
    ones = number % 10;
    // Sla het aantal volledig passende delingen op
    number = number / 10;

    // Bepaal uit hoeveel tientallen het getal bestaat
    // door de rest te nemen als het getal door 10 gedeeld wordt
    tens = number % 10;  
    number = number / 10; 

    // Bepaal uit hoeveel honderdtallen het getal bestaat
    // door de rest te nemen als het getal door 10 gedeeld wordt
    hundreds = number % 10;
    number = number / 10;
    
    thousands = number;

    // Toon de getallen op het display
    lc.setDigit(0, 3, thousands, false);
    lc.setDigit(0, 2, hundreds, false);
    lc.setDigit(0, 1, tens, false); 
    lc.setDigit(0, 0, ones, false); 
} 

void printNumber2(long number) {

  // Array van 8 bytes voor elke positie op LED display
  byte digits[8] = {0, 0, 0, 0, 0, 0, 0, 0};

  // Loop over elke positie en bepaald het getaal wat er moet komen te staan
  for (int i; i < 8; i++) {
      digits[i] = number % 10;
      number = number / 10;   
  }

  // Loop alle LED posities af
  for (int i; i < 8; i++) {
    // Toon getal op positie i op LED display
    lc.setDigit(0, i, digits[i], false);
  }
  
}


void printNumber3(long number) {

  // Array van 8 bytes voor elke positie op LED display
  byte digits[8] = {0, 0, 0, 0, 0, 0, 0, 0};

  // Loop over elke positie en bepaald het getaal wat er moet komen te staan
  for (int i; i < 8; i++) {
      digits[i] = number % 10;
      number = number / 10;   
  }

  // Hierin wordt opgeslagen of het eerste getal is gevonden wat niet 
  // gelijk is aan 0
  bool firstNonZeroFound = false;

  // Loop achteruit van 7 naar 0
  for (int i = 7; i >= 0; i--) {

      // Als het getal ongelijk is aan 0
      if(digits[i] != 0) {
        firstNonZeroFound = true;
      } 

      // Als het eerste getal ongelijk aan 0 is gevonden tool deze
      if (firstNonZeroFound) {
        lc.setDigit(0, i, digits[i], false);
      }
  }
  
}

void loop() { 
  lc.clearDisplay(0);
  printNumber3(i);
  i++;
  delay(100);
}
