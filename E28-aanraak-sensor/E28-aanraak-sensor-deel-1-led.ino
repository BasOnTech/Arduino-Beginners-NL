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

void setup()
{ 
  pinMode(8, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  
  // Zet ingebouwde LED uit
  digitalWrite(LED_BUILTIN, LOW);
}

void loop()
{
 
  if(digitalRead(8) == HIGH) {
    digitalWrite(LED_BUILTIN, HIGH);
  } else {
    digitalWrite(LED_BUILTIN, LOW);
  }

  delay(100);
}
