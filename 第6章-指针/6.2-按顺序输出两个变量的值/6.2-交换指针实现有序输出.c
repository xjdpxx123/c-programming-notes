#include <stdio.h>

int main(void)
{
    int a, b;
    printf("请输入两个整数：");
    if (scanf("%d%d", &a, &b) != 2) {
        puts("输入有误。");
        return 1;
    }

    int *smaller = &a;
    int *larger = &b;
    /* 只交换指针保存的地址，a和b中的数值保持不变。 */
    if (*smaller > *larger) {
        int *temp = smaller;
        smaller = larger;
        larger = temp;
    }
    printf("从小到大：%d %d\n", *smaller, *larger);
    printf("原变量：a = %d，b = %d\n", a, b);
    return 0;
}
