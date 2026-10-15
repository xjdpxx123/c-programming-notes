#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *numbers = malloc(10 * sizeof *numbers);
    int i;

    if (numbers == NULL) {
        puts("内存申请失败。");
        return 1;
    }
    /* malloc 不负责初始化数组，读取前先逐项赋值。 */
    for (i = 0; i < 10; ++i) {
        numbers[i] = i * i;
    }
    for (i = 0; i < 10; ++i) {
        printf("%d%s", numbers[i], i == 9 ? "\n" : " ");
    }
    /* 一次释放整块空间，不需要逐个释放数组元素。 */
    free(numbers);
    return 0;
}
