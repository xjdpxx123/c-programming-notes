#include <stdio.h>

int main(void)
{
    int number;
    int remaining;

    printf("请输入一个三位正整数：");
    if (scanf("%d", &number) != 1 || number < 100 || number > 999) {
        printf("请输入 100 到 999 之间的整数。\n");
        return 1;
    }

    remaining = number;
    printf("%d 从个位到百位依次为：", number);
    // 对 10 取余得到末位数字，整除 10 去掉这一位。
    while (remaining > 0) {
        printf("%d", remaining % 10);
        remaining /= 10;
        if (remaining > 0) {
            printf("、");
        }
    }
    printf("\n");
    return 0;
}
