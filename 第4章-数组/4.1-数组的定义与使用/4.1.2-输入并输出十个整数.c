#include <stdio.h>

int main(void)
{
    int numbers[10];

    // 十个元素的下标是 0 到 9，提示中的序号从 1 开始。
    for (int i = 0; i < 10; i++) {
        printf("请输入第 %d 个整数：", i + 1);
        if (scanf("%d", &numbers[i]) != 1) {
            printf("输入有误，请输入整数。\n");
            return 1;
        }
    }
    printf("输入的十个整数：\n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");
    return 0;
}
