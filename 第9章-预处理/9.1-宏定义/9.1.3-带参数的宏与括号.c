#include <stdio.h>

/* 参数各加括号，整个表达式再加括号，保留预期的运算次序。 */
#define DIFFERENCE(x, y) ((x) - (y))
/* 故意省略括号，用来观察替换后的运算次序。 */
#define BAD_DIFFERENCE(x, y) x - y

int main(void)
{
    int a = 9;
    int b = 3;

    printf("DIFFERENCE(a, b) = %d\n", DIFFERENCE(a, b));
    printf("DIFFERENCE(3 + 8, b - a) = %d\n", DIFFERENCE(3 + 8, b - a));
    /* 这里展开为 3 + 8 - b - a，与 (3 + 8) - (b - a) 不同。 */
    printf("BAD_DIFFERENCE(3 + 8, b - a) = %d\n", BAD_DIFFERENCE(3 + 8, b - a));
    printf("2 * DIFFERENCE(a, b) = %d\n", 2 * DIFFERENCE(a, b));
    return 0;
}
