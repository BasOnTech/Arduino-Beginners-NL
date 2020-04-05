/*
 * Bas on Tech - Drukknop longpress
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

//// DRUKKNOP ////

static const int buttonPin = 12;                    // drukknop pin
int buttonStatePrevious = LOW;                      // vorige staat van de drukknop

unsigned long minButtonLongPressDuration = 3000;    // Tijd in milliseconden totdat van "lang drukken" kan worden gesproken
unsigned long buttonLongPressMillis;                // tijdstip in ms waarop knop is ingedrukt
bool buttonStateLongPress = false;                  // is knop lang ingedrukt

const int intervalButton = 50;                      // Tijd in milliseconden tussen het uitlezen van de drukknop
unsigned long previousButtonMillis;                 // Tijdstip van laatste uitlezing staat drukknop

unsigned long buttonPressDuration;                  // Tijd dat drukknop is ingedrukt in ms

//// ALGEMEEN ////

unsigned long currentMillis;          // Variabele voor het aantal milliseconden sinds de Arduino is gestart

void setup() {
  Serial.begin(9600);                 // stel de seriële monitor in

  pinMode(buttonPin, INPUT);          // stel buttonPin in als invoer
  Serial.println("Druk knop in");

}

// Functie voor het uitlezen van de drukknop
void readButtonState() {

  // Als het tijdsverschil met de vorige uitlezing groter is dan intervalButton
  if(currentMillis - previousButtonMillis > intervalButton) {
    
    // Lees de digitale waarde van de drukknop (LOW/HIGH)
    int buttonState = digitalRead(buttonPin);    

    // Als de knop is ingedrukt EN
    // De knop was eerder nog niet ingedrukt EN 
    // Als er geen meting loopt voor het bepalen of de knop lang is ingedrukt
    if (buttonState == HIGH && buttonStatePrevious == LOW && !buttonStateLongPress) {
      buttonLongPressMillis = currentMillis;
      buttonStatePrevious = HIGH;
      Serial.println("Knop ingedrukt");
    }

    // Bereken hoe lang de knop al is ingedrukt
    buttonPressDuration = currentMillis - buttonLongPressMillis;

    // Als de knop is ingedrukt EN
    // Als er geen meting loopt voor het bepalen of de knop lang is ingedrukt EN
    // Als de tijd dat de knop is ingedrukt groter of gelijk aan de minimale tijd die nodig is voor een lang ingedrukte knop
    if (buttonState == HIGH && !buttonStateLongPress && buttonPressDuration >= minButtonLongPressDuration) {
      buttonStateLongPress = true;
      Serial.println("Knop lang ingedrukt");
    }
      
    // Als de knop wordt losgelaten EN
    // Als de knop eerder was ingedrukt
    if (buttonState == LOW && buttonStatePrevious == HIGH) {
      buttonStatePrevious = LOW;
      buttonStateLongPress = false;
      Serial.println("Knop losgelaten");

      // Als er geen meting loopt voor het bepalen of de knop lang is ingedrukt EN
      // Als de tijd dat de knop is ingedrukt kleiner is dan de minimale tijd die nodig is voor een lang ingedrukte knop
      // Note: In de video staat:
      //       if (!buttonStateLongPress && buttonPressDuration < minButtonLongPressDuration) {
      //       omdat buttonStateLongPress op regel 75 op FALSE wordt gezet, is !buttonStateLongPress altijd TRUE
      //       dit kan dus worden weggehaald.
      if (buttonPressDuration < minButtonLongPressDuration) {
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
