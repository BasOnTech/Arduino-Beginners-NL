// Bas on Tech - Arduino tutorial 5
// http://basontech.nl

int switchPin = 12;                     // drukknop pin
int ledPin = LED_BUILTIN;               // ingebouwde LED pin
int switchState = LOW;                  // waarde van de drukknop

// Voer uit bij de start van programma
void setup() {
    Serial.begin(9600);                 // stel de seriële monitor in
    pinMode(ledPin, OUTPUT);            // stel de led pin in als uitvoer
    pinMode(switchPin, INPUT);          // stel de switch pin in als invoer
}

// Herhaal oneindig
void loop() {

    switchState = digitalRead(switchPin);    // Lees de digitale waarde van de schakelaar (LOW/HIGH)
    Serial.println(switchState);             // Toon de waarde in de seriële monitor

    if (switchState == HIGH) {               // Als de schakelaar is ingedrukt (HIGH)
        digitalWrite(ledPin, HIGH);          // Zet de ingebouwde LED aan
    } else {
        digitalWrite(ledPin, LOW);           // Zet de ingebouwde LED uit  
    }

}
