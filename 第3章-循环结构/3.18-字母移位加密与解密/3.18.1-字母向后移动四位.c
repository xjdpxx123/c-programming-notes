#include <stdio.h>

int main(void)
{
    int ch;

    printf("请输入一行文字：\n");
    while ((ch = getchar()) != '\n' && ch != EOF) {
        // 先换成 0 到 25 的序号，取余使末尾字母绕回开头。
        if (ch >= 'A' && ch <= 'Z') {
            ch = 'A' + (ch - 'A' + 4) % 26;
        } else if (ch >= 'a' && ch <= 'z') {
            ch = 'a' + (ch - 'a' + 4) % 26;
        }
        putchar(ch);
    }
    putchar('\n');
    return 0;
}
