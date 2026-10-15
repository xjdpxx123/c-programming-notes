#include "../8.4-利用文件存储人员信息/人员记录.h"

int main(void)
{
    FILE *source;
    FILE *target;
    FILE *backup;
    Worker worker;
    char name[64];
    int removed = 0;
    int result;
    int failed = 0;

    puts("按姓名删除全部同名记录，原文件保留为personnel.bak。");
    printf("请输入要删除的姓名：");
    if (scanf("%63s", name) != 1) {
        puts("姓名输入有误。");
        return 1;
    }
    backup = fopen("personnel.bak", "rb");
    if (backup != NULL) {
        fclose(backup);
        puts("personnel.bak已存在，请先另存或移走旧备份。");
        return 1;
    }
    if (errno != ENOENT) {
        perror("无法检查备份文件");
        return 1;
    }
    source = fopen(PERSONNEL_FILE, "rb");
    if (source == NULL) {
        perror("无法打开personnel.dat，请先运行人员信息存储程序");
        return 1;
    }
    target = fopen("personnel.tmp", "wbx");
    if (target == NULL) {
        perror("无法创建personnel.tmp，请检查是否有同名文件");
        fclose(source);
        return 1;
    }
    /* 只把保留的记录写入临时文件，原文件在复制期间保持不变。 */
    while ((result = read_worker(source, &worker)) == 1) {
        if (strcmp(worker.name, name) == 0) {
            ++removed;
        } else if (fwrite(&worker, sizeof worker, 1, target) != 1) {
            failed = 1;
            break;
        }
    }
    if (result < 0) {
        failed = 1;
    }
    if (fclose(source) == EOF) {
        failed = 1;
    }
    if (fclose(target) == EOF) {
        failed = 1;
    }
    if (failed || removed == 0) {
        if (remove("personnel.tmp") != 0) {
            perror("临时文件未能删除");
        }
        puts(failed ? "操作失败，原文件未修改。" : "没有找到该人员，文件未修改。");
        return failed ? 1 : 0;
    }
    /* 完整写好新文件后再替换，原数据保留在备份中。 */
    if (rename(PERSONNEL_FILE, "personnel.bak") != 0) {
        perror("备份原文件失败，新内容保存在personnel.tmp");
        return 1;
    }
    if (rename("personnel.tmp", PERSONNEL_FILE) != 0) {
        perror("替换文件失败");
        /* 新文件未能就位时，尝试把备份改回原文件名。 */
        if (rename("personnel.bak", PERSONNEL_FILE) != 0) {
            perror("还原失败，原数据仍在personnel.bak中");
        }
        return 1;
    }
    printf("已删除%d条记录，原文件已备份为personnel.bak。\n", removed);
    return print_file() ? 0 : 1;
}
