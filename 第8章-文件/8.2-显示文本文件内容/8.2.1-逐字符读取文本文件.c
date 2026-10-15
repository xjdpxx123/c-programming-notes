#include <stdio.h>

int main(void)
{
    FILE *file = fopen("sample.txt", "r");
    int ch;
    int failed = 0;

    if (file == NULL) {
        perror("无法打开sample.txt");
        return 1;
    }
    /* fgetc 返回 int，才能区分所有字节值与 EOF。 */
    while ((ch = fgetc(file)) != EOF) {
        if (putchar(ch) == EOF) {
            failed = 1;
            break;
        }
    }
    /* EOF 也可能表示读取出错，用 ferror 区分是否正常读到末尾。 */
    if (ferror(file)) {
        failed = 1;
    }
    if (fclose(file) == EOF) {
        failed = 1;
    }
    if (failed) {
        fputs("文件读取或输出失败。\n", stderr);
    }
    return failed;
}
