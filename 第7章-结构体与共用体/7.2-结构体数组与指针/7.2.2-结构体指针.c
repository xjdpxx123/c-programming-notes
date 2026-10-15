#include <stdio.h>
#include <string.h>

typedef struct Student {
    char name[50];
    float grade;
} Student;

int main(void)
{
    Student student = {"", 0.0f};
    Student *p = &student;

    /* p->成员 等价于 (*p).成员，访问的是 p 所指的结构体。 */
    strcpy(p->name, "李四");
    p->grade = 99.0f;
    printf("姓名：%s，成绩：%.2f\n", p->name, p->grade);
    printf("(*p).grade = %.2f\n", (*p).grade);
    return 0;
}
