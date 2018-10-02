// Bas on Tech - Arduino tutorial 1
// https://arduino-lessen.nl

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