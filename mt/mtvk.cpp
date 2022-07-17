#include <M5StickC.h>
#define MT_KEYS "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz1234567890.:;?!/\\_-()[]% <"
#define MXLN 0xFF
#define TRM "-- "
#define VER "0.2"
#define SCHAR '#'
#define VPOS 52

void OPEN_MT(char* dest, char* TEXT) {
  //char c[strlen(MT_KEYS)]=MT_KEYS;
  //static int MXLN = sizeof(dest);
  int initRot = M5.Lcd.getRotation();
  int initCX = M5.Lcd.getCursorX();
  int initCY = M5.Lcd.getCursorY();
  char cc[MXLN];
  int c=0,stck=0,m=1;
  M5.Lcd.setTextSize(1);
  M5.Lcd.setRotation(3);
  //M5.Lcd.printf("\n%d:%d",M5.Lcd.getCursorX(),M5.Lcd.getCursorY());
  while(true) {
    //M5.update();
    char currChar = MT_KEYS[c];
    M5.Lcd.fillScreen(BLACK);
    M5.Lcd.setCursor(0,0);
    M5.Lcd.printf("Mt(c)virtual keyboard v%s\n%s",VER,TEXT);
    M5.Lcd.setCursor(0,VPOS/2);
    M5.Lcd.print(TRM);
    //if(cc[0]!='\0') {
      for(int i=0;i<strlen(cc);i++) {
        M5.Lcd.print(cc[i]);
      }
    //}
    M5.Lcd.setCursor(0,VPOS);
    for(int i=0;i<strlen(MT_KEYS);i++) {
      if(i==c){
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
        c--;break;
      }
      else if(M5.BtnA.pressedFor(500)) {
        if(c==strlen(MT_KEYS)-1) {
          if(stck!=0) {
            stck--;
            cc[stck]=0;m=0;
            delay(500);break;
          }
        }
        else {
          cc[stck]=currChar;
          stck++;m=0;
          delay(500);break;
        }
      }
      else if(M5.BtnB.pressedFor(1000)) {
        //if(!strlen(cc)>=0xFF+1) {
          //return "NULL";
        //} else {
        //if(!strlen(cc)>MXLN) {
          M5.Lcd.fillScreen(BLACK);
          M5.Lcd.setRotation(initRot);
          M5.Lcd.setCursor(initCX,initCY);
          /*for(int i=0;i<strlen(cc);i++) {
            dest[i]=cc[i];
          }*/
          //sprintf(dest,"%s",cc);
          strncpy(dest,cc,MXLN);
          return;
        /*} else {
          //sprintf(dest, "NULL");
          strncpy(dest,"NULL1",0xFF);
          return;
        }*/
      }
    }
    if(c==strlen(MT_KEYS)) {
      c=0;
    }
    else if(c<=-1) {
      c=strlen(MT_KEYS)-1;
    }
  }
  //sprintf(dest, "NULL");
  strncpy(dest,"NULL",MXLN);
}