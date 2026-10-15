#include <stdio.h>
#include <string.h>

/* source和destination应指向不重叠的字符串；capacity是目标数组的总容量。 */
int append_by_index(char *destination, size_t capacity, const char *source)
{
    size_t length = strlen(destination);
    /* 剩余空间既要容纳source的内容，也要容纳最后的'\0'。 */
    if (length >= capacity || strlen(source) >= capacity - length) {
        return 0;
    }
    size_t i = 0;
    while (source[i] != '\0') {
        destination[length + i] = source[i];
        i++;
    }
    destination[length + i] = '\0';
    return 1;
}

int append_by_pointer(char *destination, size_t capacity, const char *source)
{
    size_t length = strlen(destination);
    if (length >= capacity || strlen(source) >= capacity - length) {
        return 0;
    }
    /* 从原字符串的结束标志处开始写入，最后再补上新的结束标志。 */
    destination += length;
    while (*source != '\0') {
        *destination++ = *source++;
    }
    *destination = '\0';
    return 1;
}

int main(void)
{
    char first[100] = "abc";
    char second[100] = "abc";
    char third[100] = "abc";
    const char source[] = "123";

    if (strlen(first) + strlen(source) < sizeof(first)) {
        strcat(first, source);
        printf("库函数连接：%s\n", first);
    }
    if (append_by_index(second, sizeof(second), source)) {
        printf("下标法连接：%s\n", second);
    }
    if (append_by_pointer(third, sizeof(third), source)) {
        printf("指针法连接：%s\n", third);
    }
    return 0;
}
