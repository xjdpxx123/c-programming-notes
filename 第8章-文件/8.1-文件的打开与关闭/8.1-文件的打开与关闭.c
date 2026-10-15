#include <stdio.h>

int main(void)
{
    /* 相对路径从程序的当前工作目录开始查找。 */
    FILE *file = fopen("sample.txt", "r");

    if (file == NULL) {
        perror("无法打开sample.txt");
        return 1;
    }
    puts("sample.txt已按只读方式打开。");
    if (fclose(file) == EOF) {
        perror("关闭文件失败");
        return 1;
    }
    puts("文件已关闭。");
    return 0;
}
