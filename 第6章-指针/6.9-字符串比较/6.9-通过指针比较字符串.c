#include <stdio.h>

int compare_string(const char *first, const char *second)
{
    /* 跳过相同前缀，停在第一对不同字节或字符串末尾。 */
    while (*first != '\0' && *first == *second) {
        first++;
        second++;
    }
    /* 按无符号字节比较，与strcmp的顺序一致。 */
    unsigned char a = (unsigned char)*first;
    unsigned char b = (unsigned char)*second;
    return (a > b) - (a < b);
}

void show_comparison(const char *first, const char *second)
{
    int result = compare_string(first, second);
    printf("\"%s\" %s \"%s\"，比较结果：%d\n",
           first, result < 0 ? "<" : result > 0 ? ">" : "=", second, result);
}

int main(void)
{
    show_comparison("akcd", "aqcd");
    show_comparison("abc", "abc");
    show_comparison("abcd", "abc");
    show_comparison("", "abc");
    return 0;
}
