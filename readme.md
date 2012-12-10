a quiet diary

### hardware
See `src/ichabod.ino` for connections.

* an [Arduino Leonardo](http://arduino.cc/en/Main/arduinoBoardLeonardo)
* an [OpenLog](https://www.sparkfun.com/products/9530)
* a [real-time clock](https://www.sparkfun.com/products/99)
* a PS2 Keyboard

### external libraries

* [PS2Keyboard](http://www.pjrc.com/teensy/td_libs_PS2Keyboard.html) from PJRC
* [RTC](https://github.com/adafruit/RTClib/) from JeeLabs and adafruit

### running
I think you could use the Arduino IDE.
I like using [`ino`](https://github.com/amperka/ino) at the command line:

```
$ ino clean
$ ino build
$ ino upload
```
