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

/* 
 * Dit hart-symbool is online gemaakt met de LCD symbool generator op:
 * https://maxpromer.github.io/LCD-Character-Creator/
 */
byte heart[] = {
  0x00,
  0x0A,
  0x1F,
  0x1F,
  0x0E,
  0x04,
  0x00,
  0x00
};
 
void setup() {
  lcd.init();                  // initialiseer het LCD scherm
  lcd.backlight();             // zet de backlight aan
  lcd.createChar(1, heart);    // definieer een symbool in geheugen positie 1
}
 
void loop() {
  lcd.clear();                 // wis het scherm

  screen1();                   // voer functie screen1 uit
  delay(1000);                 // pauzeer 1 seconde

  screen2();                   // voer functie screen2 uit
  delay(1000);                 // pauzeer 1 seconde
}

void screen1() {
  lcd.setCursor(0, 1);         // zet de cursor op positie 1, regel 2
  lcd.print("  I ");           // schrijf op scherm
  lcd.write(1);                // teken symbool uit geheugen positie 1
  lcd.print(" BasOnTech.nl");  // schrijf op scherm
}

void screen2() {               
  lcd.setCursor(4, 1);         // zet de cursor op positie 5, regel 2
  lcd.print("I ");             // schrijf op scherm
  lcd.write(1);                // teken symbool uit geheugen positie 1
  lcd.print(" Arduino");       // schrijf op scherm
}
