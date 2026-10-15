#include <stdio.h>

/* 编译时定义 FACTORIAL，便会选择阶乘分支。 */
#ifndef FACTORIAL
#define ADD
#endif

int main(void)
{
    int n;
    int i;
    unsigned long long result;

    /* 条件在编译前确定，生成的程序只包含所选分支。 */
#ifdef ADD
    printf("请输入上限n（0～1000000），计算1到n的和：");
    if (scanf("%d", &n) != 1 || n < 0 || n > 1000000) {
        puts("上限输入有误。");
        return 1;
    }
    result = 0;
    for (i = 1; i <= n; ++i) {
        result += (unsigned long long)i;
    }
    printf("1到%d的和为%llu\n", n, result);
#else
    printf("请输入n（0～20），计算n的阶乘：");
    if (scanf("%d", &n) != 1 || n < 0 || n > 20) {
        puts("n应在0～20之间。");
        return 1;
    }
    result = 1;
    for (i = 1; i <= n; ++i) {
        result *= (unsigned long long)i;
    }
    printf("%d的阶乘为%llu\n", n, result);
#endif
    return 0;
}
