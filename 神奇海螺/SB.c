#include <windows.h>//��windows��ʹ��sleep��������Ҫд�����ͷ�ļ�
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
            Sleep(1000); // �޸���һ��
            printf("boy: is that a question?\n");
            Sleep(1000); // �޸���һ��
            printf("boy: no ,it doesn't.\n");
            Sleep(1000); // �޸���һ��
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
            printf("û����Ц���ˡ�����");
        }
         printf("����������һ����? ����1����, ����0�˳�\n");
        char choice[10];
        fgets(choice, sizeof(choice), stdin);

        // ����ѡɶ
        if (strcmp(choice, "1\n") == 0) {
            printf("����һ�Σ�\n");
            Sleep(5000);
        } else if (strcmp(choice, "0\n") == 0) {
            printf("ллʹ�ã�\n");
            break;  // ����0�˳�ѭ��
        } else {
            printf("��Ч���룬����������\n");
        }
    }

    return 0;
    }
