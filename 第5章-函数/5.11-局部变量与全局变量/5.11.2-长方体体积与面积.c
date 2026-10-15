#include <math.h>
#include <stdio.h>

/* volume把三个面的面积保存在全局变量中，供main读取。 */
double area_lw, area_lh, area_wh;

double volume(double length, double width, double height)
{
    area_lw = length * width;
    area_lh = length * height;
    area_wh = width * height;
    return length * width * height;
}

int main(void)
{
    double length, width, height;
    printf("请输入长方体的长、宽、高（大于0且不超过1000000）：");
    if (scanf("%lf%lf%lf", &length, &width, &height) != 3 ||
        !isfinite(length) || !isfinite(width) || !isfinite(height) ||
        length <= 0 || width <= 0 || height <= 0 ||
        length > 1000000 || width > 1000000 || height > 1000000) {
        puts("尺寸有误。");
        return 1;
    }
    double result = volume(length, width, height);
    printf("体积：%.2f\n", result);
    printf("长×宽：%.2f，长×高：%.2f，宽×高：%.2f\n", area_lw, area_lh, area_wh);
    return 0;
}
