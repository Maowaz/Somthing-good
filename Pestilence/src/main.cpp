#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Arduino.h>
#include <Adafruit_I2CDevice.h>
#include <SPI.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); // ����LCD��ַ�ͳߴ�
// ���崥��������
#define Touch_pin 2
// ���尴��
int upButton = 3;
int downButton = 4;

/*��Ϸģʽ����*/
int CurrentMode = 0;
const char* GameMode[2] = {"HUMAN","PATHOGEN"};
const int GameModeNum = sizeof(GameMode)/sizeof(GameMode[0]);//��Ϸģʽ����
/*��Ϸ��ʼ*/
void clickStart(){
    lcd.init();
    lcd.backlight();
    // ��ʾ��Ϸ���� , ���������������ʼ��Ϸ���л���Ϸģʽ
    if(digitalRead(Touch_pin) == HIGH){
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Select game mode:");
        delay(2000);
        // ��ʾ��Ϸģʽѡ�� ����С��ͷ����ʾ��ǰģʽ
        for(int i=0;i<GameModeNum;i++){
            //���i���ڵ�ǰģʽ������ʾ��ͷ��������ʾ�ո�
            if(i == CurrentMode){
                lcd.print(">");
            }else{
                lcd.print(" ");
            }
            lcd.print(GameMode[i]);
            if(i < GameModeNum-1){
                lcd.setCursor(0,i+1);
            }
        }
    }else{
        lcd.print("Pestilence");
    }
}
/*��ʼ��*/
void setup(){
    pinMode(upButton,INPUT);
    pinMode(downButton,INPUT);
    clickStart();//��Ϸ��ʼ��������
}

/*��ѭ��*/
void loop(){
    /*����*/
    if(digitalRead(upButton) == HIGH){
        CurrentMode--;//����
        //�����ϼ�����ǰģʽ��һ ������δ�����ϼ�����ǰģʽΪ0 �������ϼ� ������ʾѡ��Ϊ�ڶ���
        if(CurrentMode < 0){ 
            CurrentMode = GameModeNum - 1;
        }
        delay(300); //��ʱ300ms
        clickStart(); //��Ϸ��ʼ��������
    }
    /*����*/
    if(digitalRead(downButton) == HIGH){
        CurrentMode++;//����
        //�����¼�����ǰģʽ��һ ������δ�����¼�����ǰģʽΪ0 �������¼� ������ʾѡ��Ϊ��һ��
    if(CurrentMode >= GameModeNum){ //����ǰģʽ���ڵ�����Ϸģʽ��������ǰģʽΪ0
            CurrentMode = 0;
       }
        delay(300); //��ʱ300ms
        clickStart(); //��Ϸ��ʼ��������
    }
}    
    