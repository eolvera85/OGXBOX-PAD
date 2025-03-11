# OGXBOX-PAD USB Core for Arduino AVR

The files in this repository allow you to emulate an gamepad to Original Xbox using a USB-capable Arduino microcontroller.

## Installation

Follow the official instructions for [adding third party boards](https://support.arduino.cc/hc/en-us/articles/360016466340-Add-or-remove-third-party-boards-in-Boards-Manager) and [adding boards to the Arduino IDE](https://support.arduino.cc/hc/en-us/articles/360016119519-Add-boards-to-Arduino-IDE).

Add the following line to the "Additional Boards Manager URLs" list:
```
https://raw.githubusercontent.com/eolvera85/OGXBOX-PAD/main/releases/package_ogxbox_index.json
```
If you've done this correctly, the OGXBOX boards packages will be available within the Boards Manager. Install the "OGXBOX AVR Boards" package to add these boards to the IDE.

![alt text](images/ArduinoIDE.png?raw=true)

### How to Upload
Connect the board to your computer using a USB cable, and make sure you have the proper board selected in the IDE's 'boards' menu (with or without OGXBOX).

## Supported Boards
* [Adafruit Circuit Playground 32u4](https://www.adafruit.com/product/3000)
* [Arduino Esplora](https://store.arduino.cc/usa/arduino-esplora)
* [Arduino Industrial 101](https://store.arduino.cc/usa/arduino-industrial-101)
* [Arduino Leonardo](https://store.arduino.cc/usa/leonardo)
* [Arduino Leonardo ETH](https://store.arduino.cc/usa/arduino-leonardo-eth)
* [Arduino Micro](https://store.arduino.cc/usa/arduino-micro)
* [Arduino Robot Control / Motor](https://store.arduino.cc/usa/arduino-robot)
* [Arduino Yún](https://store.arduino.cc/usa/arduino-yun)
* [Arduino Yún Mini](https://store.arduino.cc/usa/arduino-yun-mini)
* [LilyPad Arduino USB](https://www.sparkfun.com/products/12049)
* [Linino One](https://store.arduino.cc/usa/linino-one)

Unfortunately boards such as the Uno, Nano, or Mega that do not have native USB support will *not* work.

Libraries used:
- [ogx360](https://github.com/Ryzee119/ogx360)

