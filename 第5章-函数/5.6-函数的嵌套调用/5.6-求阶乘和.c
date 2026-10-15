#include <stdio.h>

unsigned long long factorial(int n)
{
    unsigned long long result = 1;  /* n为0或1时不进入循环，阶乘为1。 */
    for (int i = 2; i <= n; i++) {
        result *= (unsigned int)i;
    }
    return result;
}

unsigned long long factorial_sum(int begin, int end)
{
    unsigned long long total = 0;
    for (int i = begin; i <= end; i++) {
        /* 每求一项，都先调用factorial得到该项的阶乘。 */
        total += factorial(i);
    }
    return total;
}

int main(void)
{
    int begin, end;
    printf("请输入阶乘和的起点和终点（0至20，起点不大于终点）：");
    if (scanf("%d%d", &begin, &end) != 2 || begin < 0 || begin > end || end > 20) {
        puts("范围有误。");
        return 1;
    }
    printf("从%d!加到%d!的和为%llu\n", begin, end, factorial_sum(begin, end));
    return 0;
}
