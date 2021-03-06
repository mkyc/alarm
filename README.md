# Purpose

Purpose of this project is to create simple home monitoring based on Arduino Micro, SIM800L board and PIR sensors. I want to be able to feed MQTT server topics constantly with data from PIR sensors and in case of "alarm" situation I will ... I don't really know what then, but with GSM/GPRS module already in place I can easily send text to myself at least.

# Plan

 * PIR sensors connected to arduino
 * Arduino sends data to serial every couple seconds
 * Arduino is connected to RaspberryPi
 * there is systemd service running in RPi receiving data and saving it to some queue
 * there is some queue
 * there is some another systemd service reading from queue and pushing messages to remote MQTT 
 * and there is another systemd service reading from queue and sending message to user

# Inspirations

First inspiration was apartment with "abandoned" alarm installation I've seen. I was wondering how it's built since previous service provider left whole infrastructure in place, and just removed communication module. Then in order following resources were useful:

* When I started to dig through internet I found [this](https://www.enigma14.eu/wiki/5V_UPS_for_Raspberry_Pi) article describing how to utilise 12V battery which was part of infrastructure left in "abandoned" alarm installation.
* Then I found [this](https://www.pushsafer.com/en/pushapi#api-read) app allowing to send push notification to your phone.
* The original article was describing installation with Raspberry Pi, but after some more research I decided I'll go with Arduino Micro (which I have multiple spare copies in my treasures box) so [this](https://content.arduino.cc/assets/Pinout-Micro_latest.pdf) piece of documentation is obvious help when working with this project.
* Since I've never played with MQTT before [this awesome list](https://github.com/hobbyquaker/awesome-mqtt) was pretty useful to have some impression about available resources.
* [This section of article](https://lastminuteengineers.com/sim800l-gsm-module-arduino-tutorial/#wiring-sim800l-gsm-module-to-arduino-uno) was very useful when connecting SIM800L module to Arduino Micro. One worth noticing that for Micro you should change pins due to [Limitations section here](https://www.arduino.cc/en/Reference/softwareSerial).
* Also [pins description](https://forum.arduino.cc/index.php?topic=525769.0) for SIM800L module was useful. [This one](https://www.electroschematics.com/introducingsim800l/) I used to set logic level voltages.
* Since I needed to lower 5V to 3.3V I had to ensure that I do it correctly with [picture from this Quora topic](https://www.quora.com/How-many-pins-on-Arduino-Uno-give-a3-3v-pin-output). I also found [this calculator](http://www.learningaboutelectronics.com/Articles/Voltage-divider-calculator.php) useful.
