/*
   Bas on Tech - Verkeerslicht stap 3
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

const int PIN_RED = 8;
const int PIN_YELLOW = 9;
const int PIN_GREEN = 10;

const int DELAY_RED = 5000;
const int DELAY_YELLOW = 1000;
const int DELAY_GREEN = 5000;

void setup()
{
  // Stel pin 8 t/m 10 in als uitvoer
  pinMode(PIN_RED, OUTPUT);
  pinMode(PIN_YELLOW, OUTPUT);
  pinMode(PIN_GREEN, OUTPUT);

  allOff();
}

void loop()
{
  // Rood
  digitalWrite(PIN_RED, HIGH);
  delay(DELAY_RED);
  digitalWrite(PIN_RED, LOW);

  // Groen
  digitalWrite(PIN_GREEN, HIGH);
  delay(DELAY_GREEN);
  digitalWrite(PIN_GREEN, LOW);

  // Oranje / Geel
  digitalWrite(PIN_YELLOW, HIGH);
  delay(DELAY_YELLOW);
  digitalWrite(PIN_YELLOW, LOW);
}

// Zet alle uitvoer op LOW zodat de LED's niet branden
void allOff()
{
  digitalWrite(PIN_RED, LOW);
  digitalWrite(PIN_YELLOW, LOW);
  digitalWrite(PIN_GREEN, LOW);
}
