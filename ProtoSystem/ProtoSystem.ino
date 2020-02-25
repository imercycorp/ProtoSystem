///
/// @mainpage	ProtoSystem
///
/// @details	System Protogen Version 2
/// @n
/// @n
/// @n @a		Developed with [embedXcode+](https://embedXcode.weebly.com)
///
/// @author		Hugo Chassaing
/// @author		iMercy
/// @date		12/02/2020 10:13
/// @version	<#version#>
///
/// @copyright	(c) Hugo Chassaing, 2020
/// @copyright	All rights reserved
///
/// @see		ReadMe.txt for references
///


///
/// @file		ProtoSystem.ino
/// @brief		Main sketch
///
/// @details	<#details#>
/// @n @a		Developed with [embedXcode+](https://embedXcode.weebly.com)
///
/// @author		Hugo Chassaing
/// @author		iMercy
/// @date		12/02/2020 10:13
/// @version	<#version#>
///
/// @copyright	(c) Hugo Chassaing, 2020
/// @copyright	All rights reserved
///
/// @see		ReadMe.txt for references
/// @n
///

#include "Arduino.h"
#include "threading.cpp"
#include "nexus.h"

int PSerial = 0
int RSerial = 0

Nexus n = Nexus();

void setup()
{
  PT_INIT(&tmp_t);
  PT_INIT(&autoRad_t);
  PT_INIT(&MLed_t);
  n.Link();
}
void loop()
{
  struct b = n.Receive();
  struct b t;
  autoRad_thread(&autoRad_t, 500);
  temp_thread(&tmp_t, 500);
  if (t.PInfo == "N"){

  } else {
    PSerial = PInfo.toInt()
    RSerial = PInfo.toInt()
  }
  if (PSerial == 1) {

  }
}
