#include <stdio.h>

void change_target(int *p)
{
    /* 修改所指对象，调用者的变量随之改变。 */
    *p = 99;
}

void change_local_pointer(int *p)
{
    int local = 0;
    /* 指针也按值传递，改变形参p的指向不改变main中的p。 */
    p = &local;
    *p = 88;
    printf("函数内的局部变量：%d\n", local);
}

int main(void)
{
    int a = 36;
    int *p = &a;

    change_local_pointer(p);
    printf("改变形参指向后：a = %d\n", a);
    change_target(p);
    printf("改变所指变量后：a = %d\n", a);
    printf("主函数的p仍指向a：%s\n", p == &a ? "是" : "否");
    return 0;
}
