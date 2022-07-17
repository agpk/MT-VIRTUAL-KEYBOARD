#include <M5StickC.h>
#include "mt/mtvk.h"

void setup() {
  M5.begin();
  char H[0xFF];
  OPEN_MT(H,"INPUT:");
  M5.Lcd.printf("%s",H);
}

void loop() {
  
}
