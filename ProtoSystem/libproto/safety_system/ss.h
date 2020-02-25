// Safety system de la suit (Gestion de la température et de la vitesse du ventilateur)

#include "Arduino.h"

#ifndef ss__RELEASE
#define ss_RELEASE

class ss {
public:
    ss();
    getTemp();
    setRad(bool volt);
    autoRad(bool stat);

private:
  bool volt;
  bool stat;
};

#endif // ss_RELEASE
