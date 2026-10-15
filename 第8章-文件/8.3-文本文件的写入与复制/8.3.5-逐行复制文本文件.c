#include <stdio.h>

int main(void)
{
    FILE *source = fopen("sample.txt", "r");
    FILE *target;
    int failed = 0;

    if (source == NULL) {
        perror("无法打开sample.txt");
        return 1;
    }
    /* x 要求目标文件不存在，避免覆盖已有文件。 */
    target = fopen("copy_lines.txt", "wx");
    if (target == NULL) {
        perror("无法创建copy_lines.txt，请检查文件是否已存在");
        fclose(source);
        return 1;
    }
    {
        char line[100];
        /* 长行可以分段复制；fputs 不补换行，分段不会改变行的内容。 */
        while (fgets(line, sizeof line, source) != NULL) {
            if (fputs(line, target) == EOF) {
                failed = 1;
                break;
            }
        }
    }
    if (ferror(source)) {
        failed = 1;
    }
    if (fclose(source) == EOF) {
        failed = 1;
    }
    if (fclose(target) == EOF) {
        failed = 1;
    }
    if (failed) {
        fputs("复制失败，目标文件可能不完整。\n", stderr);
        return 1;
    }
    puts("已复制到copy_lines.txt。");
    return 0;
}
