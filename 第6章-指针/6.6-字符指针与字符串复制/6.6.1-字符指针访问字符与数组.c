#include <stdio.h>

int main(void)
{
    char ch;
    char *pc = &ch;
    char text[5];

    printf("请输入一个英文字符：");
    int input = getchar();
    if (input == EOF) {
        puts("未读到字符。");
        return 1;
    }
    *pc = (char)input;
    printf("通过指针读到的字符：%c\n", ch);

    pc = text;
    *pc = 'a';
    pc[1] = 'b';
    *(pc + 2) = 'c';
    pc[3] = 'd';
    /* 4个可见字符还需要1个字节存放结束标志，%s据此停止输出。 */
    *(pc + 4) = '\0';
    printf("通过指针写入的字符串：%s\n", text);
    return 0;
}
