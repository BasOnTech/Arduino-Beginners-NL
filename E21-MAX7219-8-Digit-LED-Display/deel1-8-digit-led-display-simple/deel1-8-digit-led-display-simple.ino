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

void setup() {

  // De MAX72XX chip staat in power-safe mode bij het opstarten
  // deze maken we wakker met shutdown van apparaat 0
  lc.shutdown(0, false);

  // Stel de helderheid van het scherm op apparaat 0 in met een waarde van 0 tot 15
  lc.setIntensity(0, 5);
  
  // Maak scherm schoon van apparaat 0
  lc.clearDisplay(0);

  // Toon op apparaat 0, positie 0, een 8, zonder decimaal punt
  lc.setDigit(0, 0, 8, false);

  // Toon op apparaat 0, positie 2, een 5, met decimaal punt
  lc.setDigit(0, 2, 5, true);

  // Toon op apparaat 0, positie 4, een A, zonder decimaal punt
  lc.setChar(0, 4, 'A', false);

  //
  //      N
  //   NW   NO
  //      M
  //   ZW   ZO
  //      Z      D
  //
  // D N NO ZO Z ZW NW M
  lc.setRow(0, 6, B01001001);
}

void loop() {}
