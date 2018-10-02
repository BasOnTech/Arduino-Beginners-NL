/*
 * Bas on Tech - LED knipperen
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

// Geef aan welke PWM pin er gebruikt wordt
int ledPin = 11;

// Voer uit bij de start van programma
void setup() {
  // Initialiseer digitale pin ledPin als een uitvoer
  pinMode(ledPin, OUTPUT);
}

// Herhaal oneindig
void loop() {

  // Fade in
  for(int ledVal = 0; ledVal <= 255; ledVal +=1) {
    analogWrite(ledPin, ledVal);
    delay(15);
  }  

  // Fade uit
  for(int ledVal = 255; ledVal >= 0; ledVal -=1) {
    analogWrite(ledPin, ledVal);
    delay(15);
  } 
  
  // Pauzeer voor 1 seconde
  delay(1000);
  
}

