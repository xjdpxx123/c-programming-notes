#include <stdio.h>
#include <math.h>

int main(void)
{
    double value = 15.0 / 4;
    double money = 12345.62;

    // 加 0.5 再取整的方法只适用于这里的非负数。
    printf("%.2f 四舍五入为 %d\n", value, (int)(value + 0.5));
    printf("round 的结果：%.0f，%.0f\n", round(value), round(-value));
    printf("直接保留到百位：%d\n", (int)money / 100 * 100);
    // 先以百元为单位取整，再乘 100 恢复为元。
    printf("四舍五入到百位：%d\n", (int)(money / 100 + 0.5) * 100);
    printf("三舍四入到百位：%d\n", (int)(money / 100 + 0.6) * 100);
    return 0;
}
