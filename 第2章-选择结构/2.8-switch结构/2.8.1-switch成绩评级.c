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

    // 除以 10 再取整数，把一个分数段映射到一个 case 值。
    switch ((int)(score / 10)) {
        // 100 分与 90 至不足 100 分共用 A 等级分支。
        case 10:
        case 9: grade = 'A'; break;
        case 8: grade = 'B'; break;
        case 7: grade = 'C'; break;
        case 6: grade = 'D'; break;
        default: grade = 'E'; break;
    }
    printf("成绩等级：%c\n", grade);
    return 0;
}
