#include <stdio.h>

int main(void)
{
    int ch;

    printf("请输入一行移位后的文字：\n");
    while ((ch = getchar()) != '\n' && ch != EOF) {
        // 先加 26 再减 4，避免前四个字母产生负的余数。
        if (ch >= 'A' && ch <= 'Z') {
            ch = 'A' + (ch - 'A' + 26 - 4) % 26;
        } else if (ch >= 'a' && ch <= 'z') {
            ch = 'a' + (ch - 'a' + 26 - 4) % 26;
        }
        putchar(ch);
    }
    putchar('\n');
    return 0;
}
