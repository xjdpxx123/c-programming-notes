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
    /* 数组中的每个元素都是函数指针，排列顺序与菜单选项一致。 */
    long long (*operations[4])(long long, long long) = {add, subtract, multiply, divide};

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
    printf("结果：%lld\n", operations[choice - 1](x, y));
    return 0;
}
