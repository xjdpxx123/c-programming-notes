#include <stdio.h>

int main(void)
{
    int matrix[5][5] = {
        {9, 8, 7, 6, 5},
        {5, 5, 3, 2, 1},
        {7, 6, 5, 4, 3},
        {8, 7, 6, 5, 4},
        {6, 5, 4, 3, 2}
    };
    int count = 0;

    printf("矩阵：\n");
    for (int row = 0; row < 5; row++) {
        for (int column = 0; column < 5; column++) {
            printf("%4d", matrix[row][column]);
        }
        printf("\n");
    }
    for (int row = 0; row < 5; row++) {
        int maximum = matrix[row][0];
        for (int column = 1; column < 5; column++) {
            if (matrix[row][column] > maximum) {
                maximum = matrix[row][column];
            }
        }
        // 行最大值可能不止一个，每一个都要检查。
        for (int column = 0; column < 5; column++) {
            if (matrix[row][column] == maximum) {
                int k;
                // 鞍点还须是所在列的最小值；相等的元素不会使它失去资格。
                for (k = 0; k < 5; k++) {
                    if (matrix[k][column] < maximum) {
                        break;
                    }
                }
                if (k == 5) {
                    printf("鞍点：第 %d 行第 %d 列，值为 %d。\n",
                           row + 1, column + 1, maximum);
                    count++;
                }
            }
        }
    }
    if (count == 0) {
        printf("这个矩阵没有鞍点。\n");
    } else {
        printf("共有 %d 个鞍点。\n", count);
    }
    return 0;
}
