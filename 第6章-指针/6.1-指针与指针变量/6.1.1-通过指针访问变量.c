#include <stdio.h>

int main(void)
{
    int a;
    int *p = &a;  /* p保存a的地址，*p访问的就是a。 */

    printf("变量a的地址：%p\n", (void *)&a);
    printf("指针p保存的地址：%p\n", (void *)p);
    printf("请输入一个整数：");
    /* p已经是int变量的地址，不需要再取地址。 */
    if (scanf("%d", p) != 1) {
        puts("输入有误。");
        return 1;
    }
    printf("a = %d\n", a);
    printf("*p = %d\n", *p);
    printf("*(&a) = %d\n", *(&a));
    return 0;
}
