#include <math.h>
#include <stdio.h>

double polynomial(double x)
{
    return ((3.0 * x + 4.0) * x + 5.0) * x + 6.0;
}

int opposite_signs(double a, double b)
{
    return (a < 0 && b > 0) || (a > 0 && b < 0);
}

/* 调用前应保证left < right，且两端函数值异号。 */
double solve(double left, double right)
{
    double f_left = polynomial(left);
    for (int i = 0; i < 100; i++) {
        double middle = left + (right - left) / 2.0;
        double f_middle = polynomial(middle);
        if (fabs(f_middle) < 1e-10 || right - left < 1e-10) {
            return middle;
        }
        /* 保留函数值异号的半个区间，连续函数的根仍在其中。 */
        if (opposite_signs(f_left, f_middle)) {
            right = middle;
        } else {
            left = middle;
            f_left = f_middle;
        }
    }
    return left + (right - left) / 2.0;
}

int main(void)
{
    double begin, end;
    printf("求3x^3+4x^2+5x+6=0的根，请输入区间端点（-1000至1000）：");
    if (scanf("%lf%lf", &begin, &end) != 2 || !isfinite(begin) || !isfinite(end) ||
        begin < -1000 || end > 1000 || begin > end) {
        puts("区间有误。");
        return 1;
    }

    double left = begin;
    if (fabs(polynomial(left)) < 1e-10) {
        printf("方程的根：%.8f\n", left);
        return 0;
    }
    while (left < end) {
        double right = fmin(left + 0.01, end);
        double f_right = polynomial(right);
        if (fabs(f_right) < 1e-10) {
            printf("方程的根：%.8f\n", right);
            return 0;
        }
        if (opposite_signs(polynomial(left), f_right)) {
            printf("方程的根：%.8f\n", solve(left, right));
            return 0;
        }
        left = right;
    }
    /* 本例多项式严格递增，至多只有一个实根。 */
    puts("指定区间内没有实根。");
    return 0;
}
