#include <stdio.h>

int main(void)
{
    char first[101];
    char second[101];
    size_t i = 0;

    printf("请输入第一个字符串（最多 100 字节）：\n");
    if (fgets(first, sizeof(first), stdin) == NULL) {
        printf("未读到输入。\n");
        return 1;
    }
    {
        size_t end = 0;
        while (first[end] != '\0' && first[end] != '\n') {
            end++;
        }
        if (first[end] == '\n') {
            first[end] = '\0';
        } else {
            int ch = getchar();
            if (ch != '\n' && ch != EOF) {
                printf("这一行太长，请缩短后再试。\n");
                return 1;
            }
        }
    }

    printf("请输入第二个字符串（最多 100 字节）：\n");
    if (fgets(second, sizeof(second), stdin) == NULL) {
        printf("未读到输入。\n");
        return 1;
    }
    {
        size_t end = 0;
        while (second[end] != '\0' && second[end] != '\n') {
            end++;
        }
        if (second[end] == '\n') {
            second[end] = '\0';
        } else {
            int ch = getchar();
            if (ch != '\n' && ch != EOF) {
                printf("这一行太长，请缩短后再试。\n");
                return 1;
            }
        }
    }

    // 跳过相同的前缀，第一个不同的字节（也可能是 '\0'）决定大小。
    while (first[i] != '\0' && first[i] == second[i]) {
        i++;
    }
    // 与 strcmp 一样，按无符号字节比较；不是按汉字拼音排序。
    unsigned char left = (unsigned char)first[i];
    unsigned char right = (unsigned char)second[i];
    if (left > right) {
        printf("第一个字符串大于第二个字符串。\n");
    } else if (left < right) {
        printf("第一个字符串小于第二个字符串。\n");
    } else {
        printf("两个字符串相等。\n");
    }
    return 0;
}
