/*
 * Bas on Tech - LED Knipperen breadboard
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

// De setup functie wordt eenmalig uitgevoerd als je programma start
void setup() {
  // Initialiseer digitale pin LED_BUILTIN als een uitvoer
  pinMode(LED_BUILTIN, OUTPUT);
}

// De loop functie wordt oneindig herhaald
void loop() {
  digitalWrite(LED_BUILTIN, HIGH);   // Zet de ingebouwde LED aan
  delay(1000);                       // Pauzeer 1 seconde (1000 milliseconden)
  
  digitalWrite(LED_BUILTIN, LOW);    // Zet de ingebouwde LED uit
  delay(1000);                       // Pauzeer 1 seconde (1000 milliseconden)
}