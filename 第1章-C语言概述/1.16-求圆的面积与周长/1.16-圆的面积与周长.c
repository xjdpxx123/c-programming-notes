#include <stdio.h>

int main(void)
{
    // const 表示 pi 在初始化后不能再被赋值。
    const double pi = 3.141592653589793;
    double radius;
    double area, perimeter;

    printf("请输入圆的半径（0 到 1000000）：");
    if (scanf("%lf", &radius) != 1 || !(radius >= 0 && radius <= 1000000)) {
        printf("半径不在有效范围内。\n");
        return 1;
    }
    area = pi * radius * radius;
    perimeter = 2 * pi * radius;
    printf("面积：%.2f\n周长：%.2f\n", area, perimeter);
    return 0;
}
