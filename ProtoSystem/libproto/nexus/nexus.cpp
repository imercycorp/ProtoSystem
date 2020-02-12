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

String Nexus::Receive(){

    while(SerialP.available()) {
        delay(10);
        return SerialP.readStringUntil('p') ;
    }
    return "[ERR - 01000] Nothing To Receive";

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
