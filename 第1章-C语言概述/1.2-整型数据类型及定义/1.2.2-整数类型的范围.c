#include <stdio.h>
#include <limits.h>

int main(void)
{
    // 类型的大小与实现有关，用 sizeof 和 limits.h 查看当前环境。
    printf("一个字节有 %d 个二进制位\n", CHAR_BIT);
    printf("short: %zu 字节，范围 %d 到 %d\n", sizeof(short), SHRT_MIN, SHRT_MAX);
    printf("int: %zu 字节，范围 %d 到 %d\n", sizeof(int), INT_MIN, INT_MAX);
    printf("long: %zu 字节，范围 %ld 到 %ld\n", sizeof(long), LONG_MIN, LONG_MAX);
    printf("unsigned int: %zu 字节，范围 0 到 %u\n", sizeof(unsigned int), UINT_MAX);
    return 0;
}
