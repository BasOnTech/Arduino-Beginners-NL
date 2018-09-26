/*
 * Bas on Tech - I2C LCD
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
 * ---------------------------------------------------------------------------
 * 
 * Meer informatie over I2C: https://nl.wikipedia.org/wiki/I%C2%B2C-bus
 *
 *
 * PIN AANSLUITINGEN
 * 
 * SDA is serial data
 * SCL is serial clock
 *
 * GND --> GND wit
 * VCC --> 5V  grijs
 * SDA --> A4  rood
 * SCL --> A5  blauw
 * 
 * 
 * I2C aansluitingen per Arduino:
 * Uno, Ethernet    A4 (SDA), A5 (SCL)
 * Mega2560         20 (SDA), 21 (SCL)
 * Leonardo          2 (SDA),  3 (SCL)
 * Due              20 (SDA), 21 (SCL) of SDA1, SCL1
 *
 */

// Bibliotheek voor communicatie met I2C / TWI apparaten
#include <Wire.h> 

// Bibliotheek voor het LCD scherm
#include <LiquidCrystal_I2C.h>

/* 
 * Stel hier in welke chip en foromaat LCD je hebt
 * Gebruik 0x27 als je chip PCF8574 hebt van NXP
 * Gebruik 0x3F als je chip PCF8574A hebt van Ti (Texas Instruments)
 * De laatste twee getallen geven het formaat van je LCD aan
 * bijvoorbeeld 20x4 of 16x2
 *  
 */  
LiquidCrystal_I2C lcd(0x27, 20, 4);
//LiquidCrystal_I2C lcd(0x3F, 16, 2);
 
void setup() {
  lcd.init();                   // initialiseer het LCD scherm
  lcd.backlight();              // zet de backlight aan

  lcd.clear();                  // wis het scherm
  lcd.setCursor(0, 0);          // zet de cursor op positie 1, regel 1
  lcd.print("Hallo YouTube!");  // schrijf op scherm
}
 
void loop() {}