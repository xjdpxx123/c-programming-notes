#include <stdio.h>

int main(void)
{
    int a, b;

    printf("请输入两个整数，用英文逗号分隔，例如 10,20：");
    // 格式串中的普通逗号必须与输入中的逗号匹配，不能用空格替代。
    if (scanf("%d,%d", &a, &b) != 2) {
        printf("输入格式不正确，请使用英文逗号。\n");
        return 1;
    }
    printf("a = %d，b = %d\n", a, b);
    return 0;
}
