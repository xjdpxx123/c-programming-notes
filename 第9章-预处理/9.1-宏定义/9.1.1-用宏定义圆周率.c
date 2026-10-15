#include <stdio.h>
#include <math.h>

/* 替换内容不加分号，PI 可直接放入算式。 */
#define PI 3.14159265358979323846

int main(void)
{
    double radius;

    printf("请输入半径（0～1000000）：");
    if (scanf("%lf", &radius) != 1 || !isfinite(radius) ||
        radius < 0.0 || radius > 1000000.0) {
        puts("半径输入有误。");
        return 1;
    }
    printf("圆的周长：%.4f\n", 2.0 * PI * radius);
    printf("圆的面积：%.4f\n", PI * radius * radius);
    printf("球的表面积：%.4f\n", 4.0 * PI * radius * radius);
    printf("球的体积：%.4f\n", 4.0 / 3.0 * PI * radius * radius * radius);
    return 0;
}
