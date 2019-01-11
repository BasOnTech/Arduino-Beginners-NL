 /*
  * Bas on Tech - 1-wire beeper / buzzer
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

int buzzerPin = 12;                 // stel de variable "buzzerPin" in op pin 12

void setup(void) {
  pinMode(buzzerPin, OUTPUT);       // stel de buzzerPin in als uitvoer
}

void loop() {
  beep();                           // voer de "beep" functie uit
  delay(5000);                      // pauzeer 5s
}

void beep() {

  // tone(pin, frequentie, duur in milliseconden)
  tone(buzzerPin, 196, 200);        // Laat toon van 196hz, 200ms lang horen

  delay(200);                       // pauzeer 200ms
  
}
