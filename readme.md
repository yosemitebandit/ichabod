a quiet diary

### Hardware
This project uses 
an [Arduino Leonardo](http://arduino.cc/en/Main/arduinoBoardLeonardo),
an [OpenLog](https://www.sparkfun.com/products/9530),
a [real-time clock](https://www.sparkfun.com/products/99)
and a PS2 Keyboard.

See `src/ichabod.ino` for connection info.

### External libraries
I forked the [PS2Keyboard](https://github.com/yosemitebandit/PS2Keyboard) lib from PJRC to get it working with the Leonardo.
I'm also using the [RTC](https://github.com/adafruit/RTClib/) lib from JeeLabs and adafruit.

### Running
first time before you run, pull down the RTC submodule:
```
$ git submodule init
$ git submodule update
```

To run the code I presume you could use the Arduino IDE.
I like using [`ino`](https://github.com/amperka/ino) at the command line:

```
$ ino clean
$ ino build
$ ino upload
```
