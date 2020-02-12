#include "Arduino.h"

#ifndef cledm__RELEASE
#define cledm_RELEASE

class cledm {
public:
    cledm();

    void DrawM(int loc, int emp, int images);

private:
    String loc;
    int images;
    String emp;
};

#endif // cledm_RELEASE

