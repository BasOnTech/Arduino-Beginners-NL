/*
 * Bas on Tech - Potmeter
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

int potPin = A2;              // Potmeter pin
int ledPin = LED_BUILTIN;     // Ingebouwde LED pin
int potVal = 0;               // Waarde van potmeter

void setup() {
  Serial.begin(9600);         // Stel de seriële monitor in
  pinMode(ledPin, OUTPUT);    // Stel de ledPin in als uitvoer
}

// Herhaal oneindig
void loop() {
  
  potVal = analogRead(potPin);    // Lees de analoge waarde van de potmeter 0-1023
  Serial.println(potVal);         // Toon de waarde in de seriële monitor
  
  digitalWrite(ledPin, HIGH);     // Zet de ingebouwde LED aan
  delay(potVal);                  // Pauzeer de waarde van de potmeter
  
  digitalWrite(ledPin, LOW);      // Zet de ingebouwde LED uit
  delay(potVal);                  // Pauzeer de waarde van de potmeter
  
}

