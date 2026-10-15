#include <stdio.h>

int main(void)
{
    int a = 5;
    int b;

    // 后置表达式的值是修改前的 a，所以 b 得到 5。
    b = a++;
    printf("b = a++ 后：a = %d，b = %d\n", a, b);
    a = 5;
    // 前置表达式的值是修改后的 a，所以 b 得到 6。
    b = ++a;
    printf("b = ++a 后：a = %d，b = %d\n", a, b);
    a = 5;
    b = a--;
    printf("b = a-- 后：a = %d，b = %d\n", a, b);
    a = 5;
    b = --a;
    printf("b = --a 后：a = %d，b = %d\n", a, b);
    // 修改 a 和读取 a 分开写，避免依赖表达式的求值顺序。
    return 0;
}
