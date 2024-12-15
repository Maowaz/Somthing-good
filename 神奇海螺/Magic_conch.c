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
        perror("�޷����ļ�");
        return;
    }
    printf("�������û���: ");
    scanf("%s", user.username);
    printf("����������: ");
    scanf("%s", user.password);
    fwrite(&user, sizeof(User), 1, file);
    fclose(file);
    printf("ע��ɹ�!\n");
}

int loginUser() {
    User user;
    FILE *file = fopen("users.dat", "r");
    if (!file) {
        perror("�޷����ļ�");
        return 0;
    }
    char username[MAX_USERNAME_LEN], password[MAX_PASSWORD_LEN];
    printf("�������û���: ");
    scanf("%s", username);
    printf("����������: ");
    scanf("%s", password);
    while (fread(&user, sizeof(User), 1, file)) {
        if (strcmp(user.username, username) == 0 && strcmp(user.password, password) == 0) {
            fclose(file);
            printf("��¼�ɹ�!\n");
            return 1;
        }
    }
    fclose(file);
    printf("��¼ʧ��!\n");
    return 0;
}

void questionAnswerSystem() {
    char question[256];
    printf("���!�������溣��,���ʰ�: ");
    scanf(" %[^\n]", question);
    if (strcmp(question, "���") == 0) {
        printf("���!\n");
    } else if (strcmp(question, "����˭") == 0) {
        printf("�������溣�ݡ�\n");
    } else {
        printf("Ϊʲô��ȥ�������ܵ�Ⱥ���ء�\n");
    }
}

int main() {
    int choice;
    while (1) {
        printf("1. ע��\n2. ��¼\n3. �˳�\n��ѡ��: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                if (loginUser()) {
                    while (1) {
                        printf("1. ����\n2. �˳�\n��ѡ��: ");
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
                printf("������ѡ��\n");
        }
    }
    return 0;
}
