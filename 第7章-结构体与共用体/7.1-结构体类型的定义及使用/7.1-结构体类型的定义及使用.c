#include <stdio.h>
#include <string.h>

struct Date {
    int year;
    int month;
    int day;
};

struct Student {
    char number[30];
    char name[30];
    char sex[8];
    float grade;
    struct Date birth;
};

int main(void)
{
    struct Student student = {"2026001", "张三", "男", 98.5f, {2008, 6, 12}};
    struct Point {
        int x;
        int y;
    } point = {3, 4};
    struct {
        int hour;
        int minute;
    } time = {8, 30};

    /* 数组成员不能整体赋值，改名时将字符串复制到 name 中。 */
    strcpy(student.name, "李明");
    printf("学号：%s，姓名：%s，性别：%s，成绩：%.2f\n",
           student.number, student.name, student.sex, student.grade);
    printf("出生日期：%d年%d月%d日\n",
           student.birth.year, student.birth.month, student.birth.day);
    printf("坐标：(%d, %d)\n", point.x, point.y);
    printf("上课时间：%02d:%02d\n", time.hour, time.minute);
    /* 成员之间可能有填充字节，结构体大小不一定等于成员大小之和。 */
    printf("学生结构体占 %zu 字节。\n", sizeof student);
    return 0;
}
