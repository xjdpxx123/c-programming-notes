#include <stdio.h>

int main(void)
{
    int matrix[10][10];
    int order;

    printf("请输入方阵阶数（1 到 10）：");
    if (scanf("%d", &order) != 1 || order < 1 || order > 10) {
        printf("阶数必须是 1 到 10 之间的整数。\n");
        return 1;
    }
    printf("请按行输入 %d 个整数：\n", order * order);
    for (int row = 0; row < order; row++) {
        for (int column = 0; column < order; column++) {
            if (scanf("%d", &matrix[row][column]) != 1) {
                printf("矩阵元素输入有误。\n");
                return 1;
            }
        }
    }
    // 列号大于行号的位置在主对角线上方，只将这部分清零。
    for (int row = 0; row < order - 1; row++) {
        for (int column = row + 1; column < order; column++) {
            matrix[row][column] = 0;
        }
    }
    printf("下三角矩阵：\n");
    for (int row = 0; row < order; row++) {
        for (int column = 0; column < order; column++) {
            printf("%6d", matrix[row][column]);
        }
        printf("\n");
    }
    return 0;
}
