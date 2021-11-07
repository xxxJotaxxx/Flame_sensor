#include <Arduino.h>

int led = 13;       // define the LED pin
int digitalPin = 2; // KY-026 digital interface
int analogPin = A0; // KY-026 analog interface
int digitalVal;     // digital readings
int analogVal;      //analog readings

void setup()
{
    pinMode(led, OUTPUT);
    pinMode(digitalPin, INPUT);
    Serial.begin(9600);
}

void loop()
{
    // Read the digital interface
    digitalVal = digitalRead(digitalPin);
    //Serial.print("digitalVal:");
    //Serial.println(digitalVal);

    if (digitalVal == HIGH) // if flame is detected
    {
        digitalWrite(led, HIGH); // turn ON Arduino's LED
    }
    else
    {
        digitalWrite(led, LOW); // turn OFF Arduino's LED
    }

    // Read the analog interface
    analogVal = analogRead(analogPin);
    //Serial.print("analogVal:");
    Serial.println(analogVal); // print analog value to serial, when value is slow the flame is detected
    //Serial.println("----------");

    delay(100);
}