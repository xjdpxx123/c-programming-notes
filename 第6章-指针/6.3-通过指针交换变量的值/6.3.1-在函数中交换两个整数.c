#include <stdio.h>

void swap(int *first, int *second)
{
    /* 通过两个地址访问原变量，因此交换结果会保留到函数返回后。 */
    int temp = *first;
    *first = *second;
    *second = temp;
}

int main(void)
{
    int a, b;
    printf("请输入两个整数：");
    if (scanf("%d%d", &a, &b) != 2) {
        puts("输入有误。");
        return 1;
    }
    printf("交换前：a = %d，b = %d\n", a, b);
    swap(&a, &b);
    printf("交换后：a = %d，b = %d\n", a, b);
    return 0;
}
