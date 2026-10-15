#include <stdio.h>

int main(void)
{
    FILE *file = fopen("sample.txt", "r");
    char line[100];
    int failed = 0;

    if (file == NULL) {
        perror("无法打开sample.txt");
        return 1;
    }
    /* 一行超过缓冲区时会分多次读取，后续读取从上次停下的位置继续。 */
    while (fgets(line, sizeof line, file) != NULL) {
        /* fgets 可能保留换行，fputs 不会再补一个换行。 */
        if (fputs(line, stdout) == EOF) {
            failed = 1;
            break;
        }
    }
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
