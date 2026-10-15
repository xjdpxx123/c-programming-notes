#include <stdio.h>

int main(void)
{
    int ch;  // getchar 返回 int，才能同时表示字符值和 EOF。

    printf("请输入一个字符：");
    ch = getchar();
    if (ch == EOF) {
        printf("未读到字符。\n");
        return 1;
    }
    printf("读到的字符是：");
    putchar(ch);
    putchar('\n');
    return 0;
}
