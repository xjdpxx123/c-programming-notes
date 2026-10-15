#include <stdio.h>

int main(void)
{
    char text[101];
    size_t length = 0;

    printf("请输入一行文字（最多 100 字节）：\n");
    if (fgets(text, sizeof(text), stdin) == NULL) {
        printf("未读到输入。\n");
        return 1;
    }
    {
        size_t end = 0;
        while (text[end] != '\0' && text[end] != '\n') {
            end++;
        }
        if (text[end] == '\n') {
            text[end] = '\0';
        } else {
            int ch = getchar();
            if (ch != '\n' && ch != EOF) {
                printf("这一行太长，请缩短后再试。\n");
                return 1;
            }
        }
    }

    // 结束标记只表示字符串到此为止，不计入长度。
    while (text[length] != '\0') {
        length++;
    }
    // 这里统计字节数，多字节编码中的一个汉字可能占多个字节。
    printf("字符串长度为 %zu 字节。\n", length);
    return 0;
}
