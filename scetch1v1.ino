// Uses a PIR sensor to detect movement, buzzes a buzzer
// more info here: http://blog.makezine.com/projects/pir-sensor-arduino-alarm/
// 
// based upon:
// PIR sensor tester by Limor Fried of Adafruit
// tone code by michael@thegrebs.com

#include <Wire.h>
#include "rgb_lcd.h"

rgb_lcd lcd;
 
int ledPin = 7;                // choose the pin for the LED
int inputPin = 2;               // choose the input pin (for PIR sensor)
int pirState = LOW;             // we start, assuming no motion detected
int val = 0;                    // variable for reading the pin status
int pinSpeaker = 8;           //Set up a speaker on a PWM pin (digital 9, 10, or 11)
int fishCounter = 0;

void setup() {
  pinMode(ledPin, OUTPUT);      // declare LED as output
  pinMode(inputPin, INPUT);     // declare sensor as input
  pinMode(pinSpeaker, OUTPUT);
  Serial.begin(9600);
  lcd.begin(16, 2);
  
}

void loop()
{
  
  val = digitalRead(inputPin);  // read input value
  if (val == HIGH) 
  {            // check if the input is HIGH
    lcd.clear();
    digitalWrite(ledPin, HIGH);  // turn LED ON
    //playTone(300, 160);
     fishCounter ++;
      lcd.print("Fish: ");
      lcd.print(fishCounter);
      delay(3000);
      digitalWrite(ledPin, LOW); 
      
      if (fishCounter == 2)
      { 
        lcd.clear();
        delay(300);
        digitalWrite(ledPin, LOW); 
        lcd.print("Reset: ");
        playTone(1500, 160);
      }
  }  
  while(1) {lcd.print("Reset: "); }
}
// duration in mSecs, frequency in hertz
void playTone(long duration, int freq) {
    duration *= 1000;
    int period = (1.0 / freq) * 1000000;
    long elapsed_time = 0;
    while (elapsed_time < duration) {
        digitalWrite(pinSpeaker,HIGH);
        delayMicroseconds(period / 2);
        digitalWrite(pinSpeaker, LOW);
        delayMicroseconds(period / 2);
        elapsed_time += (period);
    }

    lcd.clear();
    
}
