/*
 * Bas on Tech - Schuif potmeter
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

int potmeterPin = A0;              // Schuif potmeter pin op A0
int potmeterVal = 0;               // Waarde van potmeter

void setup() {
  Serial.begin(9600);              // Stel de seriële monitor in
}

// Herhaal oneindig
void loop() {
  
  potmeterVal = analogRead(potmeterPin);    // Lees de analoge waarde van de Schuif potmeter
  Serial.println(potmeterVal - 300);        // Toon de waarde in de seriële monitor

  delay(100);                               // Pauzeer 100ms
  
}