/*
 * Bas on Tech - Arduino tutorial voltage sensor
 * https://arduino-lessen.nl
 * 
 * PIN AANSLUITINGEN SENSOR
 * 
 * S --> A3  groen
 * + --> 5V  rood
 * - --> GND blauw
 * 
 * Exacte waarden berekenen met multimeter:
 * 
 * Vin op adapter = 12.41V
 * Vout op Arduino = 2.497V
 * 5V op Arduino = 5.10V
 * 
 * Vin / vOut = factor
 * 12.41 / 2.497 = 4.97
 * 
 */

const int voltageSensorPin = 3;           // sensor pin
float vIn;                                // gemeten voltage (3.3V = max. 16.5V, 5V = max 25V)
float vOut;
float voltageSensorVal;                   // waarde op pin A0 (0 - 1023)
const float factor = 4.092;               // reductie factor van het Voltage Sensor shield
const float vCC = 5.00;                   // Arduino invoer voltage (na te meten met voltmeter)

void setup() {
  Serial.begin(9600);
}

void loop() {

  voltageSensorVal = analogRead(voltageSensorPin);    // lees de waarde van de sensor (0 - 1023) 
  vOut = (voltageSensorVal / 1023) * vCC;             // converteer de gelezen waarde naar het daadwerkelijke voltage op de analoge pin
  vIn =  vOut * factor;                               // converteer het voltage naar het voltage aan de bron door te vermenigvuldigen met de factor

  Serial.print("Voltage = ");             
  Serial.print(vIn);
  Serial.println("V");

  delay(1000);
}

