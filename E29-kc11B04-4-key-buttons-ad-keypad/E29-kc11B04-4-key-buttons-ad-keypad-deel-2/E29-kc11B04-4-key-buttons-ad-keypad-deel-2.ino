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

   Knoppen waarden:
   
   K4 1023
   K3  800
   K2  600
   K1  400
   
*/

const int AD_PIN = A0;

void setup() {
  Serial.begin(9600);
}

void loop() {

  int adValue = analogRead(AD_PIN);
  Serial.println(buttonFromValue(adValue));

}

// Geeft het nummer van de knop terug op basis van de gemeten analoge waarde
byte buttonFromValue(int adValue) {

  if (adValue > 300 && adValue < 500) {
    return 1;
  }

  if (adValue > 500 && adValue < 700) {
    return 2;
  }

  if (adValue > 700 && adValue < 900) {
    return 3;
  }

  if (adValue > 900) {
    return 4;
  }

  return 0;
  
}
