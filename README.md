MQTT
====

A Wrapper around mqtt for Arduino to be used with esp8266 modules.

It wraps a slightly modified version of mqtt for esp8266 ported by Tuan PM.
Original code for esp: https://github.com/tuanpmt/esp_mqtt
Original code for contiki: https://github.com/esar/contiki-mqtt


====

libssl:

This library links to libssl. libssl is not in the linker flags by default and has to be added manually.

In the file "hardware/esp8266com/esp8266/platform.txt" add -lssl to the line starting with: compiler.c.elf.libs so that it looks like this:
compiler.c.elf.libs=-lm -lgcc -lhal -lphy -lnet80211 -llwip -lwpa -lmain -lpp -lsmartconfig -lwps -lcrypto -lssl

If the esp8266 boards has been added via the Arduino board manager you find "platform.txt" here:
OSX: ~/Library/Arduino15/packages/esp8266/hardware/esp8266/version/platform.txt
Windows: C:\Users\*username*\AppData\Romaning\Arduino15\packages\esp8266\hardware\esp8266\version\platform.txt
Linux: ??