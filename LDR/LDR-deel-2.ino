/*
 * Bas on Tech - LDR
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

int ldrPin = A0;              // LDR pin
int ldrVal = 0;               // Waarde van LDR
int ledPin = LED_BUILTIN;     // Ingebouwde LED pin

void setup() {
  Serial.begin(9600);         // Stel de seriële monitor in
}

// Herhaal oneindig
void loop() {
  
  ldrVal = analogRead(ldrPin);    // Lees de analoge waarde van de LDR
  Serial.println(ldrVal);         // Toon de waarde in de seriële monitor

  if (ldrVal < 200) {             // Als de LDR waarde lager is dan 200
    digitalWrite(ledPin, HIGH);   // Zet ingebouwde LED aan
  } else {
    digitalWrite(ledPin, LOW);    // Zet ingebouwde LED uit
  }

  delay(100);                     // Pauzeer 100ms
  
}