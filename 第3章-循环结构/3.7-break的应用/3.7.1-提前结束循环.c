#include <stdio.h>

int main(void)
{
    int i = 1;

    while (i <= 5) {
        printf("i = %d\n", i);
        // i 为 3 时已完成输出，break 会跳过后面的 i++。
        if (i > 2) {
            break;
        }
        i++;
    }
    printf("循环结束，i = %d。\n", i);
    return 0;
}
