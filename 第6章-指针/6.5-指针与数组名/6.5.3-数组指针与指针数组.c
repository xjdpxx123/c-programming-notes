#include <stdio.h>

int main(void)
{
    int matrix[3][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    int (*row)[4] = matrix;  /* 一个指针，指向含4个int元素的数组。 */
    /* 一个含4个元素的数组，每个元素都是int指针。 */
    int *elements[4] = {&matrix[0][0], &matrix[1][1], &matrix[2][2], &matrix[2][3]};

    puts("数组指针每次移动一整行：");
    for (int i = 0; i < 3; i++, row++) {
        for (int j = 0; j < 4; j++) {
            printf("%d%s", (*row)[j], j == 3 ? "\n" : " ");
        }
    }
    printf("指针数组保存的四个元素：");
    for (int i = 0; i < 4; i++) {
        printf("%d%s", *elements[i], i == 3 ? "\n" : " ");
    }
    return 0;
}
