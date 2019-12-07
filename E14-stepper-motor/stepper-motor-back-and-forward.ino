/*
 * Bas on Tech - Stappen motor voor en achteruit
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
 * Originele code van:
 * http://www.airspayce.com/mikem/arduino/AccelStepper/index.html door Mike McCauley
 *
 */

#include <AccelStepper.h>           // Gebruikt AccelStepper bibliotheek

#define motorPin1  8                // IN1 pin op de ULN2003A driver
#define motorPin2  9                // IN2 pin op de ULN2003A driver
#define motorPin3  10               // IN3 pin op de ULN2003A driver
#define motorPin4  11               // IN4 pin op de ULN2003A driver

int stepsPerRevolution = 64;        // stappen per omwenteling
float degreePerRevolution = 5.625;  // graden per omwenteling

/*
 * AccelStepper::FULL2WIRE (2) betekent een 2 wire stepper (2 pins nodig). 
 * AccelStepper::FULL3WIRE (3) betekent een 3 wire stepper, zoals een harde schijf motor (3 pins nodig). 
 * AccelStepper::FULL4WIRE (4) betekent een 4 wire stepper (4 pins nodig). 
 * AccelStepper::HALF3WIRE (6) betekent een 3 wire half stepper, zoals een harde schijf motor (3 pins nodig) 
 * AccelStepper::HALF4WIRE (8) betekent een 4 wire half stepper (4 pins nodig) 
 *
 * Standaard gebruikt AccelStepper de AccelStepper::FULL4WIRE (4 pins nodig).
 */
AccelStepper stepper(AccelStepper::HALF4WIRE, motorPin1, motorPin3, motorPin2, motorPin4);

void setup() {
  Serial.begin(9600);               // stel de seriële monitor in

  stepper.setMaxSpeed(1000.0);      // stel de maximale motorsnelheid in
  stepper.setAcceleration(100.0);   // stel de acceleratie in
  stepper.setSpeed(200);            // stel de huidige snelheid in
}

// Graden van bewegingen dus eerst naar 30 graden, dan naar -30 graden dan naar 60 graden etc.
int steps[] = { 30, -30, 60, -60, 0 };

// Het totaal aantal bewegingen in steps[]
int stepsCount = 5;

// Houdt bij welke positie van steps[] we gaan uitvoeren
int stepsIndex = 0;

void loop() {

  // Als de stepper niet beweegt en geen afstand meer hoeft af te leggen
  if (!stepper.isRunning() && stepper.distanceToGo() == 0) {

    // Beweeg de stepper naar het aantal graden op de positie stepIndex van steps[]
    stepper.moveTo(degToSteps(steps[stepsIndex]));

    // Verhoog de index als de beweging klaar is
    stepsIndex++;

    // Als we alle posities in steps[] gehad hebben
    if (stepsIndex > stepsCount) {

      // Begin overnieuw bij 0
      stepsIndex = 0;
    }
  }

  stepper.run();

}

/*
 * Rekent het aantal graden om naar het aantal stappen
 * In ons voorbeeld van 45 graden: 64 / 5,625 = 1024 stappen
 */
float degToSteps(float deg) {
  return (stepsPerRevolution / degreePerRevolution) * deg;
}