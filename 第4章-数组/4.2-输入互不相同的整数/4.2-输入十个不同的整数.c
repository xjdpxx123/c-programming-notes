#include <stdio.h>

int main(void)
{
    int numbers[10];
    int count = 0;

    while (count < 10) {
        int k;
        printf("请输入第 %d 个整数：", count + 1);
        if (scanf("%d", &numbers[count]) != 1) {
            printf("输入有误，请输入整数。\n");
            return 1;
        }
        // 前 count 个元素已确认互不相同，只在这部分中查重。
        for (k = 0; k < count; k++) {
            if (numbers[k] == numbers[count]) {
                break;
            }
        }
        // 重复时不增加 count，下次输入仍写入同一个位置。
        if (k < count) {
            printf("这个数已经输入过，请换一个。\n");
        } else {
            count++;
        }
    }
    printf("十个不同的整数：\n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");
    return 0;
}
