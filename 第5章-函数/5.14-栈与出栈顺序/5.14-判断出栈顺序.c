#include <stdio.h>

/* 两个序列各有length个字符，length不能超过栈的容量6。 */
int valid_order(const char input[], const char output[], int length)
{
    char stack[6];
    int top = 0;  /* top是下一个入栈位置，栈顶元素的下标为top - 1。 */
    int next = 0;

    for (int i = 0; i < length; i++) {
        stack[top++] = input[i];
        /* 栈顶与下一个待输出字符相同时，立即模拟出栈。 */
        while (top > 0 && next < length && stack[top - 1] == output[next]) {
            top--;
            next++;
        }
    }
    return next == length;
}

int main(void)
{
    const char input[] = "ABCDEF";
    const char *orders[] = {"ABCDEF", "FEDCBA", "DCBEFA", "FEABCD"};

    puts("入栈顺序：ABCDEF，允许入栈和出栈交替进行。");
    for (int i = 0; i < 4; i++) {
        printf("%s：%s\n", orders[i], valid_order(input, orders[i], 6) ? "合法" : "不合法");
    }
    return 0;
}
