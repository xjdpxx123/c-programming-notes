#include <stdio.h>

int main(void)
{
    int first = 1;
    int second = 1;
    int i = 3;

    printf("%9d%9d", first, second);
    while (i <= 20) {
        int next = first + second;
        printf("%9d", next);
        if (i % 5 == 0) {
            printf("\n");
        }
        // 保留相邻的两项，供下一轮相加；更新顺序不能颠倒。
        first = second;
        second = next;
        i++;
    }
    return 0;
}
