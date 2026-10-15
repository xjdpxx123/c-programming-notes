#include <stdio.h>
#include <string.h>

/* begin从1开始，按字节截取，适合本例的英文字符串。 */
int substring(const char *source, char *destination, size_t capacity, size_t begin, size_t count)
{
    size_t length = strlen(source);
    if (capacity == 0 || begin == 0) {
        return 0;
    }
    if (begin > length || count == 0) {
        destination[0] = '\0';
        return 1;
    }
    size_t available = length - (begin - 1);
    if (count > available) {
        count = available;
    }
    /* 复制count个字节后，还要为结尾的'\0'留出一个字节。 */
    if (count >= capacity) {
        return 0;
    }
    source += begin - 1;
    for (size_t i = 0; i < count; i++) {
        *destination++ = *source++;
    }
    *destination = '\0';
    return 1;
}

int left_string(const char *source, char *destination, size_t capacity, size_t count)
{
    return substring(source, destination, capacity, 1, count);
}

int right_string(const char *source, char *destination, size_t capacity, size_t count)
{
    size_t length = strlen(source);
    if (count > length) {
        count = length;
    }
    return substring(source, destination, capacity, length - count + 1, count);
}

int main(void)
{
    const char source[] = "abcdefghijklmn";
    char result[50];
    int begin, count;

    printf("原字符串：%s\n", source);
    printf("请输入起始位置（从1开始）和截取长度（0至1000）：");
    if (scanf("%d%d", &begin, &count) != 2 || begin < 1 || begin > 1000 || count < 0 || count > 1000) {
        puts("位置或长度有误。");
        return 1;
    }
    if (!substring(source, result, sizeof(result), (size_t)begin, (size_t)count)) {
        puts("目标数组空间不足。");
        return 1;
    }
    printf("从第%d个字符开始：\"%s\"\n", begin, result);
    if (!left_string(source, result, sizeof(result), (size_t)count)) {
        return 1;
    }
    printf("左侧%d个字符：\"%s\"\n", count, result);
    if (!right_string(source, result, sizeof(result), (size_t)count)) {
        return 1;
    }
    printf("右侧%d个字符：\"%s\"\n", count, result);
    return 0;
}
