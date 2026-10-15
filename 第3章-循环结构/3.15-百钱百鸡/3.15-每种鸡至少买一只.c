#include <stdio.h>

int main(void)
{
    int solutions = 0;

    printf("用 100 元买 100 只鸡，每种至少买一只：\n");
    // 100 元最多买 20 只公鸡或 33 只母鸡，据此限定枚举范围。
    for (int roosters = 1; roosters <= 20; roosters++) {
        for (int hens = 1; hens <= 33; hens++) {
            // 总数固定为 100，小鸡数量由另两种鸡的数量确定。
            int chicks = 100 - roosters - hens;
            // 小鸡三只一元，数量须为 3 的倍数，才能这样用整数除法计价。
            if (chicks > 0 && chicks % 3 == 0 &&
                5 * roosters + 3 * hens + chicks / 3 == 100) {
                printf("公鸡 %d 只，母鸡 %d 只，小鸡 %d 只。\n",
                       roosters, hens, chicks);
                solutions++;
            }
        }
    }
    printf("共有 %d 种买法。\n", solutions);
    return 0;
}
