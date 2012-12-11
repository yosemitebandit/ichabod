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

    // PS2Keyboard
    keyboard.begin(DataPin, IRQPin);

    // RTC's TWI
    Wire.begin();
    RTC.begin();

    // OpenLog's serial interface
    // preconfigured to this baud rate by editing config.txt on the sd card
    cereal.begin(57600);

    // Serial debug
    Serial.begin(9600);

    // set the RTC to the date and time of sketch compilation
    if (!RTC.isrunning()) {
        RTC.adjust(DateTime(__DATE__, __TIME__));
    }
}


String formatted_time() {
    // returns the time formatted like so: 12/11/12 0:32:9
    DateTime now = RTC.now();

    String result;
    result += now.year();
    result += '/';
    result += now.month();
    result += '/';
    result += now.day();
    result += ' ';
    result += now.hour();
    result += ':';
    result += now.minute();
    result += ':';
    result += now.second();

    return result;
}


void loop() {
    if (keyboard.available()) {
        // read and print keys
        char c = keyboard.read();
        Serial.print(c);

        // print the time to the terminal if 't' is pressed
        if (c == 't') {
            String now = formatted_time();
            Serial.print(now);
        }

        // write the time to a file if 'f' is pressed
        if (c == 'f') {
            String now = formatted_time();
            cereal.print(now);
        }

    }

}
