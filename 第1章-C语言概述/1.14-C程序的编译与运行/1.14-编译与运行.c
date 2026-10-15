#include <stdio.h>

int main(void)
{
    int a = 123;
    int b = 456;

    // 修改数值后重新编译，再观察结果。
    printf("%d + %d = %d\n", a, b, a + b);
    return 0;
}
