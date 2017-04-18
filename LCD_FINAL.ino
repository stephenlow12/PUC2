/*
  Pushup Counter
  Stephen Low
  Wearable Computing GDES-3015-001
  OCAD University
  Created on April 13, 2017
  Based on:
  Mapping example, Kate Hartman, https://github.com/katehartman/Make-Wearable-Electronics/blob/master/MWE_Ch07_Mapping/MWE_Ch07_Mapping.ino
  Simple hit counter sketch for Arduino Uno, Cody Bonney, https://codybonney.com/simple-hit-counter-sketch-for-arduino-uno/
  "Hello World!", Arduino, https://www.arduino.cc/en/Tutorial/HelloWorld
*/

// initialize variable for sensor reading
int SensorValue = 0;
// initialize variable for sensor pin
int SensorPin = A1;
// initialize variable for mapped sensor value
int mappedSensorValue = 0;
int LEDPin = 13;
int prev = 0;
int threshold = 15

#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int a = 0;
int e = 7;

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("Push Ups");
  pinMode(e, INPUT);
}

void loop() {

  // read pin and store value in a variable:
  SensorValue = analogRead(SensorPin);

  // map sensor value to match relative distance range
  mappedSensorValue = map(SensorValue, 0, 1023, 30, 0);


  int button = digitalRead(e);


  lcd.setCursor(3, 1);
  lcd.print(a);

  //if button pressed, or if sensor is triggered below or equal to the threshold
  if (button == HIGH || mappedSensorValue <= threshold) {
    // add one
    a ++;
    // in LCD blocks (x, x)
    lcd.setCursor(3, 1);
    //printout value
    lcd.print(a);
    delay(200);
  }

  // if sensor value is between 15 and 21, with a value that is greating then the previous it plays the beep

  if (mappedSensorValue > threshold && mappedSensorValue < 21) {
    digitalWrite(LEDPin, HIGH);
    delay(500);
    digitalWrite(LEDPin, LOW);

  }

  // print the values to serial monitor:
  Serial.print("Sensor Value: ");
  Serial.print(SensorValue);
  Serial.print(", Mapped Sensor Value: ");
  Serial.print(mappedSensorValue);
  // delay between readings:
  delay(100);

}

