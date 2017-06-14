# TempMonitor
NodeMCU temperature monitor for beer fermentors

- open source IoT platform based on Esp8266 
- default firmware uses the Lua scripting language but you could flash it and use javascript if need it 
- really cheap programmable microcontroller
- fun to play with
- lot of sendors available (all the arduino sensors can be attached to this)

Fermentor1 channel
https://thingspeak.com/channels/229922


Demo channel
https://thingspeak.com/channels/287687


##### Whats next:


i plan to attach 2 relays :
1. when the temp is too low the first relay will be open and that will power an elecric belt to heat up the fermentor and while the relay is on the sensor will do a pooling to check if temp == desired temp and then stop the heating
2. more complicated when temp is too high relay is on that power a water pump that start circulating ice cold water + glycol around the fermentor in order to lower the temp. First ideea was to use a peltier element for this.


##### More Info

- http://www.instructables.com/ search for nodeMcu or esp8266 lot of projects
- 37 sensors kit - https://youtu.be/Vn9XsLh13qw?list=PLwnMi_b_qu7vx6f608858Q0LxaSahfXau


##### ESP8266 
- 32-bit RISC CPU: Tensilica Xtensa L106 running at 80 MHz*
- 64 KiB of instruction RAM, 96 KiB of data RAM
- External QSPI flash: 512 KiB to 4 MiB* (up to 16 MiB is supported)
- IEEE 802.11 b/g/n Wi-Fi
- Integrated TR switch, balun, LNA, power amplifier and matching network
- WEP or WPA/WPA2 authentication, or open networks
- 16 GPIO pins
- SPI
- I²C
- I²S interfaces with DMA (sharing pins with GPIO)
- UART on dedicated pins, plus a transmit-only UART can be enabled on GPIO2
- 10-bit ADC
