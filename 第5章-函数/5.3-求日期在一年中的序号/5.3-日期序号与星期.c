#include <stdio.h>

int is_leap(int year)
{
    return year % 400 == 0 || (year % 4 == 0 && year % 100 != 0);
}

int month_days(int year, int month)
{
    /* 下标与月份一致；下标0不使用，闰年只给二月增加一天。 */
    const int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    return days[month] + (month == 2 && is_leap(year));
}

int day_of_year(int year, int month, int day)
{
    int total = day;
    for (int m = 1; m < month; m++) {
        total += month_days(year, m);
    }
    return total;
}

int main(void)
{
    int year, month, day;
    const char *weekdays[] = {"星期日", "星期一", "星期二", "星期三", "星期四", "星期五", "星期六"};

    printf("请输入年、月、日（年份1至9999）：");
    if (scanf("%d%d%d", &year, &month, &day) != 3 ||
        year < 1 || year > 9999 || month < 1 || month > 12) {
        puts("日期不合法。");
        return 1;
    }
    if (day < 1 || day > month_days(year, month)) {
        puts("日期不合法。");
        return 1;
    }

    int number = day_of_year(year, month, day);
    int previous_year = year - 1;
    /* 按公历从1年1月1日星期一计数，普通年贡献1天偏移，闰年再加1天。 */
    int weekday = (previous_year + previous_year / 4 - previous_year / 100 +
                   previous_year / 400 + number) % 7;
    printf("%d年%d月%d日是这一年的第%d天，%s。\n", year, month, day, number, weekdays[weekday]);
    return 0;
}
