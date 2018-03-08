// Bas on Tech - Arduino tutorial 3
// http://basontech.nl

// Geef aan welke PWM pin er gebruikt wordt
int ledPin = 11;

// Voer uit bij de start van programma
void setup() {
  // Initialiseer digitale pin LED_BUILTIN als een uitvoer
  pinMode(LED_BUILTIN, OUTPUT);
}

// Herhaal oneindig
void loop() {

  // Fade in
  for(int ledVal = 0; ledVal <= 255; ledVal +=1) {
    analogWrite(ledPin, ledVal);
    delay(15);
  }  

  // Fade uit
  for(int ledVal = 255; ledVal >= 0; ledVal -=1) {
    analogWrite(ledPin, ledVal);
    delay(15);
  } 
  
  // Pauzeer voor 1 seconde
  delay(1000);
  
}

