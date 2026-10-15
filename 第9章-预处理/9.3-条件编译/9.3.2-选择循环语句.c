#include <stdio.h>

/* 默认累加3的倍数；编译时定义 EVEN_NUMBERS 则累加偶数。 */
int main(void)
{
    int n;
    int i;
    long long sum = 0;

    printf("请输入上限（0～10000）：");
    if (scanf("%d", &n) != 1 || n < 0 || n > 10000) {
        puts("上限输入有误。");
        return 1;
    }
#ifdef EVEN_NUMBERS
    puts("参与求和的偶数：");
    for (i = 2; i <= n; i += 2) {
#else
    puts("参与求和的3的倍数：");
    for (i = 3; i <= n; i += 3) {
#endif
        /* 两种 for 语句共用循环体，编译时只保留其中一种。 */
        printf("%d ", i);
        sum += i;
    }
    printf("\n和值为%lld\n", sum);
    return 0;
}
