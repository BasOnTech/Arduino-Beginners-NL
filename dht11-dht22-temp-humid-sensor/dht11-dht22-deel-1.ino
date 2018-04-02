/*
 * Bas on Tech - DHT11 / DHT22
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
 * PIN AANSLUITINGEN DHT11 & DHT22
 *
 * Vcc  --> 3.3V
 * Data --> 12
 * NC
 * GND  --> GND
 *
 * 4K7 (4700) Ohm weerstand tussen 3.3V en Data pin
 *
 */

#include "DHT.h"             // Bibliotheek voor DHT sensoren

#define dhtPin 12            // data pin

/*
 * Stel hier in welke DHT chip je gebruikt
 */
#define dhtType DHT11        // DHT 11
//#define dhtType DHT22      // DHT 22  (AM2302), AM2321
//#define dhtType DHT21      // DHT 21 (AM2301)

DHT dht(dhtPin, dhtType);    // Initialiseer de DHT bibliotheek

float humidityVal;           // luchtvochtigheid
float tempValC;              // temperatuur in graden Celcius
float tempValF;              // temperatuur in graden Fahrenheit
float heatIndexC;            // gevoelstemperatuur in graden Celcius
float heatIndexF;            // gevoelstemperatuur in graden Fahrenheit

void setup() {
  Serial.begin(9600);        // stel de seriële monitor in
  dht.begin();               // start het DHT sensor uitlezen
}

void loop() {

  humidityVal = dht.readHumidity();        // vraag de luchtvochtigheid aan de DHT sensor
  tempValC = dht.readTemperature();        // vraag de temperatuur in graden Celcius aan de DHT sensor
  tempValF = dht.readTemperature(true);    // vraag de temperatuur in graden Fahrenheit aan de DHT sensor

  // Controleer of alle waarden goed zijn uitgelezen, zo niet probeer het opnieuw
  if (isnan(humidityVal) || isnan(tempValC) || isnan(tempValF)) {
    Serial.println("Uitlezen van DHT sensor mislukt!");

    // Beëindig de loop() functie
    return;
  }
  
  // Bereken de gevoelstemperatuur in graden Celcius
  heatIndexC = dht.computeHeatIndex(tempValC, humidityVal, false);

  // Bereken de gevoelstemperatuur in graden Fahrenheit
  heatIndexF = dht.computeHeatIndex(tempValF, humidityVal);

  // Print alle waarden naar de seriële monitor
  // \t print een tab
  Serial.print("Luchtvochtigheid: ");
  Serial.print(humidityVal);
  Serial.print(" %\t");

  Serial.print("Temperatuur: ");
  Serial.print(tempValC);
  Serial.print(" °C ");
  Serial.print(tempValF);
  Serial.print(" °F\t");

  Serial.print("Gevoelstemperatuur: ");
  Serial.print(heatIndexC);
  Serial.print(" °C ");
  Serial.print(heatIndexF);
  Serial.println(" °F");
  
  delay(2000);
}