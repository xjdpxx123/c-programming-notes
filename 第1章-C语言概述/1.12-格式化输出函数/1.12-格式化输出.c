#include <stdio.h>

int main(void)
{
    int a = 123;
    int b = 456;
    double value = 12.345;

    printf("a=%d,b=%d,sum=%d\n", a, b, a + b);
    // 竖线标出字段边界，便于观察填充空格和对齐位置。
    printf("右对齐：|%5d|\n", a);
    printf("左对齐：|%-5d|\n", a);
    printf("宽度不足时完整输出：|%2d|\n", b);
    // 7 是最小字段宽度（含小数点），.2 表示保留两位小数。
    printf("两位小数：|%7.2f|\n", value);
    printf("字符：%c，字符串：%s，百分号：%%\n", 'A', "hello");
    return 0;
}
