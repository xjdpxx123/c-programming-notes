#include <stdio.h>

#ifndef COLOR
#define COLOR 4
#endif

int main(void)
{
    /* 只保留第一个条件成立的分支，都不成立时保留 #else 分支。 */
#if COLOR == 1
    puts("已编译第一段：红色。");
#elif COLOR == 2
    puts("已编译第二段：绿色。");
#elif COLOR == 3
    puts("已编译第三段：蓝色。");
#elif COLOR == 4
    puts("已编译第四段：白色。");
#else
    puts("已编译默认段：未指定颜色。");
#endif
    return 0;
}
