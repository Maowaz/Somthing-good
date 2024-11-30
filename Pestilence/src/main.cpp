#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Arduino.h>
#include <Adafruit_I2CDevice.h>
#include <SPI.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); // 设置LCD地址和尺寸
// 定义触摸传感器
#define Touch_pin 2
// 定义按键
int upButton = 3;
int downButton = 4;

/*游戏模式索引*/
int CurrentMode = 0;
const char* GameMode[2] = {"HUMAN","PATHOGEN"};
const int GameModeNum = sizeof(GameMode)/sizeof(GameMode[0]);//游戏模式数量
/*游戏开始*/
void clickStart(){
    lcd.init();
    lcd.backlight();
    // 显示游戏标题 , 点击触摸传感器开始游戏并切换游戏模式
    if(digitalRead(Touch_pin) == HIGH){
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Select game mode:");
        delay(2000);
        // 显示游戏模式选项 会有小箭头来提示当前模式
        for(int i=0;i<GameModeNum;i++){
            //如果i等于当前模式，则显示箭头，否则显示空格
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
/*初始化*/
void setup(){
    pinMode(upButton,INPUT);
    pinMode(downButton,INPUT);
    clickStart();//游戏初始函数调用
}

/*主循环*/
void loop(){
    /*上移*/
    if(digitalRead(upButton) == HIGH){
        CurrentMode--;//上移
        //按下上键，当前模式减一 ，若还未按下上键，则当前模式为0 ，按下上键 ，可显示选项为第二个
        if(CurrentMode < 0){ 
            CurrentMode = GameModeNum - 1;
        }
        delay(300); //延时300ms
        clickStart(); //游戏初始函数调用
    }
    /*下移*/
    if(digitalRead(downButton) == HIGH){
        CurrentMode++;//下移
        //按下下键，当前模式加一 ，若还未按下下键，则当前模式为0 ，按下下键 ，可显示选项为第一个
    if(CurrentMode >= GameModeNum){ //若当前模式大于等于游戏模式数量，则当前模式为0
            CurrentMode = 0;
       }
        delay(300); //延时300ms
        clickStart(); //游戏初始函数调用
    }
}    
    