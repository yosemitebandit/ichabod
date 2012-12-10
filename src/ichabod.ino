/*
ichabod.ino

takes keystrokes from a PS2 keyboard 
and writes them to OpenLog (serial comms)
things are timestamped via an RTC (I2C)

keyboard connections:
    5V and GND
    CLK (IRQ) on pin 0
    DATA on pin 9

RTC connections:
    5V and GND
    SDA to pin D2
    SCL to pin D3

OpenLog connections:
    5V and GND
    TX to pin 11
    RX to pin 12

*/

#include <SoftwareSerial.h>
#include <Wire.h>
#include "RTClib.h"
#include "PS2Keyboard.h"

SoftwareSerial cereal(11, 12);  // RX, TX
RTC_DS1307 RTC;
PS2Keyboard keyboard;

const int DataPin = 9;
const int IRQPin = 0;


void setup() {
    delay(1000);
    keyboard.begin(DataPin, IRQPin);
    Serial.begin(9600);
}

void loop() {
    if (keyboard.available()) {
        char c = keyboard.read();

        Serial.print(c);
    }

}
