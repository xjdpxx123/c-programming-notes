#include <stdio.h>

void double_values(int *p, int count)
{
    for (int i = 0; i < count; i++) {
        p[i] *= 2;
    }
}

int main(void)
{
    int values[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    /* 从下标3开始处理5个元素，最后一个是values[7]。 */
    double_values(&values[3], 5);
    printf("加倍后的数组：");
    for (int i = 0; i < 10; i++) {
        printf("%d%s", values[i], i == 9 ? "\n" : " ");
    }
    return 0;
}
