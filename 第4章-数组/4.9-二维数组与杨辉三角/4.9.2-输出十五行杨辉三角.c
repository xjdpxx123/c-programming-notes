#include <stdio.h>

int main(void)
{
    int triangle[15][15] = {0};

    for (int row = 0; row < 15; row++) {
        // 每行两端为 1；第 0 行的两端是同一个元素。
        triangle[row][0] = 1;
        triangle[row][row] = 1;
        // 中间各项等于上一行左上方和正上方两项之和。
        for (int column = 1; column < row; column++) {
            triangle[row][column] = triangle[row - 1][column - 1]
                                    + triangle[row - 1][column];
        }
    }
    for (int row = 0; row < 15; row++) {
        for (int column = 0; column <= row; column++) {
            printf("%5d", triangle[row][column]);
        }
        printf("\n");
    }
    return 0;
}
