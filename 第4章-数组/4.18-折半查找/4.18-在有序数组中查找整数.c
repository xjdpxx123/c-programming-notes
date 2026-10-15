#include <stdio.h>

int main(void)
{
    int numbers[10] = {9, 11, 15, 19, 26, 28, 36, 45, 74, 98};
    int target;
    int left = 0;
    int right = 9;
    int position = -1;

    printf("有序数组：");
    for (int i = 0; i < 10; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n请输入要查找的整数：");
    if (scanf("%d", &target) != 1) {
        printf("输入有误，请输入整数。\n");
        return 1;
    }
    // 待查区间包含左右端点；left > right 表示区间已空。
    while (left <= right) {
        int middle = left + (right - left) / 2;
        if (numbers[middle] == target) {
            position = middle;
            break;
        }
        // 数组递增有序，每次排除中间元素及不可能包含目标的那一半。
        if (numbers[middle] < target) {
            left = middle + 1;
        } else {
            right = middle - 1;
        }
    }
    if (position >= 0) {
        printf("找到了 %d：下标为 %d，是第 %d 个元素。\n", target, position, position + 1);
    } else {
        printf("数组中没有 %d。\n", target);
    }
    return 0;
}
