#include <Arduino.h>
#include <pt.h>
#include <ss.h>
#include <cledm.h>

ss temp = ss();
cledm le = cledm();

static int autoRad_thread(struct pt *pt, int interval) {
  static unsigned long timestamp = 0;
  PT_BEGIN(pt);
  while(1) {
    PT_WAIT_UNTIL(pt, millis() - timestamp > interval );
    timestamp = millis();
    ss.autoRad();
  }
  PT_END(pt);
}

static int temp_thread(struct pt *pt, int interval) { // A finir
  static unsigned long timestamp = 0;
  PT_BEGIN(pt);
  while(1) {
    PT_WAIT_UNTIL(pt, millis() - timestamp > interval );
    timestamp = millis();
    float t = ss.getTemp();
  }
  PT_END(pt);
}

static int MLed_thread(struct pt *pt, int interval, int loc, int emp, int images) {
  static unsigned long timestamp = 0;
  PT_BEGIN(pt);
  while(1) {
    PT_WAIT_UNTIL(pt, millis() - timestamp > interval );
    timestamp = millis();
    le.DrawM(loc, emp, images);
  }
  PT_END(pt);
}
