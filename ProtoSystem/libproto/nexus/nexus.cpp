#include "Arduino.h"
#include "nexus.h"
#include "SoftwareSerial.h"

String readString;
SoftwareSerial SerialP = SoftwareSerial(1,0);

//Function start
Nexus::Nexus() {
}

void Nexus::Link(){
    SerialP.begin(57600);
}

String Nexus::Send(String data){
	SerialP.print(data);
	return "OK";
}

struct Nexus::Receive(){
    struct ReceiveData {
      String PInfo = "N";
      String RInfo = "N";
    }
    struct ReceiveData t;
    while(SerialP.available()) {
        delay(10);
        t.PInfo = SerialP.readStringUntil('p');
        t.RInfo = SerialP.readStringUntil('r');
        return ReceiveData;
    }
    return ReceiveData;

}

bool Nexus::Compare(String valAtt) {
    while(SerialP.available()) {
        delay(10);
        String c = SerialP.readString();
        readString += c;
    }

    if (readString.equals(valAtt)) {
        return true;
    } else
    {
        return false;
    }

}
