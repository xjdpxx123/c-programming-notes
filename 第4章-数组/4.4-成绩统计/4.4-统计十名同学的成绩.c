#include <stdio.h>
#include <math.h>

int main(void)
{
    double scores[10];
    double sum = 0.0;
    double maximum = 0.0;
    double minimum = 100.0;
    int count = 0;

    while (count < 10) {
        printf("请输入第 %d 名同学的成绩：", count + 1);
        if (scanf("%lf", &scores[count]) != 1) {
            printf("输入有误，请输入数值。\n");
            return 1;
        }
        if (!isfinite(scores[count]) || scores[count] < 0.0 || scores[count] > 100.0) {
            printf("成绩须在 0 到 100 之间，请重新输入。\n");
            continue;
        }
        // 只有范围合法的成绩才计入总分和人数。
        sum += scores[count];
        if (scores[count] > maximum) {
            maximum = scores[count];
        }
        if (scores[count] < minimum) {
            minimum = scores[count];
        }
        count++;
    }

    printf("十名同学的成绩：\n");
    for (int i = 0; i < 10; i++) {
        printf("%.2f ", scores[i]);
    }
    printf("\n总分：%.2f\n平均分：%.2f\n最高分：%.2f\n最低分：%.2f\n",
           sum, sum / 10, maximum, minimum);
    return 0;
}
