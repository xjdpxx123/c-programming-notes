#include <stdio.h>

int main(void)
{
    int i = 1;

    while (i <= 2) {
        int k = 1;  // 每轮外层循环都重新从 1 开始。
        while (k <= 3) {
            printf("%d----%d\n", i, k);
            k++;
        }
        i++;
    }
    return 0;
}
