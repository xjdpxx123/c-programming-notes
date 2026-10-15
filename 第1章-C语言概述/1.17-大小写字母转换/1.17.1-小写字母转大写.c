#include <stdio.h>

int main(void)
{
    char letter;

    // 本例使用 ASCII 中英文字母连续排列的规则。
    printf("请输入 a 到 z 之间的字母：");
    if (scanf(" %c", &letter) != 1 || letter < 'a' || letter > 'z') {
        printf("请输入指定范围内的字母。\n");
        return 1;
    }
    letter = (char)(letter - ('a' - 'A'));
    printf("转换结果：%c\n", letter);
    return 0;
}
