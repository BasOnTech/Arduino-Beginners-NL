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
 * PIN AANSLUITINGEN ULTRASOON SENSOR
 *
 * Vcc  --> 5V
 * Trig --> 12
 * Echo --> 8
 * GND  --> GND
 *
 *
 * PIN AANSLUITINGEN SCHERM
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

const int trigPin = 12;   // trigger pin
const int echoPin = 8;    // echo in

float duration;           // variabele voor tijdsduur als kommagetal (float)
float distance;           // variabele voor afstand als kommagetal (float)

void setup() {
  Serial.begin(9600);               // stel de seriële monitor in

  // Ultrasoon sensor
  pinMode(trigPin, OUTPUT);         // stel de trigger pin in als uitvoer
  pinMode(echoPin, INPUT);          // stel de echo pin in als invoer

  // LCD scherm
  lcd.init();                       // initialiseer het LCD scherm
  lcd.backlight();                  // zet de backlight aan
}

void loop() {

  // Ultrasoon sensor
  digitalWrite(trigPin, LOW);            // zet de trigPin op LOW
  delayMicroseconds(2);                  // wacht 2ms zodat de trigPin ook daadwerkelijk LOW is

  digitalWrite(trigPin, HIGH);           // zet de trigPin op HIGH om ultrasoon geluid te zenden
  delayMicroseconds(10);                 // wacht 10ms
  digitalWrite(trigPin, LOW);            // set de trigPin op LOW om het zenden te stoppen

  duration = pulseIn(echoPin, HIGH);     // vraag de tijdsduur op van hoe lang de echoPin HIGH was
  distance = (duration * 0.0343) / 2;    // bereken de afstand aan de hand van de snelheid van het geluid
                                         // dit getal moet door 2 worden gedeeld omdat het geluid heen en terug is gegaan.
  Serial.print("Afstand: ");             // Toon het resultaat op de seriële monitor
  Serial.println(distance);

  // LCD scherm
  lcd.clear();                           // wis het scherm
  lcd.setCursor(0, 0);                   // zet de cursor op positie 1, regel 1
  lcd.print(distance);                   // schrijf op scherm
  lcd.print(" cm");                      // schrijf op scherm

  delay(100);                            // wacht 100ms tot een volgende meting
}