#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    /* sizeof *p 随指针所指类型变化，避免写死字节数。 */
    int *p = malloc(sizeof *p);

    if (p == NULL) {
        puts("内存申请失败。");
        return 1;
    }
    *p = 99;
    printf("申请的空间中存放：%d\n", *p);
    /* free 后不能再通过 p 访问这块空间；置空可避免保留旧地址。 */
    free(p);
    p = NULL;
    return 0;
}
