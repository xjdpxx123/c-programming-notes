#include <stdio.h>

/* 参数表中的void表示无参数，函数名前的void表示无返回值。 */
void hello(void)
{
    puts("你好，欢迎学习C语言！");
}

void print_stars(int count)
{
    for (int i = 0; i < count; i++) {
        putchar('*');
    }
    putchar('\n');
}

int main(void)
{
    hello();
    print_stars(5);
    print_stars(10);
    return 0;
}
