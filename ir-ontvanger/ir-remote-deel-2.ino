/*
 * Bas on Tech - Arduino tutorial 8 - deel 2
 * http://basontech.nl
 * 
 * Originele code van:
 * http://arcfn.com door Ken Shirriff
 *
 */

// Importeer de IR-remote bibliotheek
#include <IRremote.h>

int IrReceiverPin = 12;                 // stel de variable "IrReceiverPin" in op pin 12
IRrecv irrecv(IrReceiverPin);           // maak een nieuwe instantie van "irrecv" en sla deze op in de variabele "IRrecv"
decode_results results;                 // definieer de variable "results" om de ontvangen knop-code in op te slaan

int speed = 100;

void setup()
{
    Serial.begin(9600);                 // Stel de seriële monitor in

    pinMode(LED_BUILTIN, OUTPUT);       // Initialiseer digitale pin LED_BUILTIN als een uitvoer

    // In case the interrupt driver crashes on setup, give a clue
    // to the user what's going on.

    // Mocht de IR-remote bibliotheek vastlopen dan kunnen we dit aan de getoonde tekst zien
    Serial.println("IR-ontvanger wordt gestart...");
    irrecv.enableIRIn();  // start de IR-ontvanger
    Serial.println("IR-ontvanger actief");

    digitalWrite(LED_BUILTIN, LOW);     // Zet de ingebouwde LED uit
}


void loop() {

    // Als de IR-ontvanger een signaal heeft ontvangen
    if (irrecv.decode(&results)) {

        // Print de ontvangen waarde als hexadecimaal        
        Serial.println(results.value, HEX);

        // Laat de IR-ontvanger luisteren naar nieuwe signalen
        irrecv.resume();
  
        // Bepaal welke knop is ingedrukt
        switch (results.value) {
            case 0xFF6897:     // knop 1
                speed = 100;   // stel de snelheid in op 100ms
                break;

            case 0xFF9867:     // knop 2
                speed = 500;   // stel de snelheid in op 500ms
                break;

            case 0xFFB04F:     // knop 3
                speed = 1000;  // stel de snelheid in op 1000ms
                break;        
        }

    }

    // Knipper de ingebouwde LED met de ingestelde snelheid
    digitalWrite(LED_BUILTIN, HIGH);
    delay(speed);

    digitalWrite(LED_BUILTIN, LOW);
    delay(speed);

}