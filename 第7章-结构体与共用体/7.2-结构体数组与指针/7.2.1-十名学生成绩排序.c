#include <stdio.h>
#include <math.h>

typedef struct Student {
    char name[50];
    double grade;
} Student;

int main(void)
{
    Student students[10];
    int i;
    int j;

    for (i = 0; i < 10; ++i) {
        printf("请输入第%d名学生的姓名和成绩：", i + 1);
        if (scanf("%49s%lf", students[i].name, &students[i].grade) != 2 ||
            !isfinite(students[i].grade) || students[i].grade < 0 ||
            students[i].grade > 100) {
            puts("输入有误，成绩应在0～100之间。");
            return 1;
        }
    }
    /* 相邻比较，成绩相同的学生保持原来的次序。 */
    for (i = 0; i < 9; ++i) {
        for (j = 0; j < 9 - i; ++j) {
            if (students[j].grade < students[j + 1].grade) {
                /* 交换整个结构体，姓名与成绩一起移动。 */
                Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
    puts("按成绩从高到低排列：");
    for (i = 0; i < 10; ++i) {
        printf("%2d  %s  %.2f\n", i + 1, students[i].name, students[i].grade);
    }
    return 0;
}
