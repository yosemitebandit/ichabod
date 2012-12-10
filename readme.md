a quiet diary

### Hardware
This project uses 
an [Arduino Leonardo](http://arduino.cc/en/Main/arduinoBoardLeonardo),
an [OpenLog](https://www.sparkfun.com/products/9530),
a [real-time clock](https://www.sparkfun.com/products/99)
and a PS2 Keyboard.

See `src/ichabod.ino` for connection info.

### External libraries
We make use of [RTC](https://github.com/adafruit/RTClib/) from JeeLabs and adafruit
and a fork of [PS2Keyboard](https://github.com/yosemitebandit/PS2Keyboard).

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
