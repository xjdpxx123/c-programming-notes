#include <stdio.h>
#include <ctype.h>

int main(void)
{
    char first[50];
    char second[50];

    printf("请输入两个单词，用空格或换行分隔（每个最多 49 字节）：\n");
    // 宽度 49 为结尾的 '\0' 留出一个位置。
    if (scanf("%49s", first) != 1) {
        printf("需要输入两个单词。\n");
        return 1;
    }
    // 若下一个字符还不是空白或 EOF，说明单词被宽度限制截断了。
    int ch = getchar();
    if (ch != EOF && !isspace((unsigned char)ch)) {
        printf("第一个单词超过了 49 字节。\n");
        return 1;
    }
    if (scanf("%49s", second) != 1) {
        printf("需要输入两个单词。\n");
        return 1;
    }
    ch = getchar();
    if (ch != EOF && !isspace((unsigned char)ch)) {
        printf("第二个单词超过了 49 字节。\n");
        return 1;
    }
    printf("第一个字符串：%s\n第二个字符串：%s\n", first, second);
    return 0;
}
