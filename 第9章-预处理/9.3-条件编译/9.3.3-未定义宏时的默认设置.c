#include <stdio.h>

/* 编译时可以定义 CLASS_SIZE，未定义时使用30。 */
#ifndef CLASS_SIZE
#define CLASS_SIZE 30
#endif

int main(void)
{
    printf("班级人数：%d\n", CLASS_SIZE);
    return 0;
}
