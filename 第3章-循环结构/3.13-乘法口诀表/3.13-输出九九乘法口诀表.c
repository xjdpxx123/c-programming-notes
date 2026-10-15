#include <stdio.h>

int main(void)
{
    int row = 1;

    while (row <= 9) {
        int column = 1;
        // 每行只输出到对角线，避免重复列出交换两个乘数后的算式。
        while (column <= row) {
            printf("%d × %d = %-3d ", column, row, column * row);
            column++;
        }
        putchar('\n');
        row++;
    }
    return 0;
}
