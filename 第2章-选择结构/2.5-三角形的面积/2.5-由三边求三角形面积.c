#include <stdio.h>
#include <math.h>

int main(void)
{
    int a, b, c;
    double p, area;

    printf("请输入三条整数边长（1 到 1000000）：");
    if (scanf("%d%d%d", &a, &b, &c) != 3 ||
        a < 1 || a > 1000000 || b < 1 || b > 1000000 ||
        c < 1 || c > 1000000) {
        printf("边长不在有效范围内。\n");
        return 1;
    }
    // 任意两边之和必须大于第三边，相等时三点在同一直线上。
    if (a + b <= c || a + c <= b || b + c <= a) {
        printf("这三条边不能构成三角形。\n");
        return 1;
    }
    // p 是半周长，除以 2.0 保留可能出现的半个单位。
    p = (a + b + c) / 2.0;
    // 海伦公式用三边和半周长计算面积。
    area = sqrt(p * (p - a) * (p - b) * (p - c));
    printf("三角形的面积：%.2f\n", area);
    return 0;
}
