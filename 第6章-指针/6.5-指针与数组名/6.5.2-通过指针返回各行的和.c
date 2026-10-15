#include <stdio.h>

/* values至少有3行、每行4列，三个结果通过指针写回调用者的变量。 */
void row_sums(double values[][4], double *first, double *second, double *third)
{
    *first = 0;
    *second = 0;
    *third = 0;
    for (int column = 0; column < 4; column++) {
        *first += values[0][column];
        *second += values[1][column];
        *third += values[2][column];
    }
}

int main(void)
{
    double values[3][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    double first, second, third;

    row_sums(values, &first, &second, &third);
    printf("三行的和：%.2f %.2f %.2f\n", first, second, third);
    return 0;
}
