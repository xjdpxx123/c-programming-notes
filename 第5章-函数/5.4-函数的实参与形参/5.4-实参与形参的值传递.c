#include <stdio.h>

void change_value(int n)
{
    printf("形参接收的值：n = %d\n", n);
    /* n是实参值的副本，给n赋值不会改变main中的m。 */
    n = 78;
    printf("修改形参后：n = %d\n", n);
}

int main(void)
{
    int m;
    printf("请输入一个整数：");
    if (scanf("%d", &m) != 1) {
        puts("输入有误。");
        return 1;
    }
    change_value(m);
    printf("调用结束后：m = %d\n", m);
    return 0;
}
