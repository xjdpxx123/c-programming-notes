#include <stdio.h>

/* n的范围为0至20，递归使用n! = n × (n - 1)!。 */
unsigned long long factorial(int n)
{
    /* 0!和1!都为1，也是递归的终止条件。 */
    if (n == 0 || n == 1) {
        return 1;
    }
    return (unsigned int)n * factorial(n - 1);
}

int main(void)
{
    int n;
    printf("请输入一个0至20的整数：");
    if (scanf("%d", &n) != 1 || n < 0 || n > 20) {
        puts("范围有误。");
        return 1;
    }
    printf("%d! = %llu\n", n, factorial(n));
    return 0;
}
