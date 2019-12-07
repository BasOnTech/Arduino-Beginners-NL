/*
 * Bas on Tech - Stappen motor
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
float degreePerRevolution = 5.625;  // graden per stap

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

  stepper.moveTo(degToSteps(90));   // geef motor instructie  om de motor 90 graden vooruit te bewegen

}

void loop() {
  stepper.run();                    // start de beweging van de motor  
}

/*
 * Rekent het aantal graden om naar het aantal stappen
 * 
 * 28BYJ-48 motor heeft 5,625 graden per stap
 * 360 graden / 5,625 = 64 stappen per omwenteling
 * 
 * Voorbeeld van degToSteps(45):
 * (64 / 5,625) * 45 = 512 stappen
 */
float degToSteps(float deg) {
  return (stepsPerRevolution / degreePerRevolution) * deg;
}
