#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Arduino.h>
#include <Adafruit_I2CDevice.h>
#include <Adafruit_GFX.h>

// Set the LCD address to 0x27 in PCF8574 by NXP and Set to 0x3F in PCF8574A by Ti
LiquidCrystal_I2C lcd(0x27, 16, 2);
//点击发射篮球
#define touchPin 2

int Position = 0;//球的位置
//坤坤的位置
int KUN_Position_line = 0;
//坤坤
byte KUN[] = {
  B00000,
  B00110,
  B01110,
  B11111,
  B11111,
  B01111,
  B10010,
  B10001
};
//篮球
byte BALL[] = {
  B00000,
  B00000,
  B01110,
  B01110,
  B01110,
  B00000,
  B00000,
  B00000
};
//触摸
void touch(){
  if (digitalRead(touchPin) == HIGH)
  {
    //坤坤移动
    KUN_Position_line++;
 if(KUN_Position_line > 1){
     KUN_Position_line = 0;
  }
    /* code */
  }
//移动篮球 
}

void setup() {
  lcd.begin(0x27, 16, 2);
  lcd.init();
  lcd.backlight();
  lcd.createChar(0, KUN);
  lcd.createChar(1,BALL);
  lcd.home();
  lcd.write(0);
  
}
void loop() {
  //判断是否有触摸,触摸发射篮球
 if(digitalRead(touchPin)==HIGH){
  //如果点击次数超过1次，坤坤回到第一行
  touch();
   //按下之后坤坤上下移动
  Position++;
   if(Position > 16){
     Position = 0;
   }
   
  lcd.clear();
  lcd.setCursor(Position, KUN_Position_line);//坤坤移动是的光标
  lcd.write((byte)0);
   //球移动时的光标位置
  lcd.write((byte)1);
   
  delay(300);
 }
}

 
