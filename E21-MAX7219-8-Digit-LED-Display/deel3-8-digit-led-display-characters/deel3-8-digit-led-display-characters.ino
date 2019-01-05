/*
 * Bas on Tech - 8 segment LED display
 * Deze les is onderdeel van de lessen op https://arduino-lessen.nl
 *  
 * (c) Copyright 2018-2019 - Bas van Dijk / Bas on Tech
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
 
// Gebruik de BoTLedControl bibliotheek
#include "BoTLedControl.h"

// Initialiseer de LedControl bibliotheek met
// pin 7 op DIN, 
// pin 6 op Clk, 
// pin 5 op LOAD
// aantal displays 1
LedControl lc = LedControl(7, 6, 5, 1);

int i = 0;

String charString = "0123456789ABCDEFGHIJLNOPQRSTUYabcdefghijlnopqrstuy,-/\[]._";
char charBuf[60];

void setup() {
  // De MAX72XX chip staat in power-safe mode bij het opstarten
  // deze maken we wakker met shutdown van apparaat 0
  lc.shutdown(0, false);

  // Stel de helderheid van het scherm op apparaat 0 in met een waarde van 0 tot 15
  lc.setIntensity(0, 5);
  
  // Maak scherm schoon van apparaat 0
  lc.clearDisplay(0);

  // Kopieer de charString naar een array van characters in charBuf
  charString.toCharArray(charBuf, 60);
}

void loop() { 

  // Toon karakter van apparaaat 0,
  // Op led positie i % 8, oftewel de restwaarde van een deling door 8
  // met het karakter op charBuf[i]
  // zonder decimaal punt
  lc.setChar(0, i % 8, charBuf[i], false);
  i++;

  // Als we alle 60 karakters gehad hebben
  if (i > 60) {
    i = 0;
  }
  
  delay(250);
}
