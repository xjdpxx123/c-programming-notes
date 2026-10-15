#include <stdio.h>

int peaches(int day)
{
    /* 第10天早上剩1个，由此逐天反推此前的数量。 */
    if (day == 10) {
        return 1;
    }
    /* 当天吃掉一半再多吃1个，因此当天数量是次日数量加1后再乘2。 */
    return 2 * (peaches(day + 1) + 1);
}

int main(void)
{
    printf("第一天共摘了%d个桃子。\n", peaches(1));
    for (int day = 1; day <= 10; day++) {
        printf("第%d天早上剩%d个桃子。\n", day, peaches(day));
    }
    return 0;
}
