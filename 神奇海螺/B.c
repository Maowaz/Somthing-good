#include <stdio.h>
#include <stdlib.h>  // ���� atoi ������Ҫ��ͷ�ļ�

int main() {
    char a[10], b[10]; // �������벻����9���ַ�
    int num_a, num_b, Result;

    fgets(a, sizeof(a), stdin);
    printf("����b: \n");
    fgets(b, sizeof(b), stdin);

    num_a = atoi(a);  // ���ַ���ת��Ϊ����
    num_b = atoi(b);  // ���ַ���ת��Ϊ����

    if (num_a <= 5 && num_b <= 5) {
        printf("a,b ������\n");
        return 1;  // ����һ��������
    } else {
        Result = num_a + num_b; // ������������
        printf("Result = %d\n", Result);
        return 0; // �ɹ�����
    }
}
