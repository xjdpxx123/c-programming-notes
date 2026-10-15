#include <stdio.h>

int main(void)
{
    char x = 'B';

    // 从 case 'B' 进入后，后续分支不会重新检查 x 的值。
    switch (x) {
        case 'A':
            printf("It is A.\n");
            /* fall through：此处有意省略 break。 */
        case 'B':
            printf("It is B.\n");
            /* fall through */
        case 'C':
            printf("It is C.\n");
            /* fall through */
        default:
            printf("other.\n");
    }
    return 0;
}
