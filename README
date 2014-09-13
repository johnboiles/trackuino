Trackuino
=========
Firmware to turn your Arduino into an APRS tracker. This is a fork of the [original mercurial repo](http://code.google.com/p/trackuino) by EA5HAV Javi.

Board support
-------------
Arduinos based on ATmega328 (e.g. Uno), ATmega32u4 (e.g. Arduino Leonardo), and chipKIT Uno32 are supported. Here are a couple PCB designs that work with this firmware:

* [Official Trackuino Shield](https://code.google.com/p/trackuino/wiki/TrackuinoShield22)
* [TinyTrackuino](https://github.com/johnboiles/tinytrackuino)

Building with the Arduino IDE
-----------------------------

1. Open `trackuino/trackuino.ino`
2. Locate the `config.h` tab and replace settings with your own (`S_CALLSIGN`, `APRS_COMMENT`, etc).
3. Select the appropriate board for your hardware setup
4. Click Upload

On ATmega328 and other boards with only a single serial port, make sure to unplug the GPS when uploading or flashing will fail with an error.

Building at the command line
----------------------------
A makefile is included for easy building and uploading outside the Arduino IDE. The `BOARD` environment variable needs to be specified so the makefile can know what board to compile for. For boards not included in the official Arduino IDE, you can set `BOARDSPATH` to point at a directory that has details about the board.

For example, for an Arduino UNO (included in the Arduino IDE)

    BOARD=uno make upload

Or for a Sparkfun ProMicro 5V/16MHz board (assuming Sparkfun boards are installed in `~/Documents/Arduino/hardware`)

    BOARD=promicro16 BOARDSPATH=~/Documents/Arduino/hardware/sf32u4_boards make upload
