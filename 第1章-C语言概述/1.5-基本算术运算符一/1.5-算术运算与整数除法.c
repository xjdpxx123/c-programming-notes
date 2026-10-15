#include <stdio.h>

int main(void)
{
    int a = 21;
    int b = 5;

    printf("加：%d，减：%d，乘：%d\n", a + b, a - b, a * b);
    // 两个整数相除时，商的小数部分被舍去；% 取得余数。
    printf("整数除法：%d，余数：%d\n", a / b, a % b);
    // 在除法之前转换 a，才能得到实数除法的结果。
    printf("实数除法：%.1f\n", (double)a / b);
    printf("1 + 2 * 3 = %d\n", 1 + 2 * 3);
    printf("(1 + 2) * 3 = %d\n", (1 + 2) * 3);
    printf("嵌套括号：%d\n", (1 + (2 + 3) * 4) / 3);
    return 0;
}
