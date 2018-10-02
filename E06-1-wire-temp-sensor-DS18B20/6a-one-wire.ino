 /*
  * Bas on Tech - 1-wire temperatuursensor
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

// Importeer de benodigde bibliotheken
#include <OneWire.h>
#include <DallasTemperature.h>

float temp = 0.0;                       // variabele om temperatuur in op te slaan (float is getal met komma)
int oneWireBus = 12;                    // 1-wire pin
OneWire oneWire(oneWireBus);            // 1-wire instantie op de oneWireBus pin
DallasTemperature sensors(&oneWire);    // geef de instantie van de oneWire bus door aan de DallasTemperature

void setup(void) {
    Serial.begin(9600);                   // stel de seriële monitor in 
    Serial.println("Bas on Tech - 1-wire temperatuur sensor"); // toon bericht op seriële monitor
    sensors.begin();                      // begin met het uitlezen van de sensor
}

void loop(void) { 
    sensors.requestTemperatures();          // lees de temperatuur sensor uit
    temp = sensors.getTempCByIndex(0);      // haal temperatuur in Celcius op van eerste sensor
    Serial.print("Temperatuur is: ");       // toon bericht op seriële monitor op zelfde regel
    Serial.println(temp); 
    delay(1000);                            // pauzeer 1000ms / 1 seconde
}
