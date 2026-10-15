#include <stdio.h>

int main(void)
{
    char text[1000];
    size_t count = 0;  // 用实际保存的字节数控制输出，不依赖字符串结束标记。
    int ch;

    printf("请输入字符，以 # 结束；空格和换行也会保存：\n");
    while ((ch = getchar()) != '#' && ch != EOF) {
        if (count == sizeof(text)) {
            printf("字符太多，最多保存 %zu 字节。\n", sizeof(text));
            return 1;
        }
        text[count] = (char)ch;
        count++;
    }
    printf("保存了 %zu 字节，内容如下：\n", count);
    for (size_t i = 0; i < count; i++) {
        putchar((unsigned char)text[i]);
    }
    putchar('\n');
    return 0;
}
