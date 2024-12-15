#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERNAME_LEN 50
#define MAX_PASSWORD_LEN 50

typedef struct {
    char username[MAX_USERNAME_LEN];
    char password[MAX_PASSWORD_LEN];
} User;

void registerUser() {
    User user;
    FILE *file = fopen("users.dat", "a");
    if (!file) {
        perror("无法打开文件");
        return;
    }
    printf("请输入用户名: ");
    scanf("%s", user.username);
    printf("请输入密码: ");
    scanf("%s", user.password);
    fwrite(&user, sizeof(User), 1, file);
    fclose(file);
    printf("注册成功!\n");
}

int loginUser() {
    User user;
    FILE *file = fopen("users.dat", "r");
    if (!file) {
        perror("无法打开文件");
        return 0;
    }
    char username[MAX_USERNAME_LEN], password[MAX_PASSWORD_LEN];
    printf("请输入用户名: ");
    scanf("%s", username);
    printf("请输入密码: ");
    scanf("%s", password);
    while (fread(&user, sizeof(User), 1, file)) {
        if (strcmp(user.username, username) == 0 && strcmp(user.password, password) == 0) {
            fclose(file);
            printf("登录成功!\n");
            return 1;
        }
    }
    fclose(file);
    printf("登录失败!\n");
    return 0;
}

void questionAnswerSystem() {
    char question[256];
    printf("你好!我是神奇海螺,请问吧: ");
    scanf(" %[^\n]", question);
    if (strcmp(question, "你好") == 0) {
        printf("你好!\n");
    } else if (strcmp(question, "你是谁") == 0) {
        printf("我是神奇海螺。\n");
    } else {
        printf("为什么不去问问万能的群友呢。\n");
    }
}

int main() {
    int choice;
    while (1) {
        printf("1. 注册\n2. 登录\n3. 退出\n请选择: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                if (loginUser()) {
                    while (1) {
                        printf("1. 提问\n2. 退出\n请选择: ");
                        scanf("%d", &choice);
                        if (choice == 1) {
                            questionAnswerSystem();
                        } else {
                            break;
                        }
                    }
                }
                break;
            case 3:
                exit(0);
            default:
                printf("请重新选择。\n");
        }
    }
    return 0;
}
