#include <stdio.h>
#include <stdlib.h>  // 包含 atoi 函数需要的头文件

int main() {
    char a[10], b[10]; // 假设输入不超过9个字符
    int num_a, num_b, Result;

    fgets(a, sizeof(a), stdin);
    printf("输入b: \n");
    fgets(b, sizeof(b), stdin);

    num_a = atoi(a);  // 将字符串转换为整数
    num_b = atoi(b);  // 将字符串转换为整数

    if (num_a <= 5 && num_b <= 5) {
        printf("a,b 不够大\n");
        return 1;  // 返回一个错误码
    } else {
        Result = num_a + num_b; // 假设您想计算和
        printf("Result = %d\n", Result);
        return 0; // 成功结束
    }
}
