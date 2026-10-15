#include <stdio.h>

int is_prime(int n)
{
    if (n < 2) {
        return 0;
    }
    /* 只试除到平方根；写成除法可以避免divisor * divisor溢出。 */
    for (int divisor = 2; divisor <= n / divisor; divisor++) {
        if (n % divisor == 0) {
            return 0;
        }
    }
    return 1;
}

int main(void)
{
    int total = 0;
    printf("10至20之间的素数：");
    for (int n = 10; n <= 20; n++) {
        if (is_prime(n)) {
            printf("%d ", n);
            total += n;
        }
    }
    printf("\n素数和：%d\n", total);
    return 0;
}
