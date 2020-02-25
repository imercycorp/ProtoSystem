#include "Arduino.h"
#include "define_cos.cpp"
#include "ss.h"

ss:ss {}

ss:getTemp(){
  tmp_v = analogRead(SS_TEMP);
  float tmp_t = tmp_v * 5.0;
  tension /= 1024.0;
  float temp = ((tmp_t * 1000) - 500 ) / 10;
  return temp;
}

ss:setRad(bool volt){
  digitalWrite(SS_RAD, volt);
}

ss:autoRad(){
    float t = ss:getTemp();
    if (t >= SS_VIT_T + 1){
      digitalWrite(SS_RAD, HIGH);
    } else if (t <= SS_VIT_T){
      digitalWrite(SS_RAD, LOW)
    }
}
