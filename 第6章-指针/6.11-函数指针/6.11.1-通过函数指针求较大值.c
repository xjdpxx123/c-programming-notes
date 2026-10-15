#include <stdio.h>

int maximum(int a, int b)
{
    return a > b ? a : b;
}

int main(void)
{
    int x, y;
    /* function指向接收两个int参数、返回int的函数。 */
    int (*function)(int, int) = maximum;

    printf("请输入两个整数：");
    if (scanf("%d%d", &x, &y) != 2) {
        puts("输入有误。");
        return 1;
    }
    printf("较大的值：%d\n", (*function)(x, y));
    return 0;
}
