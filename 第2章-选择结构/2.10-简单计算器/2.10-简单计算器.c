#include <stdio.h>
#include <math.h>

int main(void)
{
    double a, b, result;
    int choice;

    printf("请输入两个数（绝对值不超过 1000000）：");
    if (scanf("%lf%lf", &a, &b) != 2 ||
        !(a >= -1000000 && a <= 1000000) ||
        !(b >= -1000000 && b <= 1000000)) {
        printf("输入的数不在有效范围内。\n");
        return 1;
    }
    printf("1.相加\n2.相减\n3.相乘\n4.相除\n请选择：");
    if (scanf("%d", &choice) != 1) {
        printf("选项格式不正确。\n");
        return 1;
    }
    // break 结束分支选择，错误情况下的 return 则直接结束程序。
    switch (choice) {
        case 1: result = a + b; break;
        case 2: result = a - b; break;
        case 3: result = a * b; break;
        case 4:
            if (b == 0) {
                printf("除数不能为 0。\n");
                return 1;
            }
            result = a / b;
            break;
        default:
            printf("请选择 1 到 4。\n");
            return 1;
    }
    // 除数很接近 0 时，商仍有可能超出 double 的表示范围。
    if (!isfinite(result)) {
        printf("结果超出实数类型的表示范围。\n");
        return 1;
    }
    printf("运算结果：%.2f\n", result);
    return 0;
}
