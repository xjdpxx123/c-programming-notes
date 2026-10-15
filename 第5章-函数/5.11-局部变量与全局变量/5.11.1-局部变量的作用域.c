#include <stdio.h>

int value = 100;

void show_local(int a)
{
    int k = a + 1;
    printf("show_local中的k = %d\n", k);
}

void show_global(void)
{
    printf("全局变量value = %d\n", value);
}

int main(void)
{
    /* 这个局部变量遮蔽同名全局变量，show_global中仍使用全局变量。 */
    int value = 5;
    show_local(value);
    printf("main中的局部变量value = %d\n", value);
    {
        /* inside的作用域仅限于这一对花括号。 */
        int inside = 20;
        printf("语句块内的inside = %d\n", inside);
    }
    show_global();
    return 0;
}
