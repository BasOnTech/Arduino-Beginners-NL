 /*
  * Bas on Tech - Arduino (funduino) Joystick Shield
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
  * NOKIA 5110 DISPLAY PIN LAYOUT
  * 
  * RST                Reset
  * CE/CS/CSE          Chip Enable / Chip Select
  * DC                 Data/Command selection (HIGH = data, LOW = command)
  * DIN/DN/MOSI/DATA   Data in
  * CLK/SCLK/SCK       Clock
  * VCC                2.7V - 3.3V
  * LED/LIGHT          Backlight
  * GND                Ground
  * 
  * 
  * PROBLEMEN OPLOSSEN
  * 
  * Mogelijke problemen als de joystick shield schakelaar op 3.3V staat ipv 5V:
  * - De joystick drukknop werkt niet
  * - De joystick waarden liggen tussen 0 en 659 ipv 0 en 1023
  * 
  * 
  */

//// DISPLAY ////

// Bibliotheek voor Nokia 5110 scherm met PCD8544 controller
#include <Adafruit_PCD8544.h>

// Bibliotheek voor teken functies
#include <Adafruit_GFX.h>

// Defineer Nokia 5110 display pins
#define RST 12
#define CE  13
#define DC  11
#define DIN 10
#define CLK  9

// Initialiseer de Adafruit PC8544 bibliotheek (Nokia 5110 scherm gebruikt PC8544 controller)
Adafruit_PCD8544 display = Adafruit_PCD8544(CLK, DIN, DC, CE, RST);

//// BUTTONS ////

// Pin definitie voor knoppen
const byte pinButtonA = 2;
const byte pinButtonB = 3;
const byte pinButtonC = 4;
const byte pinButtonD = 5;
const byte pinButtonE = 6;
const byte pinButtonF = 7;
const byte pinButtonK = 8;


//// JOYSTICK ////
const byte pinX = A0;
const byte pinY = A1;

int xDirection = 0;
int yDirection = 0;

void setup() {

  Serial.begin(9600);

  // Display
  display.begin();

  // Knoppen
  pinMode(pinButtonA, INPUT_PULLUP);
  pinMode(pinButtonB, INPUT_PULLUP);
  pinMode(pinButtonC, INPUT_PULLUP);
  pinMode(pinButtonD, INPUT_PULLUP);
  pinMode(pinButtonE, INPUT_PULLUP);
  pinMode(pinButtonF, INPUT_PULLUP);
  pinMode(pinButtonK, INPUT_PULLUP);
}

// Tekent een knop een x en y positie
// active geeft aan of the knop ingedrukt is
// label is de letter op de knop
void drawButton(int x, int y, bool active, char label) {

  // Knop cirkel
  if (active)   {
    display.fillCircle(x, y, 5, BLACK);
  } else {
    display.drawCircle(x, y, 5, BLACK);
  }

  // Knop label
  display.setCursor(x - 2, y - 3);
  display.setTextColor(active ? WHITE : BLACK);
  display.println(label);
}

void loop() {

  // Maak scherm leeg
  display.clearDisplay();

  // Teken de knoppen
  drawButton(65,  5, digitalRead(pinButtonA) == LOW, 'A');
  drawButton(75, 15, digitalRead(pinButtonB) == LOW, 'B');
  drawButton(65, 25, digitalRead(pinButtonC) == LOW, 'C');
  drawButton(55, 15, digitalRead(pinButtonD) == LOW, 'D');

  drawButton(50, 40, digitalRead(pinButtonE) == LOW, 'E');
  drawButton(35, 40, digitalRead(pinButtonF) == LOW, 'F');

  // Lees waarden van joystick uit (0-1023)
  xDirection = analogRead(pinX);
  yDirection = analogRead(pinY);

  // Teken de joystick

  // Bereken de positie van de joystick in een 30x30 vierkant

  // Het vierkant loopt van 0-30 pixels, de joystick schaal is 0-1023.
  // 30 / 1023 = 0.0293
  int x = xDirection * 0.0293; 
  int y = yDirection * 0.0293;

  // Als de joystick knop is ingedrukt
  if (digitalRead(pinButtonK) == LOW) {

    // Teken zwart vierkant met witte cirkel
    display.fillRect(0, 0, 31, 31, BLACK);
    display.fillCircle(x, 30 - y, 1, WHITE); 
  } else {

    // Teken wit vierkant met zwarte cirkel
    display.drawRect(0, 0, 31, 31, BLACK);
    display.fillCircle(x, 30 - y, 1, BLACK);
  }

  //  int x = 15 + 15 * cos((45 * 3.14 / 180));
  //  int y = 15 + 15 * sin((45 * 3.14 / 180));
  //
  //  if (digitalRead(pinButtonK) == LOW) {
  //    display.fillCircle(15, 15, 15, BLACK);
  //  } else {
  //    display.drawCircle(15, 15, 15, BLACK);
  //  }
  //  display.drawLine(15, 15, x, y, BLACK);

  // Teken display
  display.display();

  delay(200);
  
}