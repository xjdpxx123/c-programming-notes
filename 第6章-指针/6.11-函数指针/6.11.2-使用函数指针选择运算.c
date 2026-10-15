#include <stdio.h>

long long add(long long a, long long b)
{
    return a + b;
}

long long subtract(long long a, long long b)
{
    return a - b;
}

long long multiply(long long a, long long b)
{
    return a * b;
}

long long divide(long long a, long long b)
{
    return a / b;
}

int main(void)
{
    long long x, y;
    int choice;
    long long (*operation)(long long, long long);

    printf("请输入两个整数（-1000000至1000000）：");
    if (scanf("%lld%lld", &x, &y) != 2 || x < -1000000 || x > 1000000 || y < -1000000 || y > 1000000) {
        puts("整数范围有误。");
        return 1;
    }
    printf("请选择运算：1 加，2 减，3 乘，4 整数除法：");
    if (scanf("%d", &choice) != 1 || choice < 1 || choice > 4) {
        puts("请选择1至4。");
        return 1;
    }
    if (choice == 4 && y == 0) {
        puts("除数不能为0。");
        return 1;
    }
    /* 四个函数的参数和返回类型一致，可赋给同一个函数指针。 */
    if (choice == 1) {
        operation = add;
    } else if (choice == 2) {
        operation = subtract;
    } else if (choice == 3) {
        operation = multiply;
    } else {
        operation = divide;
    }
    printf("结果：%lld\n", operation(x, y));
    return 0;
}
