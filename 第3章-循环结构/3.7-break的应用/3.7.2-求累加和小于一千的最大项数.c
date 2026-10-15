#include <stdio.h>

int main(void)
{
    int n = 0;
    int sum = 0;

    while (1) {
        // 先检查下一项，保证当前和值严格小于 1000。
        if (sum + n + 1 >= 1000) {
            break;
        }
        n++;
        sum += n;
    }
    printf("最大的 n 为 %d，1 + 2 + ... + %d = %d。\n", n, n, sum);
    printf("再加上 %d 后，和值为 %d。\n", n + 1, sum + n + 1);
    return 0;
}
