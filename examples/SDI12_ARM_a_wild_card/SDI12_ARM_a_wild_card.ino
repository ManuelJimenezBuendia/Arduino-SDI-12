/*
  Modified 2017 Manuel Jimenez to work with Arduino Zero (SDI12_ARM library)
  
  Example A: Using the wildcard.

  This is a simple demonstration of the SDI-12 library for Arduino.
  It requests information about the attached sensor, including its address and manufacturer info.

  The SDI-12 specification is available at: http://www.sdi-12.org/
  The library is available at: https://github.com/StroudCenter/Arduino-SDI-12

  The circuit: You should not have more than one SDI-12 device attached for this example.

  See:
  https://raw.github.com/Kevin-M-Smith/SDI-12-Circuit-Diagrams/master/basic_setup_no_usb.png
  or
  https://raw.github.com/Kevin-M-Smith/SDI-12-Circuit-Diagrams/master/compat_setup_usb.png

  Written by Kevin M. Smith in 2013.
  Contact: SDI12@ethosengineering.org
*/


#include <SDI12_ARM.h>  // this is the modified library by MJB to work with ARM processors
// and ARM ones using interrupt enabled pins

#define DATAPIN 7         // change to the proper pin: https://www.arduino.cc/en/Reference/AttachInterrupt
// Leonardo: 0, 1, 2, 3, 7
// Uno, Nano, Mini, other 328-based: 2, 3
// Zero: all except 4
SDI12 mySDI12(DATAPIN);
/*
  '?' is a wildcard character which asks any and all sensors to respond
  'I' indicates that the command wants information about the sensor
  '!' finishes the command
*/
String myCommand = "?I!";

void setup() {
  Serial.begin(9600);
  while (!Serial);  // Waits for serial available
  mySDI12.begin();

}

void loop() {

  mySDI12.sendCommand(myCommand);

  delay(500);                     // wait a while for a response

  while (mySDI12.available()) {  // write the response to the screen
    Serial.write(mySDI12.read());
  }
  delay(1000); // print again in one second
}




