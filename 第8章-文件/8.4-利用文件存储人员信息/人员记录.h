#ifndef PERSONNEL_RECORD_H
#define PERSONNEL_RECORD_H

#include <stdio.h>
#include <string.h>
#include <errno.h>

#define PERSONNEL_FILE "personnel.dat"

/* 二进制记录依赖编译器、字节序和结构体布局，只在同一环境中交换。 */
typedef struct Worker {
    int number;
    char name[64];
    char sex[16];
    int age;
} Worker;

static inline void print_worker(const Worker *worker)
{
    printf("编号：%d，姓名：%s，性别：%s，年龄：%d\n",
           worker->number, worker->name, worker->sex, worker->age);
}

/* 返回1表示读到记录，0表示正常结束，-1表示文件损坏或读取失败。 */
static inline int read_worker(FILE *file, Worker *worker)
{
    /* 按字节统计读取量，文件末尾不足一条记录时也能检查出来。 */
    size_t size = fread(worker, 1, sizeof *worker, file);

    if (size == 0 && !ferror(file)) {
        return 0;
    }
    /* 字符数组中必须有 '\0'，之后才能安全地按字符串输出或比较。 */
    if (size != sizeof *worker || ferror(file) || worker->number <= 0 ||
        worker->age < 0 || worker->age > 150 ||
        memchr(worker->name, '\0', sizeof worker->name) == NULL ||
        memchr(worker->sex, '\0', sizeof worker->sex) == NULL ||
        worker->name[0] == '\0' || worker->sex[0] == '\0') {
        fputs("人员文件不完整或记录格式不正确。\n", stderr);
        return -1;
    }
    return 1;
}

static inline int input_details(Worker *worker)
{
    printf("请输入姓名、性别、年龄（姓名和性别不含空格）：");
    if (scanf("%63s%15s%d", worker->name, worker->sex, &worker->age) != 3 ||
        worker->age < 0 || worker->age > 150) {
        puts("输入有误，年龄应在0～150之间。");
        return 0;
    }
    return 1;
}

static inline int print_file(void)
{
    FILE *file = fopen(PERSONNEL_FILE, "rb");
    Worker worker;
    int result;
    int count = 0;

    if (file == NULL) {
        perror("无法读取personnel.dat");
        return 0;
    }
    while ((result = read_worker(file, &worker)) == 1) {
        print_worker(&worker);
        ++count;
    }
    if (fclose(file) == EOF) {
        perror("关闭人员文件失败");
        return 0;
    }
    if (result < 0) {
        return 0;
    }
    printf("共%d条记录。\n", count);
    return 1;
}

static inline int append_worker(const Worker *worker)
{
    /* r+b 保留已有记录并允许读写；仅在文件不存在时尝试新建。 */
    FILE *file = fopen(PERSONNEL_FILE, "r+b");
    Worker old;
    int result;
    int failed = 0;

    if (file == NULL && errno == ENOENT) {
        file = fopen(PERSONNEL_FILE, "w+bx");
    }
    if (file == NULL) {
        perror("无法打开personnel.dat");
        return 0;
    }
    while ((result = read_worker(file, &old)) == 1) {
        if (old.number == worker->number) {
            puts("编号已存在，未添加记录。");
            fclose(file);
            return 0;
        }
    }
    if (result < 0) {
        fclose(file);
        return 0;
    }
    /* 从读取切换到写入前，先调用定位函数。 */
    if (fseek(file, 0L, SEEK_END) != 0 ||
        fwrite(worker, sizeof *worker, 1, file) != 1) {
        failed = 1;
    }
    if (fclose(file) == EOF) {
        failed = 1;
    }
    if (failed) {
        perror("保存记录失败");
        return 0;
    }
    return 1;
}

#endif
