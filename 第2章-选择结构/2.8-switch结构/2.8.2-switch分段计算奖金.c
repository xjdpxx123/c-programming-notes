#include <stdio.h>

int main(void)
{
    double profit, bonus;
    // 依次累计利润达到 10万、20万、40万、60万、100万时的奖金。
    double p2 = 100000 * 0.10;
    double p4 = p2 + 100000 * 0.075;
    double p6 = p4 + 200000 * 0.05;
    double p10 = p6 + 200000 * 0.03;
    double p100 = p10 + 400000 * 0.015;

    printf("请输入利润（元，0 到 1000000000）：");
    if (scanf("%lf", &profit) != 1 || !(profit >= 0 && profit <= 1000000000)) {
        printf("利润不在有效范围内。\n");
        return 1;
    }
    // 各区间分别计提；p2 等变量保存前面区间的累计奖金。

    // 每个 case 对应一个十万元区间，同一提成比例的区间共用语句。
    switch ((int)(profit / 100000)) {
        case 0:
            bonus = profit * 0.10;
            break;
        case 1:
            bonus = p2 + (profit - 100000) * 0.075;
            break;
        case 2:
        case 3:
            bonus = p4 + (profit - 200000) * 0.05;
            break;
        case 4:
        case 5:
            bonus = p6 + (profit - 400000) * 0.03;
            break;
        case 6:
        case 7:
        case 8:
        case 9:
            bonus = p10 + (profit - 600000) * 0.015;
            break;
        default:
            bonus = p100 + (profit - 1000000) * 0.01;
            break;
    }
    printf("奖金：%.2f 元\n", bonus);
    return 0;
}
