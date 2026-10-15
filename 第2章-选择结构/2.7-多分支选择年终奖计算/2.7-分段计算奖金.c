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
    // 超过分界点的部分才使用下一档比例，前面各档奖金保持不变。

    if (profit <= 100000) {
        bonus = profit * 0.10;
    } else if (profit <= 200000) {
        bonus = p2 + (profit - 100000) * 0.075;
    } else if (profit <= 400000) {
        bonus = p4 + (profit - 200000) * 0.05;
    } else if (profit <= 600000) {
        bonus = p6 + (profit - 400000) * 0.03;
    } else if (profit <= 1000000) {
        bonus = p10 + (profit - 600000) * 0.015;
    } else {
        bonus = p100 + (profit - 1000000) * 0.01;
    }
    printf("奖金：%.2f 元\n", bonus);
    return 0;
}
