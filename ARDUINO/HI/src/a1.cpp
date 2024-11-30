#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <SPI.h>
#include <Adafruit_I2CDevice.h>

#define LCD_ADDRESS 0x27
#define TOUCH_PIN 2

LiquidCrystal_I2C lcd(LCD_ADDRESS, 16, 2);

void setup(){
  Serial.begin(9600);
  lcd.init();// initialize the lcd 初始化lcd
  lcd.backlight();//设置背光
  lcd.setCursor(0,0);
  lcd.print("please touch");

}
void loop(){
  int a = random(1,6);
  if(digitalRead(TOUCH_PIN) == HIGH){
    lcd.clear();
    lcd.print("NUMBER : ");
    lcd.print(a);
    delay(1000);
  }
}
