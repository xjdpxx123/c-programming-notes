#include "../8.4-利用文件存储人员信息/人员记录.h"

int main(void)
{
    FILE *file;
    Worker worker;
    Worker original = {0};
    char name[64];
    long position = 0;
    int found = 0;
    int result;
    int failed = 0;

    puts("修改当前目录personnel.dat中第一个同名人员，编号保持不变。");
    printf("请输入要修改的姓名：");
    if (scanf("%63s", name) != 1) {
        puts("姓名输入有误。");
        return 1;
    }
    file = fopen(PERSONNEL_FILE, "r+b");
    if (file == NULL) {
        perror("无法打开personnel.dat，请先运行人员信息存储程序");
        return 1;
    }
    while ((result = read_worker(file, &worker)) == 1) {
        if (!found && strcmp(worker.name, name) == 0) {
            long end = ftell(file);
            if (end < 0) {
                perror("无法取得文件位置");
                fclose(file);
                return 1;
            }
            /* 读取后的位置在记录末尾，减去记录长度得到它的起点。 */
            position = end - (long)sizeof worker;
            original = worker;
            found = 1;
        }
    }
    /* 先检查完整文件，避免修改后才发现后面的记录损坏。 */
    if (result < 0) {
        fclose(file);
        return 1;
    }
    if (!found) {
        puts("没有找到该人员，文件未修改。");
        return fclose(file) == 0 ? 0 : 1;
    }
    worker = original;
    puts("原记录：");
    print_worker(&worker);
    if (!input_details(&worker)) {
        fclose(file);
        return 1;
    }
    /* 回到原记录起点再覆盖，既完成读写切换，也保留后面的记录。 */
    if (fseek(file, position, SEEK_SET) != 0 ||
        fwrite(&worker, sizeof worker, 1, file) != 1 || fflush(file) == EOF) {
        perror("更新失败");
        fclose(file);
        return 1;
    }
    /* 写入后回到文件头，再读取更新后的完整列表。 */
    rewind(file);
    puts("更新后的文件内容：");
    while ((result = read_worker(file, &worker)) == 1) {
        print_worker(&worker);
    }
    if (result < 0) {
        failed = 1;
    }
    if (fclose(file) == EOF) {
        failed = 1;
    }
    return failed;
}
