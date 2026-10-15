#include <stdio.h>

/* 数组形参不携带元素个数，length由调用者另行传入。 */
int sum(const int values[], int length)
{
    int total = 0;
    for (int i = 0; i < length; i++) {
        total += values[i];
    }
    return total;
}

int main(void)
{
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    printf("整个数组的和：%d\n", sum(a, 10));
    /* 从a[2]开始传入三个元素，函数内下标仍从0开始。 */
    printf("a[2]至a[4]的和：%d\n", sum(&a[2], 3));
    return 0;
}
