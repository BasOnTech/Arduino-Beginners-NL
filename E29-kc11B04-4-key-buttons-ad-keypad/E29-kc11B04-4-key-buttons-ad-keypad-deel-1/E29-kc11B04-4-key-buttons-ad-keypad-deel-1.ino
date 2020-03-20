/*
   Bas on Tech - Aanraak sensor
   Deze les is onderdeel van de lessen op https://arduino-lessen.nl

   (c) Copyright 2020 - Bas van Dijk / Bas on Tech
   Deze code en inhoud van de lessen mag zonder schriftelijke toestemming
   niet voor commerciele doeleinden worden gebruikt

   YouTube:    https://www.youtube.com/c/BasOnTechNL
   Facebook:   https://www.facebook.com/BasOnTechChannel
   Instagram:  https://www.instagram.com/BasOnTech
   Twitter:    https://twitter.com/BasOnTech

   ---------------------------------------------------------------------------
   
*/

const int AD_PIN = A0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.println(analogRead(AD_PIN));
}
