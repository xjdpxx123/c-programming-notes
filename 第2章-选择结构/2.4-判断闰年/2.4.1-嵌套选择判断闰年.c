#include <stdio.h>

int main(void)
{
    int year;

    printf("请输入公历年份（1 到 9999）：");
    if (scanf("%d", &year) != 1 || year < 1 || year > 9999) {
        printf("年份不在有效范围内。\n");
        return 1;
    }

    if (year % 4 != 0) {
        printf("%d 年是平年\n", year);
    } else {
        if (year % 100 != 0) {
            printf("%d 年是闰年\n", year);
        } else {
            // 世纪年还要能被 400 整除，才是闰年。
            if (year % 400 != 0) {
                printf("%d 年是平年\n", year);
            } else {
                printf("%d 年是闰年\n", year);
            }
        }
    }
    return 0;
}
