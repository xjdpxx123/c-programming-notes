#include <stdio.h>

int main(void)
{
    int numbers[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // 只需交换前一半，否则会再次换回原来的顺序。
    for (int i = 0; i < 10 / 2; i++) {
        int temp = numbers[i];
        numbers[i] = numbers[9 - i];
        numbers[9 - i] = temp;
    }
    printf("交换后的数组：\n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n数组中第一个元素变为 %d。\n", numbers[0]);
    return 0;
}
