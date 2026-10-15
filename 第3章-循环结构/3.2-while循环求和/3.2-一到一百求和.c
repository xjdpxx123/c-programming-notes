#include <stdio.h>

int main(void)
{
    int i = 1;
    int sum = 0;

    // 每轮开始时，sum 保存 1 到 i - 1 的和。
    while (i <= 100) {
        sum += i;
        i++;
    }
    printf("1 + 2 + ... + 100 = %d\n", sum);
    return 0;
}
