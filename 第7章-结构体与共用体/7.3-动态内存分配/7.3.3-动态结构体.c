#include <stdio.h>
#include <stdlib.h>

typedef struct Pair {
    int first;
    int second;
} Pair;

int main(void)
{
    Pair *p = malloc(sizeof *p);

    if (p == NULL) {
        puts("内存申请失败。");
        return 1;
    }
    /* 这块空间容纳整个结构体，用 -> 分别访问它的成员。 */
    p->first = 99;
    p->second = 88;
    printf("两个成员的值：%d，%d\n", p->first, p->second);
    free(p);
    return 0;
}
