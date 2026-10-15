#include <stdio.h>

#define WELCOME puts("你好，欢迎学习C语言！")

int main(void)
{
    /* 预处理后，这一行会成为 puts 函数调用。 */
    WELCOME;
    return 0;
}
