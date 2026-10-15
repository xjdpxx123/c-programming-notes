#include <stdio.h>

int main(void)
{
    int a, b, c;

    printf("请输入三个整数，偶数将加 1：");
    if (scanf("%d%d%d", &a, &b, &c) != 3) {
        printf("输入格式不正确。\n");
        return 1;
    }
    // 三个数各自判断，不能串成只执行一个分支的 if-else。
    if (a % 2 == 0) {
        a++;
    }
    if (b % 2 == 0) {
        b++;
    }
    if (c % 2 == 0) {
        c++;
    }
    printf("三个奇数：%d %d %d\n", a, b, c);
    return 0;
}
