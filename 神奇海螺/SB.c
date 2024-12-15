#include <windows.h>//在windows，使用sleep（）函数要写出这个头文件
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    srand(time(NULL));
    for (int i = 0; i < 3; i++) {
        int n = rand() % 3 + 1;
        if (n == 1) {
            printf("girl: what starts with an f and ends with a k?\n");
            Sleep(1000); // 修改这一行
            printf("boy: is that a question?\n");
            Sleep(1000); // 修改这一行
            printf("boy: no ,it doesn't.\n");
            Sleep(1000); // 修改这一行
            printf("boy:what starts with a w and ends with a t \n");
        }else if(n==2){
            printf("1 :Do you know what's theeasiest English word to spell? \n");
            Sleep(1000); 
            printf("Easiest?Ha? \n");
            Sleep(2000); 
            printf("1:It's the word 'icy'. \n");
            Sleep(1000); 
            printf("2:icy? why \n");
            Sleep(1000); 
            printf("2: i see why... \n");

        }else{
            printf("没有冷笑话了。。。");
        }
         printf("您还想再来一次吗? 输入1继续, 输入0退出\n");
        char choice[10];
        fgets(choice, sizeof(choice), stdin);

        // 看看选啥
        if (strcmp(choice, "1\n") == 0) {
            printf("再来一次！\n");
            Sleep(5000);
        } else if (strcmp(choice, "0\n") == 0) {
            printf("谢谢使用！\n");
            break;  // 输入0退出循环
        } else {
            printf("无效输入，请重新输入\n");
        }
    }

    return 0;
    }
