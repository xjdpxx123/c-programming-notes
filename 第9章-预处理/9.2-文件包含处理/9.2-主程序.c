#include <stdio.h>
#include "共享数据.h"

/* 本文件与 9.2-共享数据.c 一起编译、链接。 */
int main(void)
{
    printf("修改前：%d\n", shared_value);
    add_six();
    printf("修改后：%d\n", shared_value);
    return 0;
}
