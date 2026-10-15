#include <stdio.h>

double fraction_sum(int count)
{
    double numerator = 2.0;
    double denominator = 1.0;
    double total = 0.0;

    for (int i = 0; i < count; i++) {
        total += numerator / denominator;
        /* 下一项分子是当前分子与分母之和，分母是当前分子。 */
        double next = numerator + denominator;
        denominator = numerator;
        numerator = next;
    }
    return total;
}

int main(void)
{
    puts("分数序列：2/1 + 3/2 + 5/3 + 8/5 + ...");
    printf("前20项和：%.6f\n", fraction_sum(20));
    return 0;
}
