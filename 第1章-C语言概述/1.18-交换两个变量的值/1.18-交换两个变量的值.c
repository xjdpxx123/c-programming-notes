#include <stdio.h>

int main(void)
{
    int a, b, temp;

    printf("请输入两个整数：");
    if (scanf("%d%d", &a, &b) != 2) {
        printf("输入格式不正确。\n");
        return 1;
    }
    // 先保留 a 的旧值，否则执行 a = b 后就无法找回它。
    temp = a;
    a = b;
    b = temp;
    printf("交换后：a = %d，b = %d\n", a, b);
    return 0;
}
