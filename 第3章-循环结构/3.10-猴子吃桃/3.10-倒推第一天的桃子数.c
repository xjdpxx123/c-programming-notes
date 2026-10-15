#include <stdio.h>

int main(void)
{
    int day = 9;
    int peaches = 1;

    printf("第 10 天早上剩下 1 个桃子。\n");
    while (day >= 1) {
        // 后一天剩余数 = 前一天的数量 / 2 - 1，倒推时先加 1 再乘 2。
        peaches = (peaches + 1) * 2;
        printf("第 %2d 天早上有 %4d 个桃子，当天吃掉 %d 个。\n",
               day, peaches, peaches / 2 + 1);
        day--;
    }
    printf("第一天共摘了 %d 个桃子。\n", peaches);
    return 0;
}
