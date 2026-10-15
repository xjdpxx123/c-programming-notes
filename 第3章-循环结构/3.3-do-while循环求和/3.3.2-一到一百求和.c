#include <stdio.h>

int main(void)
{
    int i = 1;
    int sum = 0;

    // 加入第 100 项后，i 增为 101，循环才结束。
    do {
        sum += i;
        i++;
    } while (i <= 100);
    printf("1 + 2 + ... + 100 = %d\n", sum);
    return 0;
}
