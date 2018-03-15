/*
 * Bas on Tech - Arduino tutorial
 * http://basontech.nl
 * 
 */

//// DRUKKNOP ////

static const int buttonPin = 12;             // drukknop pin
int buttonState = LOW;                       // huidige staat van de drukknop
int buttonStatePrevious = LOW;               // vorige staat van de drukknop

const int intervalButtonLongPress = 3000;    // Tijd in milliseconden totdat van "lang drukken" kan worden gesproken
unsigned long buttonLongPressMillis = 0;       // tijd verstreken sinds indrukken knop
bool buttonStateLongPress = false;           // is knop lang ingedrukt

const int intervalButton = 100;              // Tijd in milliseconden tussen het uitlezen van de drukknop
unsigned long previousButtonMillis = 0;      // Tijdstip van laatste uitlezing staat drukknop

unsigned long buttonPressDuration = 0;        // Tijd dat drukknop is ingedrukt in ms

//// ALGEMEEN ////

unsigned long currentMillis = 0;             // Variabele voor het aantal milliseconden sinds de Arduino is gestart

void setup() {
  Serial.begin(9600);                        // stel de seriële monitor in

  pinMode(buttonPin, INPUT);                 // stel buttonPin in als invoer
  Serial.println("Druk knop in");

}

// Functie voor het uitlezen van de drukknop
void readButtonState() {

  // Als het tijdsverschil met de vorige uitlezing groter is dan intervalButton
  if(currentMillis - previousButtonMillis > intervalButton) {
    
    // Lees de digitale waarde van de drukknop (LOW/HIGH)
    buttonState = digitalRead(buttonPin);    

    // Als er nog geen meting loopt voor lang drukken en de knop is net voor het 
    // eerst ingedrukt (buttonState == HIGH && buttonStatePrevious == LOW)
    if (!buttonStateLongPress && buttonState == HIGH && buttonStatePrevious == LOW) {
      buttonLongPressMillis = currentMillis;
      buttonStatePrevious = HIGH;
      Serial.println("Knop ingedrukt");
    }

    // Bereken hoe lang de knop al is ingedrukt
    buttonPressDuration = currentMillis - buttonLongPressMillis;

    // Als de knop is ingedrukt
    if (buttonState == HIGH) {

      // Als de verstreken indruktijd groter is dan intervalButtonLongPress
      if (!buttonStateLongPress && buttonPressDuration >= intervalButtonLongPress) {
        buttonStateLongPress = true;
        Serial.println("Knop lang ingedrukt");
      }
      
    }

    // Als de knop wordt losgelaten
    if (buttonState == LOW && buttonStatePrevious == HIGH) {
        buttonStatePrevious = LOW;
        buttonStateLongPress = false;
        Serial.println("Knop losgelaten");

        if (!buttonStateLongPress && buttonPressDuration < intervalButtonLongPress) {
          Serial.println("Knop kort ingedrukt");
        }
    }
    
    // sla het huidige tijdstip op in previousButtonMillis
    previousButtonMillis = currentMillis;

  }
}


void loop() {

  currentMillis = millis();    // sla de huidige tijd op
  readButtonState();           // lees de drukknop uit
  
}
