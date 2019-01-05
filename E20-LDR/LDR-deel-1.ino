/*
 * Bas on Tech - LDR
 * Deze les is onderdeel van de lessen op https://arduino-lessen.nl
 *  
 * (c) Copyright 2019 - Bas van Dijk / Bas on Tech
 * Deze code en inhoud van de lessen mag zonder schriftelijke toestemming 
 * niet voor commerciele doeleinden worden gebruikt
 * 
 * YouTube:    https://www.youtube.com/c/BasOnTechNL
 * Facebook:   https://www.facebook.com/BasOnTechChannel
 * Instagram:  https://www.instagram.com/BasOnTech
 * Twitter:    https://twitter.com/BasOnTech
 * 
 */

int ldrPin = A0;              // LDR pin
int ldrVal = 0;               // Waarde van potmeter

void setup() {
  Serial.begin(9600);         // Stel de seriële monitor in
}

// Herhaal oneindig
void loop() {
  
  ldrVal = analogRead(ldrPin);    // Lees de analoge waarde van de LDR
  Serial.println(ldrVal);         // Toon de waarde in de seriële monitor

  delay(100);                     // Pauzeer 100ms
  
}