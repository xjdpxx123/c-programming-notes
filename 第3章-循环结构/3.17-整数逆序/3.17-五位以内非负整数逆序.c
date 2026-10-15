#include <stdio.h>

int main(void)
{
    int number;
    int remaining;
    int reversed = 0;

    printf("请输入 0 到 99999 之间的整数：");
    if (scanf("%d", &number) != 1 || number < 0 || number > 99999) {
        printf("输入有误，请输入不超过五位的非负整数。\n");
        return 1;
    }
    remaining = number;
    while (remaining > 0) {
        // 已得到的结果乘 10 空出个位，再接上原数当前的末位数字。
        reversed = reversed * 10 + remaining % 10;
        remaining /= 10;
    }
    // 结果按整数输出，原数末尾的 0 不会保留为前导 0。
    printf("%d 逆序后的整数为 %d。\n", number, reversed);
    return 0;
}
