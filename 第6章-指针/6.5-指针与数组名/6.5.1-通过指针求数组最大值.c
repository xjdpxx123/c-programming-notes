#include <stdio.h>

/* 调用时必须提供至少一个元素。 */
int array_max(const int *values, int length)
{
    /* 用实际元素初始化，数组中全为负数时也能正确比较。 */
    int largest = values[0];
    for (int i = 1; i < length; i++) {
        if (*(values + i) > largest) {
            largest = *(values + i);
        }
    }
    return largest;
}

int main(void)
{
    int a[] = {5, 8, 9, 6, 15, 23, 7, 99, 105, 2};
    printf("数组的最大值：%d\n", array_max(a, 10));
    return 0;
}
