#include <stdio.h>

int main(void)
{
    // float 的有效数字有限，数值较大时，相邻的整数可能无法区分。
    float value = 123456788.0f;
    double exact = 123456788.0;
    int sum = (int)(58.6 + 35.8);
    float a = 36.8f;
    // 类型转换产生一个新的值，变量 a 本身仍保留原来的值。
    float b = (float)(int)a;

    value = value + 11111.0f;
    exact = exact + 11111.0;
    printf("float 计算结果：%.0f\n", value);
    printf("double 计算结果：%.0f\n", exact);
    printf("先求和再转成 int：%d\n", sum);
    printf("a = %.1f，截去小数后的 b = %.1f\n", a, b);
    printf("负数转成 int 也向零截断：%d\n", (int)-3.8);
    return 0;
}
