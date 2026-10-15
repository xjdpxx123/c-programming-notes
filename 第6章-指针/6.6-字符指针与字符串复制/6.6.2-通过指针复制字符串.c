#include <stdio.h>
#include <string.h>

/* 容量包括结尾的空字符，空间不足时不修改目标数组。 */
int copy_string(char *destination, size_t capacity, const char *source)
{
    if (strlen(source) >= capacity) {
        return 0;
    }
    while (*source != '\0') {
        /* 先复制当前字符，再将两个指针各向后移动一个位置。 */
        *destination++ = *source++;
    }
    *destination = '\0';
    return 1;
}

int main(void)
{
    char source[50] = "abcdefg";
    char destination[50];
    char small[4] = "abc";

    if (copy_string(destination, sizeof(destination), source)) {
        printf("复制结果：%s\n", destination);
    }
    if (!copy_string(small, sizeof(small), source)) {
        printf("目标数组空间不足，原内容为：%s\n", small);
    }
    return 0;
}
