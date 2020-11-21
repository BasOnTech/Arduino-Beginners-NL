/*
 * Bas on Tech - Ultrasoon sensor
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
 * 
 * Originele code van:
 * https://create.arduino.cc/projecthub/Isaac100/getting-started-with-the-hc-sr04-ultrasonic-sensor-036380
 *
 *
 * PIN AANSLUITINGEN
 *
 * Vcc  --> 5V
 * Trig --> 12
 * Echo --> 8
 * GND  --> GND
 *
 */

const int trigPin = 12;   // trigger pin
const int echoPin = 8;    // echo in

float duration;           // variabele voor tijdsduur als kommagetal (float)
float distance;           // variabele voor afstand als kommagetal (float)

void setup() {
  Serial.begin(9600);               // stel de seriële monitor in
  pinMode(trigPin, OUTPUT);         // stel de trigger pin in als uitvoer
  pinMode(echoPin, INPUT);          // stel de echo pin in als invoer
}

void loop() {
  digitalWrite(trigPin, LOW);       // zet de trigPin op LOW
  delayMicroseconds(2);             // wacht 2 microseconden zodat de trigPin ook daadwerkelijk LOW is

  digitalWrite(trigPin, HIGH);      // zet de trigPin op HIGH om ultrasoon geluid te zenden
  delayMicroseconds(10);            // wacht 10 microseconden
  digitalWrite(trigPin, LOW);       // set de trigPin op LOW om het zenden te stoppen

  duration = pulseIn(echoPin, HIGH);     // vraag de tijdsduur op van hoe lang het duurde tot de echoPin HIGH was. 
                                         // Let op dat pulseIn het programma voor pauseert totdat er een signaal terug is ontvangen
                                         // standaard is de timeout 1 seconden. Dus het programma staat maximaal 1 seconde stil.
  distance = (duration * 0.0343) / 2;    // bereken de afstand aan de hand van de snelheid van het geluid
                                         // dit getal moet door 2 worden gedeeld omdat het geluid heen en terug is gegaan.
  Serial.print("Afstand: ");             // Toon het resultaat op de seriële monitor
  Serial.println(distance);

  delay(100);                            // wacht 100ms tot een volgende meting
}
