#include <stdio.h>

int main(void)
{
    int i = 0;
    int sum = 0;

    while (i < 100) {
        i++;
        // 满足任一整除条件就跳过本次累加。
        if (i % 3 == 0 || i % 7 == 0) {
            continue;
        }
        sum += i;
    }
    printf("1 到 100 中既不能被 3 整除，也不能被 7 整除的数之和为 %d。\n", sum);
    return 0;
}
