#include <stdio.h>

int main(void)
{
    char c;

    // 以下编码数值以 ASCII 字符集为例。
    c = 'a';
    printf("字符：%c，编码：%d\n", c, c);
    c = c + 1;
    printf("字符：%c，编码：%d\n", c, c);
    c = 99;
    printf("字符：%c，编码：%d\n", c, c);
    return 0;
}
