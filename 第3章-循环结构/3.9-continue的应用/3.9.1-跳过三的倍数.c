#include <stdio.h>

int main(void)
{
    int i = 0;

    while (i < 10) {
        i++;  // 放在 continue 前，确保循环变量每次都变化。
        if (i % 3 == 0) {
            continue;
        }
        printf("%d ", i);
    }
    printf("\n");
    return 0;
}
