#include "共享数据.h"

/* 共享变量只在这里定义一次，其他源文件通过 extern 声明使用。 */
int shared_value = 36;

void add_six(void)
{
    shared_value += 6;
}
