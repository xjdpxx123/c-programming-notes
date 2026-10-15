#include <stdio.h>
#include <math.h>

#define MAX_VALUE(x, y) ((x) > (y) ? (x) : (y))
#define MIN_VALUE(x, y) ((x) < (y) ? (x) : (y))
/* RATIO 展开后，其中的 MAX_VALUE 和 MIN_VALUE 还会继续展开。 */
#define RATIO(x, y) (MAX_VALUE((x), (y)) / MIN_VALUE((x), (y)))

int main(void)
{
    double a;
    double b;
    double ratio;

    printf("请输入两个正数：");
    if (scanf("%lf%lf", &a, &b) != 2 || !isfinite(a) || !isfinite(b) ||
        a <= 0.0 || b <= 0.0) {
        puts("请输入两个有限的正数。");
        return 1;
    }
    /* 宏会重复使用参数，不要传入 i++ 等带副作用的表达式。 */
    ratio = RATIO(a, b);
    if (!isfinite(ratio)) {
        puts("比值超出可表示范围。");
        return 1;
    }
    printf("较大值与较小值的比：%.6f\n", ratio);
    return 0;
}
