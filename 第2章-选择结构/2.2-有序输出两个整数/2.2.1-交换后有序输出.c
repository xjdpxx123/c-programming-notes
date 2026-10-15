#include <stdio.h>

int main(void)
{
    int a, b;

    printf("请输入两个整数：");
    if (scanf("%d%d", &a, &b) != 2) {
        printf("输入格式不正确。\n");
        return 1;
    }

    if (a > b) {
        int temp = a;
        a = b;
        b = temp;
    }
    // 无论是否发生交换，到这里都满足 a <= b。
    printf("从小到大：%d %d\n", a, b);
    return 0;
}
