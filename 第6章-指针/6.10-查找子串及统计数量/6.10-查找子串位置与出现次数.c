#include <stddef.h>
#include <stdio.h>
#include <string.h>

/* 找到时返回从1开始的位置，找不到或子串为空时返回-1。 */
ptrdiff_t find_substring(const char *text, const char *pattern)
{
    if (*pattern == '\0') {
        return -1;
    }
    for (const char *start = text; *start != '\0'; start++) {
        const char *p = start;
        const char *q = pattern;
        while (*p != '\0' && *q != '\0' && *p == *q) {
            p++;
            q++;
        }
        /* 子串已全部匹配；主串在此处不必结束。 */
        if (*q == '\0') {
            return start - text + 1;
        }
    }
    return -1;
}

/* 不重复使用已匹配的字符，例如aaaa中的aa计为2次。 */
int count_substrings(const char *text, const char *pattern)
{
    int count = 0;
    size_t length = strlen(pattern);
    if (length == 0) {
        return 0;
    }
    ptrdiff_t position = find_substring(text, pattern);
    while (position > 0) {
        count++;
        text += (size_t)(position - 1) + length;
        position = find_substring(text, pattern);
    }
    return count;
}

void show_result(const char *text, const char *pattern)
{
    printf("在\"%s\"中查找\"%s\"：位置%td，数量%d\n",
           text, pattern, find_substring(text, pattern), count_substrings(text, pattern));
}

int main(void)
{
    show_result("abcabcab", "abc");
    show_result("abcdefg", "cde");
    show_result("aaaa", "aa");
    show_result("abcdefg", "xyz");
    show_result("abcdefg", "efg");
    show_result("abc", "");
    return 0;
}
