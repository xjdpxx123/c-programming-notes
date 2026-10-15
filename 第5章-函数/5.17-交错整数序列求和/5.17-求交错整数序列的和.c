#include <stdio.h>

/* step取正数，依次累加不超过end的项。 */
int sum(int begin, int end, int step)
{
    int total = 0;
    for (int n = begin; n <= end; n += step) {
        total += n;
    }
    return total;
}

int main(void)
{
    int direct = 1;
    int sign = 1;
    for (int n = 2; n <= 999; n++) {
        direct += sign * n;
        sign = -sign;
    }
    /* 首项1单独保留，其余正项为偶数，负项为从3开始的奇数。 */
    int even_sum = sum(2, 998, 2);
    int odd_sum = sum(3, 999, 2);
    printf("1+2-3+4-5+...+998-999\n");
    printf("循环求和：%d\n", direct);
    printf("分组求和：%d\n", 1 + even_sum - odd_sum);
    return 0;
}
