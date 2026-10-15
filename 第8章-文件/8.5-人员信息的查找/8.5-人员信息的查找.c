#include "../8.4-利用文件存储人员信息/人员记录.h"

static int add_records(void)
{
    for (;;) {
        Worker worker = {0};

        printf("请输入新增人员编号（正整数，负数结束录入）：");
        if (scanf("%d", &worker.number) != 1 || worker.number == 0) {
            puts("编号输入有误。");
            return 0;
        }
        if (worker.number < 0) {
            return 1;
        }
        if (!input_details(&worker) || !append_worker(&worker)) {
            return 0;
        }
    }
}

static int find_workers(void)
{
    FILE *file;
    Worker worker;
    int mode;
    int number = 0;
    char name[64] = "";
    int found = 0;
    int result;

    printf("查找方式：1-编号，2-姓名，3-编号和姓名：");
    if (scanf("%d", &mode) != 1 || mode < 1 || mode > 3) {
        puts("查找方式输入有误。");
        return 0;
    }
    if (mode == 1 || mode == 3) {
        printf("请输入编号：");
        if (scanf("%d", &number) != 1 || number <= 0) {
            puts("编号应为正整数。");
            return 0;
        }
    }
    if (mode == 2 || mode == 3) {
        printf("请输入姓名：");
        if (scanf("%63s", name) != 1) {
            puts("姓名输入有误。");
            return 0;
        }
    }
    file = fopen(PERSONNEL_FILE, "rb");
    if (file == NULL) {
        perror("无法读取personnel.dat，请先添加记录");
        return 0;
    }
    while ((result = read_worker(file, &worker)) == 1) {
        /* 未选择的条件视为满足，组合查找时两个条件都必须满足。 */
        int number_matches = mode == 2 || worker.number == number;
        int name_matches = mode == 1 || strcmp(worker.name, name) == 0;

        if (number_matches && name_matches) {
            /* 同名人员可能不止一位，找到后仍继续检查后面的记录。 */
            print_worker(&worker);
            ++found;
        }
    }
    if (fclose(file) == EOF || result < 0) {
        return 0;
    }
    if (found == 0) {
        puts("没有找到符合条件的人员。");
    } else {
        printf("找到%d条记录。\n", found);
    }
    return 1;
}

int main(void)
{
    puts("使用当前目录中的personnel.dat；新增记录会保留原有内容。");
    if (!add_records()) {
        return 1;
    }
    return find_workers() ? 0 : 1;
}
