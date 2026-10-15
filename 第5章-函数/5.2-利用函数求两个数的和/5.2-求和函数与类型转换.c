#include <stdio.h>

int add_int(int a, int b)
{
    return a + b;
}

int add_mixed(float a, int b)
{
    return (int)(a + (float)b);
}

int add_then_truncate(float a, float b)
{
    return (int)(a + b);
}

float add_float(float a, float b)
{
    return a + b;
}

int main(void)
{
    float m = 3.9f;
    float n = 5.8f;

    printf("3 + 5 = %d\n", add_int(3, 5));
    /* 显式转换便于看清小数在哪一步被舍去。 */
    printf("两个实参转为整数：%.2f\n", (double)add_int((int)m, (int)n));
    printf("第二个实参转为整数，返回整数：%.2f\n", (double)add_mixed(m, (int)n));
    printf("先按浮点数求和，再返回整数：%.2f\n", (double)add_then_truncate(m, n));
    printf("按浮点数求和并返回：%.2f\n", (double)add_float(m, n));
    return 0;
}
