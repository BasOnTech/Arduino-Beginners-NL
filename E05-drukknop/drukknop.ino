/*
 * Bas on Tech - Drukknop
 * Deze les is onderdeel van de lessen op https://arduino-lessen.nl
 *  
 * (c) Copyright 2018 - Bas van Dijk / Bas on Tech
 * Deze code en inhoud van de lessen mag zonder schriftelijke toestemming 
 * niet voor commerciele doeleinden worden gebruikt
 * 
 * YouTube:    https://www.youtube.com/c/BasOnTechNL
 * Facebook:   https://www.facebook.com/BasOnTechChannel
 * Instagram:  https://www.instagram.com/BasOnTech
 * Twitter:    https://twitter.com/BasOnTech
 * 
 */ 

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
