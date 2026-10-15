#include <stdio.h>

void repeat(char ch, int count)
{
    for (int i = 0; i < count; i++) {
        putchar(ch);
    }
}

void print_row(int level, int height)
{
    /* 行号从1开始，每下一行少一个前导空格、多两个星号。 */
    repeat(' ', height - level);
    repeat('*', 2 * level - 1);
    putchar('\n');
}

void pyramid(int height)
{
    for (int level = 1; level <= height; level++) {
        print_row(level, height);
    }
}

void diamond(int height)
{
    pyramid(height);
    /* 下半部分从height - 1行开始，避免重复打印最宽的一行。 */
    for (int level = height - 1; level >= 1; level--) {
        print_row(level, height);
    }
}

int main(void)
{
    int height;
    printf("请输入金字塔高度（1至30）：");
    if (scanf("%d", &height) != 1 || height < 1 || height > 30) {
        puts("范围有误。");
        return 1;
    }
    puts("金字塔：");
    pyramid(height);
    puts("菱形：");
    diamond(height);
    return 0;
}
