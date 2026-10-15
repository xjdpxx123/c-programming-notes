#include <stdio.h>
#include <ctype.h>

int main(void)
{
    FILE *file = fopen("numbers.txt", "r");
    int number;
    int result;
    int failed = 0;
    int needs_number = 0;

    if (file == NULL) {
        perror("无法打开numbers.txt");
        return 1;
    }
    while ((result = fscanf(file, "%d", &number)) == 1) {
        int separator;
        needs_number = 0;
        printf("%d ", number);
        /* 数字后允许空白，跳过空白后应当是逗号或文件末尾。 */
        do {
            separator = fgetc(file);
        } while (separator != EOF && isspace((unsigned char)separator));
        if (separator == EOF) {
            break;
        }
        if (separator != ',') {
            failed = 1;
            break;
        }
        /* 读到逗号后必须再读到整数，不能以逗号结束。 */
        needs_number = 1;
    }
    putchar('\n');
    if (result == 0 || needs_number || ferror(file)) {
        failed = 1;
    }
    if (fclose(file) == EOF) {
        failed = 1;
    }
    if (failed) {
        fputs("读取失败，请用逗号分隔整数。\n", stderr);
    }
    return failed;
}
