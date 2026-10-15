#include <stdio.h>

int main(void)
{
    char text[] = {'I', ' ', 'a', 'm', ' ', 'h', 'a', 'p', 'p', 'y'};

    printf("数组有 %zu 个字符元素。\n", sizeof(text) / sizeof(text[0]));
    for (size_t i = 0; i < sizeof(text); i++) {
        printf("text[%zu] 的地址：%p，字符：'%c'\n", i, (void *)&text[i], text[i]);
    }
    printf("逐个输出字符：");
    // 此数组没有字符串结束标记，应逐个输出，不能使用 %s。
    for (size_t i = 0; i < sizeof(text); i++) {
        putchar(text[i]);
    }
    putchar('\n');
    return 0;
}
