#include <stdio.h>

int main(void)
{
    int number = 521;

    printf("%d 是奇数：%d\n", number, number % 2 != 0);
    printf("%d 能被 3 整除：%d\n", number, number % 3 == 0);
    printf("百位：%d\n", number / 100);
    // 先除以 10 去掉个位，再对 10 取余，就得到原数的十位。
    printf("十位：%d\n", number / 10 % 10);
    printf("个位：%d\n", number % 10);
    return 0;
}
