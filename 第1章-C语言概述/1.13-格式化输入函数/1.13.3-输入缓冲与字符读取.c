#include <stdio.h>

int main(void)
{
    int a, b, c;
    char letter;

    printf("请输入三个整数，可放在同一行：");
    // 第一次只取走两个整数，第二次从尚未读取的输入继续取数。
    if (scanf("%d%d", &a, &b) != 2 || scanf("%d", &c) != 1) {
        printf("输入格式不正确。\n");
        return 1;
    }
    printf("第一次读取：%d %d，第二次读取：%d\n", a, b, c);
    printf("请输入一个非空白字符：");
    // %c 前的空格会跳过换行、空格和制表符。
    if (scanf(" %c", &letter) != 1) {
        printf("未读到字符。\n");
        return 1;
    }
    printf("字符：%c\n", letter);
    return 0;
}
