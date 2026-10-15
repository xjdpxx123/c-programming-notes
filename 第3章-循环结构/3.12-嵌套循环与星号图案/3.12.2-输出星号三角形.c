#include <stdio.h>

int main(void)
{
    int rows;
    int row = 1;

    printf("请输入行数（1 到 40）：");
    if (scanf("%d", &rows) != 1 || rows < 1 || rows > 40) {
        printf("行数必须是 1 到 40 之间的整数。\n");
        return 1;
    }
    while (row <= rows) {
        int column = 1;
        // 第 row 行输出 2 * row - 1 个星号，每行比上一行多两个。
        while (column <= 2 * row - 1) {
            putchar('*');
            column++;
        }
        putchar('\n');
        row++;
    }
    return 0;
}
