/*
   Bas on Tech - Verkeerslicht stap 1
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

void setup()
{
  // Stel pin 8 t/m 10 in als uitvoer
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);

  // Zet alle uitvoer op LOW zodat de LED's niet branden
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
}

void loop()
{
  // Rood
  digitalWrite(8, HIGH);
  delay(5000);
  digitalWrite(8, LOW);

  // Groen
  digitalWrite(10, HIGH);
  delay(5000);
  digitalWrite(10, LOW);

  // Oranje / Geel
  digitalWrite(9, HIGH);
  delay(1000);
  digitalWrite(9, LOW);
}
