#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>  // 包含sleep函数的头文件
#include <string.h>  // 包含strcmp函数的头文件

#define EVENT2_THRESHOLD 10  // 事件2的触发次数阈值
#define EVENT3_THRESHOLD 10  // 事件3的触发次数阈值

void trigger_event(int random_num, int *event1_count, int *event2_count, int *event3_count, int *event4_count) {
    if (random_num == 1) {
        printf("刷会手机吧\n");
        (*event1_count)++;
    } else if (random_num > 1 && random_num <= 80) {
        printf("学习两小时\n");
        (*event2_count)++;
    } else if (random_num > 80 && random_num <= 99) {
        printf("学习一天\n");
        (*event3_count)++;
    } else {
        printf("刷一天手机\n");
        (*event4_count)++;
    }
}

int main() {
    // 使用当前时间作为种子
    srand(time(NULL));

    // 记录事件触发次数
    int event1_count = 0;
    int event2_count = 0;
    int event3_count = 0;
    int event4_count = 0;

    while (1) {
        int random_num = rand() % 100 + 1;  // 生成1-100之间的随机数
        trigger_event(random_num, &event1_count, &event2_count, &event3_count, &event4_count);

        // 连续抽中事件2，3十次之后，触发隐藏事件
        if (event2_count >= EVENT2_THRESHOLD || event3_count >= EVENT3_THRESHOLD) {
            printf("你触发了隐藏事件！\n");
            int hidden_event = rand() % 10 + 1;
            if (hidden_event == 1) {
                printf("荣获1等奖! 刷手机\n");
            } else {
                printf("你被骗了！\n");
            }
            break;  // 触发隐藏事件后退出循环
        }

        printf("您还想再来一次吗? 输入1继续, 输入0退出\n");
        char choice[10];
        //fgets(choice, sizeof(choice), stdin); 的作用是从标准输入中读取一行字符，直到遇到换行符（\n）或读取到指定的字符数为止。它将读取的内容存储在 choice 数组中，允许程序根据用户的输入进行相应的操作。
        fgets(choice, sizeof(choice), stdin);//stdin接收用户输入 fgets 可以指定要读取的最大字符数，并且能够防止缓冲区溢出。

        // 看看选啥
        if (strcmp(choice, "1\n") == 0) { //strcmp 是一个用于比较两个字符串的函数，其原型在 <string.h> 头文件中定义。该函数的作用是逐字符比较两个字符串的内容。
            printf("再来一次！\n");
            sleep(5);
        } else if (strcmp(choice, "0\n") == 0) {
            printf("谢谢使用！\n");
            break;  // 输入0退出循环
        } else {
            printf("无效输入，请重新输入\n");
        }
    }

    return 0;
}
