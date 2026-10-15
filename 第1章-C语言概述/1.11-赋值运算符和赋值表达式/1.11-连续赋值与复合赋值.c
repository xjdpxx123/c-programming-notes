#include <stdio.h>

int main(void)
{
    int a, b, c, d;

    // 连续赋值按从右向左的方式结合，四个变量都得到 16。
    a = b = c = d = 16;
    printf("连续赋值：%d %d %d %d\n", a, b, c, d);
    a += 9 - 6;
    b -= 9 - 6;
    // 等价于 c = c * (9 - 6)，右侧的减法要作为一个整体。
    c *= 9 - 6;
    d /= 3;
    printf("复合赋值：%d %d %d %d\n", a, b, c, d);
    a %= 5;
    printf("a 对 5 取余后：%d\n", a);
    return 0;
}
