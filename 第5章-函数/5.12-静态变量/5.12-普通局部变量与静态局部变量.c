#include <stdio.h>

int ordinary_count(void)
{
    /* 每次进入函数都会重新创建并初始化这个局部变量。 */
    int count = 0;
    return ++count;
}

int persistent_count(void)
{
    /* 静态局部变量只初始化一次，函数返回后仍保留原值。 */
    static int count = 0;
    return ++count;
}

int main(void)
{
    puts("调用次数  普通局部变量  静态局部变量");
    for (int i = 1; i <= 5; i++) {
        printf("%d         %d             %d\n", i, ordinary_count(), persistent_count());
    }
    return 0;
}
