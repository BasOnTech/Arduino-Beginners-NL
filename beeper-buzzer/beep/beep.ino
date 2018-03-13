// Bas on Tech - Arduino tutorial 10 - deel 1
// https://arduino-lessen.nl

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
