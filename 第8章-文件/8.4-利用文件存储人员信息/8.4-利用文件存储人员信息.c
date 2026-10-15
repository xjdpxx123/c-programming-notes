#include "人员记录.h"

int main(void)
{
    Worker worker = {0};

    puts("新增一条记录，保存到当前目录的personnel.dat。");
    printf("请输入人员编号（正整数）：");
    if (scanf("%d", &worker.number) != 1 || worker.number <= 0) {
        puts("编号应为正整数。");
        return 1;
    }
    if (!input_details(&worker) || !append_worker(&worker)) {
        return 1;
    }
    puts("记录已保存，文件内容如下：");
    return print_file() ? 0 : 1;
}
