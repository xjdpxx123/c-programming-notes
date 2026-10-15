#include <stdio.h>

int main(void)
{
    FILE *file = fopen("words.txt", "r");
    char word[100];
    int failed = 0;

    if (file == NULL) {
        perror("无法打开words.txt");
        return 1;
    }
    /* %s 跳过开头的空白；最多读99个字节，给结尾的 '\0' 留一个位置。 */
    while (fscanf(file, "%99s", word) == 1) {
        if (puts(word) == EOF) {
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
