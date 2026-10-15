#include <stdio.h>

int main(void)
{
    int x = 1, y = 0;
    int a = 0, b = 0;

    switch (x) {
        case 1:
            switch (y) {
                case 0: a++; break;
                case 1: b++; break;
            }
            /* fall through：内层的 break 只结束内层 switch。 */
        case 2:
            a++;
            b++;
            break;
        case 3:
            a++;
            b++;
            break;
    }
    printf("a = %d，b = %d\n", a, b);
    return 0;
}
