#include <stdio.h>

int main(void)
{
    int number;
    int divisor;
    int is_prime = 1;

    printf("请输入一个整数：");
    if (scanf("%d", &number) != 1) {
        printf("输入有误，请输入整数。\n");
        return 1;
    }
    if (number < 2) {
        printf("%d 不是素数，素数必须大于 1。\n", number);
        return 0;
    }

    divisor = 2;
    // 因子成对出现，试除到平方根即可；除法避免平方溢出。
    while (divisor <= number / divisor) {
        if (number % divisor == 0) {
            is_prime = 0;
            break;
        }
        divisor++;
    }
    if (is_prime) {
        printf("%d 是素数。\n", number);
    } else {
        printf("%d 不是素数，可以被 %d 整除。\n", number, divisor);
    }
    return 0;
}
