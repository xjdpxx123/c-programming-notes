#include <stdio.h>

int main(void)
{
    int a = 35;
    int b = 0;
    int result;

    printf("a 在 20 与 100 之间：%d\n", a > 20 && a < 100);
    printf("a 小于 20 或大于 100：%d\n", a < 20 || a > 100);
    printf("a 不大于 5：%d\n", !(a > 5));
    // 左侧已决定结果时，右侧不会求值。
    result = (a < 20) && (++b > 0);
    printf("逻辑与的结果：%d，b = %d\n", result, b);
    result = (a > 20) || (++b > 0);
    printf("逻辑或的结果：%d，b = %d\n", result, b);
    return 0;
}
