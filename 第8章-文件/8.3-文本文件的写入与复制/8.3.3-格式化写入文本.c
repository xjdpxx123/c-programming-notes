#include <stdio.h>

int main(void)
{
    FILE *file = fopen("formatted.txt", "a");
    int failed = 0;

    if (file == NULL) {
        perror("无法打开formatted.txt");
        return 1;
    }
    /* fprintf 将整数转换为数字字符，逗号和换行也按格式写入。 */
    if (fprintf(file, "%d,%d,%s\n", 36, 45, "学习C语言") < 0) {
        failed = 1;
    }
    /* 缓冲区中的内容可能到关闭时才写出，因此也要检查 fclose。 */
    if (fclose(file) == EOF) {
        failed = 1;
    }
    if (failed) {
        perror("写入失败");
        return 1;
    }
    puts("已向formatted.txt追加：36,45,学习C语言");
    return 0;
}
