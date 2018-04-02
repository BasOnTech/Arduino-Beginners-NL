/*
 * Bas on Tech - Rotary encoder
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
 * Meer informatie over Rotary Encoder: 
 *   https://nl.wikipedia.org/wiki/Encoder
 *   https://en.wikipedia.org/wiki/Rotary_encoder
 *
 * Meer informatie over interrupts:
 *   https://www.arduino.cc/reference/en/language/functions/external-interrupts/attachinterrupt/
 *
 *
 * PIN AANSLUITINGEN
 *
 * GND --> GND zwart
 *  +  --> 5V  rood
 * SW  --> 12  geel
 * DT  --> 3   groen (data)
 * CLK --> 2   blauw (clock)
 *
 */

int switchPin = 12;                        // drukknop pin
int switchState = HIGH;                    // waarde van de drukknop

volatile int pinA = 2;                              // Rotary encoder Pin A
int pinB = 3;                                       // Rotary encoder Pin B
volatile int pinAstateCurrent = LOW;                // Huidige staat van Pin A
volatile int pinAStateLast = pinAstateCurrent;      // Laatst gelezen staat van Pin A

void setup() {
  Serial.begin (9600);                     // Stel de seriële monitor in

  pinMode (switchPin, INPUT_PULLUP);       // Stel de switchPin in als invoer met ingebouwde PULLUP weerstand

  pinMode(pinA, INPUT);                    // Stel pinA in als invoer

  // Koppel een interrupt op PinA voor als deze veranderd (CHANGE) en voer de update functie
  // uit als deze verandering plaatsvindt.
  attachInterrupt(digitalPinToInterrupt(pinA), update, CHANGE);
  
  pinMode (pinB, INPUT);                   // Stel de pinB in als invoer
  
}

void loop() {

  // DRUKKNOP
  switchState = digitalRead(switchPin);    // Lees de digitale waarde van de schakelaar (LOW/HIGH)

  // Als de schakelaar is ingedrukt (LOW), print bericht
  if (switchState == LOW) {
      Serial.println("Schakelaar ingedrukt");
  } 
  
}

void update() {

  /* LET OP: voor illustratieve doeleinden heb ik in deze interrupt functie gebruik gemaakt van Serial.println
   * Omdat de Serial bibliotheek zelf ook gebruikt maakt van interrupts kan dit problemen geven.
   * Maak daarom in je eigen projecten geen gebruik van Serial functies in interrupt functies
   */

  // ROTATIE RICHTING
  pinAstateCurrent = digitalRead(pinA);    // Lees de huidige staat van Pin A
  
  // Als er minimaal 1 tik gedraaid is
  if ((pinAStateLast == LOW) && (pinAstateCurrent == HIGH)) {
    
    if (digitalRead(pinB) == HIGH) {       // Als Pin B vervolgens HIGH is
      Serial.println("Links");             // Print op scherm
    } else {
      Serial.println("Rechts");            // Print op scherm
    }
    
  }
  
  pinAStateLast = pinAstateCurrent;        // Stel de laatst gelezen staat in op de huidige staat

}