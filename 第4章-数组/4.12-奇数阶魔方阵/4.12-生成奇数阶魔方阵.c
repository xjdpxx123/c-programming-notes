#include <stdio.h>

int main(void)
{
    int square[9][9] = {0};
    int order;
    int row = 0;
    int column;

    printf("请输入阶数（3、5、7 或 9）：");
    if (scanf("%d", &order) != 1 || order < 3 || order > 9 || order % 2 == 0) {
        printf("阶数必须是 3 到 9 之间的奇数。\n");
        return 1;
    }
    // 1 放在第一行的中间位置。
    column = order / 2;
    for (int value = 1; value <= order * order; value++) {
        square[row][column] = value;
        // 尝试右上方一格；越过边界时，从另一侧接着走。
        int next_row = (row + order - 1) % order;
        int next_column = (column + 1) % order;
        // 右上方已有数时，改放到当前格的正下方，列号不变。
        if (square[next_row][next_column] != 0) {
            row = (row + 1) % order;
        } else {
            row = next_row;
            column = next_column;
        }
    }
    for (row = 0; row < order; row++) {
        for (column = 0; column < order; column++) {
            printf("%4d", square[row][column]);
        }
        printf("\n");
    }
    printf("每行、每列和两条对角线的和均为 %d。\n", order * (order * order + 1) / 2);
    return 0;
}
