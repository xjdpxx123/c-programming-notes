#include <stdio.h>

int main(void)
{
    int matrix[3][5];

    // 第一维下标表示行，第二维下标表示列，两者都从 0 开始。
    for (int row = 0; row < 3; row++) {
        for (int column = 0; column < 5; column++) {
            matrix[row][column] = row + column;
        }
    }
    for (int row = 0; row < 3; row++) {
        for (int column = 0; column < 5; column++) {
            printf("%5d", matrix[row][column]);
        }
        printf("\n");
    }
    return 0;
}
