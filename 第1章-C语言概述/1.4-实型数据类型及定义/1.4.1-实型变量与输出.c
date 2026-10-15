#include <stdio.h>

int main(void)
{
    // 小数常量默认是 double，后缀 f 和 L 分别指定 float 与 long double。
    float a = 36.8f;
    double b = 123.658;
    long double c = 0.123658e3L;

    // float 传给 printf 时提升为 double；long double 则用 %Lf 输出。
    printf("float: %.2f，%zu 字节\n", a, sizeof(a));
    printf("double: %.3f，%zu 字节\n", b, sizeof(b));
    printf("long double: %.3Lf，%zu 字节\n", c, sizeof(c));
    printf("指数形式：%e\n", b);
    return 0;
}
