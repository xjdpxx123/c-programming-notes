#include <stdio.h>

int main(void)
{
    int a;
    char c;

    // sizeof 是运算符，这里不会读取变量的值。
    // 结果的类型是 size_t，输出时使用 %zu。
    printf("整型变量的字节数为：%zu\n", sizeof(a));
    printf("字符变量的字节数为：%zu\n", sizeof(c));
    printf("整型的字节数为：%zu\n", sizeof(int));
    printf("字符类型的字节数为：%zu\n", sizeof(char));
    return 0;
}
