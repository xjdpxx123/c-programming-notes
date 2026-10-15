#include <stdio.h>

int main(void)
{
    int a;
    float b;
    double c;

    printf("请输入一个整数和两个实数，用空格分隔：");
    // scanf 中 float 用 %f，double 用 %lf。
    // & 取得变量地址；返回值为 3 时，三个变量才都成功读入。
    if (scanf("%d%f%lf", &a, &b, &c) != 3) {
        printf("输入格式不正确。\n");
        return 1;
    }
    printf("整数：%d，单精度：%.2f，双精度：%.2f\n", a, b, c);
    return 0;
}
