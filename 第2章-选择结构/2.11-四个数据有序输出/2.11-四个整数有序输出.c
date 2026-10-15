#include <stdio.h>

int main(void)
{
    int a, b, c, d, temp;

    printf("请输入四个整数：");
    if (scanf("%d%d%d%d", &a, &b, &c, &d) != 4) {
        printf("输入格式不正确。\n");
        return 1;
    }
    // a 依次与另外三个数比较，把最小值留在 a 中。
    if (a > b) {
        temp = a;
        a = b;
        b = temp;
    }
    if (a > c) {
        temp = a;
        a = c;
        c = temp;
    }
    if (a > d) {
        temp = a;
        a = d;
        d = temp;
    }
    // a 已经确定，再把剩下三个数中的最小值留在 b 中。
    if (b > c) {
        temp = b;
        b = c;
        c = temp;
    }
    if (b > d) {
        temp = b;
        b = d;
        d = temp;
    }
    // 最后只需排好 c 和 d。
    if (c > d) {
        temp = c;
        c = d;
        d = temp;
    }
    printf("从小到大：%d %d %d %d\n", a, b, c, d);
    return 0;
}
