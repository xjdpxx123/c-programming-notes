#include <stdio.h>

int main(void)
{
    int a = 12;
    int b = 15;
    // 条件成立时取问号后的值，否则取冒号后的值。
    int larger = (a > b) ? a : b;
    int even = (b % 2 == 0) ? b : b - 1;

    printf("较大的数：%d\n", larger);
    printf("不大于 %d 的最大偶数：%d\n", b, even);
    // 加法的优先级高于关系运算，括号可以改变运算的组合方式。
    printf("5 + 3 > 7：%d\n", 5 + 3 > 7);
    printf("5 + (3 > 7)：%d\n", 5 + (3 > 7));
    return 0;
}
