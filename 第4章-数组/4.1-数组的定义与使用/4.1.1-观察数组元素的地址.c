#include <stdio.h>

int main(void)
{
    int numbers[5] = {0};

    // 数组元素连续存放，相邻元素的地址相差一个 int 的大小。
    for (int i = 0; i < 5; i++) {
        printf("numbers[%d] 的地址：%p\n", i, (void *)&numbers[i]);
    }
    printf("数组首元素地址：%p\n", (void *)numbers);
    printf("每个元素占 %zu 字节。\n", sizeof(numbers[0]));
    return 0;
}
