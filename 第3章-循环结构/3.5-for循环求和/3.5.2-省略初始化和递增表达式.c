#include <stdio.h>

int main(void)
{
    int i = 1;
    int sum = 0;

    // 初始化移到循环前，两个分号仍须保留。
    for (; i <= 100; i++) {
        sum += i;
    }
    printf("省略初始化表达式：%d\n", sum);

    sum = 0;
    for (i = 1; i <= 100;) {
        sum += i;
        i++;  // 递增操作移到循环体中。
    }
    printf("省略递增表达式：%d\n", sum);
    return 0;
}
