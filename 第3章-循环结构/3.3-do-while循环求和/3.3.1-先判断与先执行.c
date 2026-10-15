#include <stdio.h>

int main(void)
{
    int i;

    printf("初值为 5，while 循环的输出：\n");
    i = 5;
    // 第一次判断就不成立，循环体一次也不执行。
    while (i < 5) {
        printf("%d\n", i);
        i++;
    }

    printf("初值为 5，do...while 循环的输出：\n");
    i = 5;
    // 先执行循环体再判断条件，因此会输出一次 5。
    do {
        printf("%d\n", i);
        i++;
    } while (i < 5);
    return 0;
}
