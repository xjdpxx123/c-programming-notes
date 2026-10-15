#include <stdio.h>

int main(void)
{
    int numbers[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    printf("倒序输出：\n");
    for (int i = 9; i >= 0; i--) {
        printf("%d ", numbers[i]);
    }
    printf("\n数组中第一个元素仍为 %d。\n", numbers[0]);
    return 0;
}
