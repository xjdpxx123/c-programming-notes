#include <stdio.h>
#include <string.h>

int main(void)
{
    char first[100] = "你好，";
    char second[] = "欢迎学习C语言";

    printf("连接前的字节数：%zu、%zu。\n", strlen(first), strlen(second));
    // 两段文字之外，还要给末尾的 '\0' 留一个字节。
    if (strlen(first) + strlen(second) >= sizeof(first)) {
        printf("目标数组空间不足。\n");
        return 1;
    }
    // 将第二个字符串接到第一个字符串的末尾。
    strcat(first, second);
    puts(first);
    printf("连接后的字节数：%zu。\n", strlen(first));
    printf("strcmp(\"abc\", \"abc\") = %d\n", strcmp("abc", "abc"));
    printf("strcmp(\"abc\", \"abd\") < 0：%d\n", strcmp("abc", "abd") < 0);
    return 0;
}
