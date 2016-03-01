#include <Servo.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);

Servo myservo;
//調整平行角度
int stard = 50;
//休息時間上下限 ms
int breaktime= 30000;
//舵機輸出port
int pos = 10;
//隨機步數上下限
int minstep = 10;
int maxstep = 50;


void setup() {
  // put your setup code here, to run once:
  myservo.attach(pos);
  myservo.write(stard);
  delay(2000);
  lcd.begin();
  //lcd.backlight();
}

void loop() {
  // put your main code here, to run repeatedly:
  // set stard to servo
 // onestep(1000);
  slowwalk(random(minstep,maxstep));
  fastwalk(random(minstep,maxstep));
  gorun(random(minstep,maxstep)+30);
  slowwalk(random(minstep,maxstep));
  delay(breaktime);
}

void slowwalk(int step){
  lcd.clear();
  lcd.setCursor(1, 0);
  lcd.print("Slow:");
  lcd.setCursor(1, 1);
  lcd.print(step,DEC);
  int delaytime = 700;
  for(int i;i<=step;i++){
       onestep(delaytime);
  }
}
void fastwalk(int step){
  lcd.clear();
  lcd.setCursor(1, 0);
  lcd.print("Fast:");
  lcd.setCursor(1, 1);
  lcd.print(step,DEC);
  int delaytime = 500;
  for(int i;i<=step;i++){
       onestep(delaytime);
    }
}
void gorun(int step){
  lcd.clear();
  lcd.setCursor(1, 0);
  lcd.print("Run:");
  lcd.setCursor(1, 1);
  lcd.print(step,DEC);
  int delaytime = 400;
  for(int i;i<=step;i++){
       onestep(delaytime);
    }
}
void gobreaktime(int timee){
  lcd.clear();
  lcd.setCursor(1, 0);
  lcd.print("Breaktime: ms");
  lcd.setCursor(1, 1);
  lcd.print(timee,DEC);
  delay(timee);
}

void onestep(int delaytime){
  /*int i = stard;
  for(i;i>=stard-49;i--){
       myservo.write(i);
       delay(5);
    }
  delay(delaytime);
  for(i;i<=stard+49;i++){
       myservo.write(i);
       delay(5);
    }
  delay(delaytime);
  for(i;i>=stard;i--){
       myservo.write(i);
       delay(5);
    }*/
  
    myservo.write(stard - 31);
    delay(delaytime);
    myservo.write(stard);
    delay(delaytime);
    myservo.write(stard + 31);
    delay(delaytime);
    myservo.write(stard);
    delay(delaytime);
}


