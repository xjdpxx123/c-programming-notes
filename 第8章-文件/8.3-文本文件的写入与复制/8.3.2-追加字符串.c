#include <stdio.h>

int main(void)
{
    FILE *file = fopen("append_lines.txt", "a");
    int failed = 0;

    if (file == NULL) {
        perror("无法打开append_lines.txt");
        return 1;
    }
    /* fputs 不自动换行，也不把字符串末尾的 '\0' 写入文件。 */
    if (fputs("欢迎学习C语言。\n", file) == EOF) {
        failed = 1;
    }
    if (fclose(file) == EOF) {
        failed = 1;
    }
    if (failed) {
        perror("写入失败");
        return 1;
    }
    puts("已向append_lines.txt追加一行文字。");
    return 0;
}
