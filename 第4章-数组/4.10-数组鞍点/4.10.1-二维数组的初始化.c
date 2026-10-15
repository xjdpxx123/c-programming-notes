#include <stdio.h>

int main(void)
{
    int first[3][5] = {{0, 1, 2}, {3, 4, 5, 6}, {7, 8}};
    int second[3][5] = {{0, 1, 2, 3, 4}, {5, 6, 7, 8, 9}, {10}};
    // 行数可由初值推算，列数仍须给出，才能确定每一行的大小。
    int third[][4] = {{1, 2, 3}, {4, 5}, {6, 7, 8}};

    printf("部分初始化，未列出的元素为 0：\n");
    for (int row = 0; row < 3; row++) {
        for (int column = 0; column < 5; column++) {
            printf("%4d", first[row][column]);
        }
        printf("\n");
    }
    printf("按行连续存放 0 到 10：\n");
    for (int row = 0; row < 3; row++) {
        for (int column = 0; column < 5; column++) {
            printf("%4d", second[row][column]);
        }
        printf("\n");
    }
    printf("省略第一维长度，共 %zu 行：\n", sizeof(third) / sizeof(third[0]));
    for (int row = 0; row < 3; row++) {
        for (int column = 0; column < 4; column++) {
            printf("%4d", third[row][column]);
        }
        printf("\n");
    }
    return 0;
}
