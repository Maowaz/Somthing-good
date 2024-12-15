#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>  // ����sleep������ͷ�ļ�
#include <string.h>  // ����strcmp������ͷ�ļ�

#define EVENT2_THRESHOLD 10  // �¼�2�Ĵ���������ֵ
#define EVENT3_THRESHOLD 10  // �¼�3�Ĵ���������ֵ

void trigger_event(int random_num, int *event1_count, int *event2_count, int *event3_count, int *event4_count) {
    if (random_num == 1) {
        printf("ˢ���ֻ���\n");
        (*event1_count)++;
    } else if (random_num > 1 && random_num <= 80) {
        printf("ѧϰ��Сʱ\n");
        (*event2_count)++;
    } else if (random_num > 80 && random_num <= 99) {
        printf("ѧϰһ��\n");
        (*event3_count)++;
    } else {
        printf("ˢһ���ֻ�\n");
        (*event4_count)++;
    }
}

int main() {
    // ʹ�õ�ǰʱ����Ϊ����
    srand(time(NULL));

    // ��¼�¼���������
    int event1_count = 0;
    int event2_count = 0;
    int event3_count = 0;
    int event4_count = 0;

    while (1) {
        int random_num = rand() % 100 + 1;  // ����1-100֮��������
        trigger_event(random_num, &event1_count, &event2_count, &event3_count, &event4_count);

        // ���������¼�2��3ʮ��֮�󣬴��������¼�
        if (event2_count >= EVENT2_THRESHOLD || event3_count >= EVENT3_THRESHOLD) {
            printf("�㴥���������¼���\n");
            int hidden_event = rand() % 10 + 1;
            if (hidden_event == 1) {
                printf("�ٻ�1�Ƚ�! ˢ�ֻ�\n");
            } else {
                printf("�㱻ƭ�ˣ�\n");
            }
            break;  // ���������¼����˳�ѭ��
        }

        printf("����������һ����? ����1����, ����0�˳�\n");
        char choice[10];
        //fgets(choice, sizeof(choice), stdin); �������Ǵӱ�׼�����ж�ȡһ���ַ���ֱ���������з���\n�����ȡ��ָ�����ַ���Ϊֹ��������ȡ�����ݴ洢�� choice �����У������������û������������Ӧ�Ĳ�����
        fgets(choice, sizeof(choice), stdin);//stdin�����û����� fgets ����ָ��Ҫ��ȡ������ַ����������ܹ���ֹ�����������

        // ����ѡɶ
        if (strcmp(choice, "1\n") == 0) { //strcmp ��һ�����ڱȽ������ַ����ĺ�������ԭ���� <string.h> ͷ�ļ��ж��塣�ú��������������ַ��Ƚ������ַ��������ݡ�
            printf("����һ�Σ�\n");
            sleep(5);
        } else if (strcmp(choice, "0\n") == 0) {
            printf("ллʹ�ã�\n");
            break;  // ����0�˳�ѭ��
        } else {
            printf("��Ч���룬����������\n");
        }
    }

    return 0;
}
