#include <stdio.h>

int main(void)
{
    int a = 5;

    // 关系表达式成立时结果为 1，不成立时为 0。
    printf("5 > 3：%d\n", 5 > 3);
    printf("9 < 12：%d\n", 9 < 12);
    printf("5 >= 5：%d\n", 5 >= 5);
    printf("5 <= 3：%d\n", 5 <= 3);
    printf("5 != 3：%d\n", 5 != 3);
    printf("a == 9：%d\n", a == 9);
    printf("比较之后 a = %d\n", a);
    // == 只比较，= 会赋值；这里先给 a 赋值，再输出赋值表达式的值。
    printf("a = 9 的表达式值：%d\n", (a = 9));
    printf("赋值之后 a = %d\n", a);
    return 0;
}
