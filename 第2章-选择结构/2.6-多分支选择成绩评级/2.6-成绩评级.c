#include <stdio.h>

int main(void)
{
    double score;
    char grade;

    printf("请输入成绩（0 到 100）：");
    if (scanf("%lf", &score) != 1 || !(score >= 0 && score <= 100)) {
        printf("成绩不在有效范围内。\n");
        return 1;
    }

    // 从高分向低分判断；进入后一分支时，前面的条件已经不成立。
    if (score >= 90) {
        grade = 'A';
    } else if (score >= 80) {
        grade = 'B';
    } else if (score >= 70) {
        grade = 'C';
    } else if (score >= 60) {
        grade = 'D';
    } else {
        grade = 'E';
    }
    printf("成绩等级：%c\n", grade);
    return 0;
}
