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

unsigned long previousMillis = 0;     // Vorige millis
unsigned long elapsedMillis = 0;      // Verstreken millis
int ledState = LOW;                   // Huidige staat van de LED
int debounceTime = 1000;              // Debounce tijd voor de sensor

void setup()
{
  pinMode(8, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  
  // Zet ingebouwde LED uit
  digitalWrite(LED_BUILTIN, LOW);
}

void loop()
{

  // Bereken het aantal verstreken milliseconden
  elapsedMillis = millis() - previousMillis;

  // Als de sensor wordt aangeraakt EN
  // de verstreken tijd groter is dan de ingestelde debounce tijd
  if(digitalRead(8) == HIGH && elapsedMillis > debounceTime) {

    // Zet ledState naar LOW als hij HIGH was en andersom
    if(ledState == HIGH) {
      ledState = LOW;
    } else {
      ledState = HIGH;
    }

    // stuur ledState naar de ingebouwde LED
    digitalWrite(LED_BUILTIN, ledState);

    // Sla de huidige millis op in previousMillis
    previousMillis = millis();
  };

}
