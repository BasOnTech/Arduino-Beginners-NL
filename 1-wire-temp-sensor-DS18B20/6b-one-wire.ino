// Bas on Tech - Arduino tutorial 6b
// https://arduino-lessen.nl

// Importeer de benodigde bibliotheken
#include <OneWire.h>
#include <DallasTemperature.h>

float temp = 0.0;                       // variabele om temperatuur in op te slaan (float is getal met komma)
int oneWireBus = 12;                    // 1-wire pin
OneWire oneWire(oneWireBus);            // 1-wire instantie op de oneWireBus pin
DallasTemperature sensors(&oneWire);    // geef de instantie van de oneWire bus door aan de DallasTemperature

void setup(void) {
    
    pinMode(LED_BUILTIN, OUTPUT);       // Initialiseer digitale pin LED_BUILTIN als een uitvoer 
    digitalWrite(LED_BUILTIN, LOW);     // Zorg dat de LED aan het begin van het programma "uit" staat

    Serial.begin(9600);                   // stel de seriële monitor in 
    Serial.println("Bas on Tech - 1-wire temperatuur sensor"); // toon bericht op seriële monitor
    sensors.begin();                      // begin met het uitlezen van de sensor
}

void loop(void) { 
    sensors.requestTemperatures();          // lees de temperatuur sensor uit
    temp = sensors.getTempCByIndex(0);      // haal temperatuur in Celcius op van eerste sensor
    Serial.print("Temperatuur is: ");       // toon bericht op seriële monitor op zelfde regel
    Serial.println(temp);

    if (temp > 21) {                        // controleer of temperatuur warmer is dan 21 graden
        digitalWrite(LED_BUILTIN, HIGH);    // als de temperatuur warmer is dan 21 graden zet LED aan
    } else {
        digitalWrite(LED_BUILTIN, LOW);     // als de temperatuur niet warmer is dan 21 graden zet LED uit
    }

    delay(1000);                            // pauzeer 1000ms / 1 seconde
}
