#include <stdio.h>

int main(void)
{
    int a, b;

    printf("请输入两个整数：");
    if (scanf("%d%d", &a, &b) != 2) {
        printf("输入格式不正确。\n");
        return 1;
    }

    // 只改变输出顺序，a 和 b 保存的值没有交换。
    if (a <= b) {
        printf("从小到大：%d %d\n", a, b);
    } else {
        printf("从小到大：%d %d\n", b, a);
    }
    return 0;
}
