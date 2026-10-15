#include <stdio.h>

/* 调用前先声明，函数定义可以放在main后面。 */
int sum(int begin, int end);

int main(void)
{
    int begin = 5;
    int end = 86;
    printf("从%d连加到%d的和为%d\n", begin, end, sum(begin, end));
    return 0;
}

int sum(int begin, int end)
{
    int total = 0;
    for (int i = begin; i <= end; i++) {
        total += i;
    }
    return total;
}
