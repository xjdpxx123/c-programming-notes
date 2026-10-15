#include <stdio.h>

int main(void)
{
    int in_circle[1000] = {0};  // 1 表示仍在圈内，0 表示不参与报数。
    int people;
    int remaining;
    int number = 0;

    printf("请输入人数（1 到 1000）：");
    if (scanf("%d", &people) != 1 || people < 1 || people > 1000) {
        printf("人数必须是 1 到 1000 之间的整数。\n");
        return 1;
    }
    for (int i = 0; i < people; i++) {
        in_circle[i] = 1;
    }
    remaining = people;
    printf("出圈顺序：");
    // 扫完一遍数组后继续报数，number 不在每圈开始时清零。
    while (remaining > 1) {
        for (int i = 0; i < people && remaining > 1; i++) {
            if (in_circle[i]) {
                number++;
                if (number == 3) {
                    printf("%d ", i + 1);
                    in_circle[i] = 0;
                    remaining--;
                    number = 0;
                }
            }
        }
    }
    printf("\n");
    for (int i = 0; i < people; i++) {
        if (in_circle[i]) {
            printf("最后留下的是 %d 号。\n", i + 1);
        }
    }
    return 0;
}
