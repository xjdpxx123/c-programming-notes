#include <stdio.h>

int main(void)
{
    char first[201];  // 两段各 100 字节的文字，加一个字符串结束标记。
    char second[101];
    size_t i = 0;
    size_t k = 0;

    printf("请输入第一个字符串（最多 100 字节）：\n");
    if (fgets(first, 101, stdin) == NULL) {
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

    while (first[i] != '\0') {
        i++;
    }
    // i 停在第一段的结束标记处，从这里开始覆盖并接入第二段。
    while (second[k] != '\0') {
        first[i] = second[k];
        i++;
        k++;
    }
    first[i] = '\0';  // 复制字符后，在新的末尾补上结束标记。
    printf("连接结果：%s\n", first);
    return 0;
}
