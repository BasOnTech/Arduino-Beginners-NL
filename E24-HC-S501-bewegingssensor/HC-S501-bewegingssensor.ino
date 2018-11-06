/*
 * Bas on Tech - Schuif potmeter
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

int ledPin = 13;   // Ingebouwde LED op pin 13 van Arduino
int pirPin = 12;   // Pin voor de HC-S501 sensor
int pirValue;      // Uitgelezen sensor waarde

void setup() {
  pinMode(ledPin, OUTPUT);    // Stel de ledPin in als uitvoer
  pinMode(pirPin, INPUT);     // Stel de pirPin in als invoer
   digitalWrite(ledPin, LOW);  // Zet het ingebouwde LED uit
}

// Herhaal oneindig
void loop() {
  pirValue = digitalRead(pirPin); // Lees de waarde van de PIR uit
  digitalWrite(ledPin, pirValue); // Schrijf de gelezen waarde naar het ingebouwde LED  
}