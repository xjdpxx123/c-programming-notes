#include <stdio.h>

int main(void)
{
    int numbers[] = {10, 20, 30};
    char letters[] = {'a', 'b', 'c'};
    int *p = numbers;
    char *q = letters;

    printf("一个int占%zu字节，一个char占%zu字节。\n", sizeof(int), sizeof(char));
    /* 指针加1前进一个所指类型的元素，跨过的字节数由类型决定。 */
    for (int i = 0; i < 3; i++) {
        printf("p + %d = %p，值为%d\n", i, (void *)(p + i), *(p + i));
        printf("q + %d = %p，值为%c\n", i, (void *)(q + i), *(q + i));
    }
    printf("(p + 2) - p = %td，指针相减得到元素间距。\n", (p + 2) - p);
    return 0;
}
