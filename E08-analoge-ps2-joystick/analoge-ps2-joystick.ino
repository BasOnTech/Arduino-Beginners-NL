 /*
  * Bas on Tech - Analog PS2 joystick
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
  * ---------------------------------------------------------------------------
  *
  * PIN AANSLUITINGEN
  *
  * GND --> GND
  * +5V --> 5V
  * VRX --> A5
  * VRY --> A0
  * SW  --> 12
  *
  */


// Definieer de pin-nummers
const int swPin = 12;
const int VrxPin = A5;
const int VryPin = A0;

// Stel de variabelen in op hun beginwaarde
int xDirection = 0;
int yDirection = 0;
int switchState = 1;

void setup() {
    Serial.begin(9600);

    pinMode(swPin, INPUT);

    // De joystick knop is altijd HIGH en LOW als de knop wordt ingedrukt
    digitalWrite(swPin, HIGH);
}

void loop() {

    // Lees de analoge waarden van de joystick
    xDirection = analogRead(VryPin);
    yDirection = analogRead(VrxPin);

    // Lees de staat van de drukknop
    switchState = digitalRead(swPin);

    // Print de gelezen waarden naar de seriële monitor
    Serial.print("Schakelaar:  ");
    Serial.println(switchState);

    Serial.print("X-as:        ");
    Serial.println(xDirection);

    Serial.print("Y-as:        ");
    Serial.println(yDirection);

    Serial.println("");

    // Omdat de schakelaar HIGH is als hij NIET is ingedrukt moeten we de gelezen waarde omdraaien
    // Dit doen we door er een uitroepteken voor te zetten. HIGH wordt dan LOW en andersom.
    if (!switchState) {
        Serial.println("Schakelaar ingedrukt");
    }

    // Voor de joystick nemen we niet precies 512 als midden omdat een analoge waarde een
    // beetje kan schommelen. In het midden stond de joystick rond de 500, vandaar de marge
    // van 20 op alle richtingen.

    // Bepaal de richting van de joystick op de X-as
    if (xDirection < 480) {
        Serial.println("Links");
    } else if (xDirection > 520) {
        Serial.println("Rechts");
    }

    // Bepaal de richting van de joystick op de Y-as
    if (yDirection < 480) {
        Serial.println("Omlaag");
    } else if (yDirection > 520) {
        Serial.println("Omhoog");
    }

    delay(500);
}
