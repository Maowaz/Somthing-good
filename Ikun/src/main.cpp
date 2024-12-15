#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Arduino.h>
#include <Adafruit_I2CDevice.h>
#include <Adafruit_GFX.h>

// Set the LCD address to 0x27 in PCF8574 by NXP and Set to 0x3F in PCF8574A by Ti
LiquidCrystal_I2C lcd(0x27, 16, 2);
//�����������
#define touchPin 2

int Position = 0;//���λ��
//������λ��
int KUN_Position_line = 0;
//����
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
//����
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
//����
void touch(){
  if (digitalRead(touchPin) == HIGH)
  {
    //�����ƶ�
    KUN_Position_line++;
 if(KUN_Position_line > 1){
     KUN_Position_line = 0;
  }
    /* code */
  }
//�ƶ����� 
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
  //�ж��Ƿ��д���,������������
 if(digitalRead(touchPin)==HIGH){
  //��������������1�Σ������ص���һ��
  touch();
   //����֮�����������ƶ�
  Position++;
   if(Position > 16){
     Position = 0;
   }
   
  lcd.clear();
  lcd.setCursor(Position, KUN_Position_line);//�����ƶ��ǵĹ��
  lcd.write((byte)0);
   //���ƶ�ʱ�Ĺ��λ��
  lcd.write((byte)1);
   
  delay(300);
 }
}

 
