#include <stdio.h>

int main(void)
{
    printf("三位水仙花数：\n");
    for (int number = 100; number <= 999; number++) {
        int hundreds = number / 100;
        int tens = number / 10 % 10;
        int units = number % 10;
        // 三位数等于各位数字的立方和时，就是三位水仙花数。
        if (hundreds * hundreds * hundreds + tens * tens * tens +
            units * units * units == number) {
            printf("%d ", number);
        }
    }
    printf("\n");
    return 0;
}
