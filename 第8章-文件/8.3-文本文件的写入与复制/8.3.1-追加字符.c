#include <stdio.h>

int main(void)
{
    /* a 模式在文件末尾追加，文件不存在时创建，已有内容会保留。 */
    FILE *file = fopen("append_char.txt", "a");
    int failed = 0;

    if (file == NULL) {
        perror("无法打开append_char.txt");
        return 1;
    }
    if (fputc('a', file) == EOF || fputc('\n', file) == EOF) {
        failed = 1;
    }
    if (fclose(file) == EOF) {
        failed = 1;
    }
    if (failed) {
        perror("写入失败");
        return 1;
    }
    puts("已向append_char.txt追加字符a和换行。");
    return 0;
}
