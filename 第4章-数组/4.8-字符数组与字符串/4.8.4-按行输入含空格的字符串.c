#include <stdio.h>

int main(void)
{
    char first[101];
    char second[101];

    printf("请输入第一行（最多 100 字节，可含空格）：\n");
    // fgets 保留空格；读到换行符时也会把它存入数组。
    if (fgets(first, sizeof(first), stdin) == NULL) {
        printf("未读到输入。\n");
        return 1;
    }
    {
        size_t end = 0;
        while (first[end] != '\0' && first[end] != '\n') {
            end++;
        }
        // 去掉换行符，使后面的 %s 只输出文字本身。
        if (first[end] == '\n') {
            first[end] = '\0';
        } else {
            // 数组里没有换行符时，再读一个字符以区分恰好装满和超长。
            int ch = getchar();
            if (ch != '\n' && ch != EOF) {
                printf("这一行太长，请缩短后再试。\n");
                return 1;
            }
        }
    }

    printf("请输入第二行（最多 100 字节，可含空格）：\n");
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

    printf("第一行：%s\n第二行：%s\n", first, second);
    return 0;
}
