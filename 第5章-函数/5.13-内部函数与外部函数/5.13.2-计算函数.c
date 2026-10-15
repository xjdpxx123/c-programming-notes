#include "5.13-计算函数.h"

int last_result = 0;
static int call_count = 0;

/* static函数和static文件作用域变量只在本文件内可见。 */
static void record_call(void)
{
    call_count++;
}

int add(int a, int b)
{
    record_call();
    last_result = a + b;
    return last_result;
}

int get_call_count(void)
{
    return call_count;
}
