#include <stdio.h>
#include "5.13-计算函数.h"

/* 本节两个.c文件需要一起编译。 */
int main(void)
{
    printf("5 + 6 = %d\n", add(5, 6));
    printf("10 + 20 = %d\n", add(10, 20));
    printf("调用次数：%d\n", get_call_count());
    printf("外部变量保存的最近结果：%d\n", last_result);
    return 0;
}
