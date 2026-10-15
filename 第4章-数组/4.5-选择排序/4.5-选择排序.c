#include <stdio.h>

int main(void)
{
    int numbers[10] = {36, 45, 28, 74, 15, 26, 19, 98, 11, 9};

    for (int i = 0; i < 9; i++) {
        // 前 i 个元素已经有序，minimum 记录剩余部分最小元素的下标。
        int minimum = i;
        for (int k = i + 1; k < 10; k++) {
            if (numbers[k] < numbers[minimum]) {
                minimum = k;
            }
        }
        // 一趟查找结束后，再把最小元素交换到下标 i 的位置。
        int temp = numbers[i];
        numbers[i] = numbers[minimum];
        numbers[minimum] = temp;

        printf("第 %d 趟：", i + 1);
        for (int k = 0; k < 10; k++) {
            printf("%d ", numbers[k]);
        }
        printf("\n");
    }
    return 0;
}
