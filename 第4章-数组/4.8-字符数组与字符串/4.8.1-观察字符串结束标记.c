#include <stdio.h>

int main(void)
{
    char string[] = "abcde";  // 字符串字面量末尾自动补上 '\0'，共占六个元素。
    char characters[] = {'a', 'b', 'c', 'd', 'e'};
    char shortened[] = "abcdefg";

    printf("字符串占 %zu 字节，普通字符数组占 %zu 字节。\n",
           sizeof(string), sizeof(characters));
    for (size_t i = 0; i < sizeof(string); i++) {
        printf("string[%zu] 的编码为 %u\n", i, (unsigned int)(unsigned char)string[i]);
    }
    // %s 遇到第一个 '\0' 就停止，后面的数组元素仍然存在。
    shortened[4] = '\0';
    printf("按字符串输出：%s\n", shortened);
    printf("逐个查看前七个元素：\n");
    for (size_t i = 0; i < 7; i++) {
        if (shortened[i] == '\0') {
            printf("[%zu] = '\\0'\n", i);
        } else {
            printf("[%zu] = '%c'\n", i, shortened[i]);
        }
    }
    return 0;
}
