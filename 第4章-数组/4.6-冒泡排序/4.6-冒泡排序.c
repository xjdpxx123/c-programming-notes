#include <stdio.h>

int main(void)
{
    int numbers[10] = {36, 45, 28, 74, 15, 26, 19, 98, 11, 9};

    // 每趟把未排序部分的最大值移到 end，下一趟少比较一个元素。
    for (int end = 9; end > 0; end--) {
        for (int k = 0; k < end; k++) {
            if (numbers[k] > numbers[k + 1]) {
                int temp = numbers[k];
                numbers[k] = numbers[k + 1];
                numbers[k + 1] = temp;
            }
        }
        printf("第 %d 趟：", 10 - end);
        for (int k = 0; k < 10; k++) {
            printf("%d ", numbers[k]);
        }
        printf("\n");
    }
    return 0;
}
