#include <stdio.h>

int main(void)
{
    int n;
    unsigned long result = 1;  // 从 1 开始累乘；n 为 0 时保留 0! = 1。

    printf("请输入 0 到 12 之间的整数：");
    // 12! 可用 32 位 unsigned long 保存，13! 会超出其范围。
    if (scanf("%d", &n) != 1 || n < 0 || n > 12) {
        printf("输入有误，阶乘的计算范围为 0 到 12。\n");
        return 1;
    }

    for (int i = 1; i <= n; i++) {
        result *= (unsigned long)i;
    }
    printf("%d! = %lu\n", n, result);
    return 0;
}
