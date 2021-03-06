
//               MTVK Library
//     Copyright (c) Alan Kubiak, 2022.
//
//  This project is under the GPLv3 license.
//           For the LLEC project.
//
//   --------------------------------------
//        Mt(c)Virtual Keyboard (MTVK)
//   --------------------------------------

#include <M5StickC.h>
#define MT_KEYS "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz1234567890+-*/%=()<>#@\". <"
#define TYPEC 500
#define MXLN 0xFF
#define TRM "-- "
#define VER "0.2"
#define SCHAR '#'
#define VPOS 52
char cc[MXLN];

void OPEN_MT(char* dest, char* TEXT) {
  int initRot=M5.Lcd.getRotation();
  int initCX=M5.Lcd.getCursorX();
  int initCY=M5.Lcd.getCursorY();
  int c=0,stck=0,m=1,e=0;
  M5.Lcd.setTextSize(1);
  M5.Lcd.setRotation(3);
  while(true) {
    M5.Lcd.fillScreen(BLACK);
    M5.Lcd.setCursor(0,0);
    M5.Lcd.printf("Mt(c)virtual keyboard v%s\n%s",VER,TEXT);
    M5.Lcd.setCursor(0,VPOS/2);
    M5.Lcd.print(TRM);
    for(int i=0;i<strlen(cc);i++) {
      M5.Lcd.print(cc[i]);
    }
    M5.Lcd.setCursor(0,VPOS);
    for(int i=0;i<strlen(MT_KEYS);i++) {
      if(i==c) {
        M5.Lcd.print(SCHAR);
      }
      else M5.Lcd.printf("%c",MT_KEYS[i]);
    }
    while(true) {
      M5.update();
      if(M5.BtnA.wasReleased()) {
        if(m) {
          c++;break;
        } else {
          m=1;
        }
      }
      else if(M5.BtnB.wasReleased()) {
        if(e) {
          c--;break;
        } else {
          e=1;
        }
      }
      else if(M5.BtnA.pressedFor(500)) {
        if(c==strlen(MT_KEYS)-1) {
          m=0;
          if(stck!=0) {
            stck--;
            cc[stck]=0;
            delay(TYPEC);break;
          }
        }
        else {
          cc[stck]=MT_KEYS[c];
          stck++;m=0;
          delay(TYPEC);break;
        }
      }
      else if(M5.BtnB.pressedFor(1000)) {
        M5.Lcd.fillScreen(BLACK);
        M5.Lcd.setRotation(initRot);
        M5.Lcd.setCursor(initCX,initCY);
        strcpy(dest,cc); // not secure
        memset(cc,0,sizeof(cc));
        delay(TYPEC);
        return;
      }
    }
    if(c==strlen(MT_KEYS)) {
      c=0;
    }
    else if(c<=-1) {
      c=strlen(MT_KEYS)-1;
    }
  }
  strcpy(dest,"NULL");
}
