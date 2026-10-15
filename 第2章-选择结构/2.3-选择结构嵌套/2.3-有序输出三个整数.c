#include <stdio.h>

int main(void)
{
    int a, b, c;

    printf("请输入三个整数：");
    if (scanf("%d%d%d", &a, &b, &c) != 3) {
        printf("输入格式不正确。\n");
        return 1;
    }
    // 使用 >= 也能处理两个或三个数相等的情况。
    // 外层确定最大值，内层再排列剩下的两个数。
    if (a >= b && a >= c) {
        if (b >= c) {
            printf("从大到小：%d %d %d\n", a, b, c);
        } else {
            printf("从大到小：%d %d %d\n", a, c, b);
        }
    } else if (b >= a && b >= c) {
        if (a >= c) {
            printf("从大到小：%d %d %d\n", b, a, c);
        } else {
            printf("从大到小：%d %d %d\n", b, c, a);
        }
    } else {
        if (a >= b) {
            printf("从大到小：%d %d %d\n", c, a, b);
        } else {
            printf("从大到小：%d %d %d\n", c, b, a);
        }
    }
    return 0;
}
