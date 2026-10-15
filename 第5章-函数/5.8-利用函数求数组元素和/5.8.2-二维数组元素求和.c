#include <stdio.h>

#define ROWS 3
#define COLS 4

/* 二维数组形参必须给出列数，才能确定下一行的起始位置。 */
int sum(int values[][COLS], int rows)
{
    int total = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < COLS; j++) {
            total += values[i][j];
        }
    }
    return total;
}

int main(void)
{
    int a[ROWS][COLS] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    printf("二维数组的元素和：%d\n", sum(a, ROWS));
    return 0;
}
