#include <stdio.h>

void move_disks(int count, char from, char to, char spare)
{
    /* 只剩一个盘时直接移动，递归到此结束。 */
    if (count == 1) {
        printf("把1号盘从%c移到%c\n", from, to);
        return;
    }
    /* 先把上面的盘移到辅助柱，才能移动最下面的盘。 */
    move_disks(count - 1, from, spare, to);
    printf("把%d号盘从%c移到%c\n", count, from, to);
    /* 再把辅助柱上的盘移到目标柱，此时原柱充当辅助柱。 */
    move_disks(count - 1, spare, to, from);
}

int main(void)
{
    int count;
    printf("请输入盘子数量（1至15，1号盘最小）：");
    if (scanf("%d", &count) != 1 || count < 1 || count > 15) {
        puts("范围有误。");
        return 1;
    }
    move_disks(count, 'A', 'C', 'B');
    printf("共移动%u次。\n", (1u << count) - 1u);
    return 0;
}
