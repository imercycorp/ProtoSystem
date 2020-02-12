#ifndef Nexus_h
#define Nexus_h

#include "Arduino.h"
#include "SoftwareSerial.h"

class Nexus
{
  public:
    Nexus();
    String Send(String data);
    String Receive();
    void Link();
    bool Compare(String valAtt);
  private:
    String data;
    String valAtt;
};

#endif
