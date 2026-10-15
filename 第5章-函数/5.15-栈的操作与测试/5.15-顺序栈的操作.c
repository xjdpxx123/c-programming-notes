#include <stdio.h>

#define CAPACITY 15

int stack[CAPACITY];
int top = 0;  /* top指向下一个空位置，也等于当前元素个数。 */
const int bottom = 0;

void clear_stack(void)
{
    /* 重置栈顶后，旧数据不再属于栈；后续入栈会覆盖它们。 */
    top = bottom;
}

int stack_empty(void)
{
    return top == bottom;
}

int stack_length(void)
{
    return top - bottom;
}

int get_top(int *value)
{
    if (stack_empty()) {
        return 0;
    }
    *value = stack[top - 1];
    return 1;
}

int push(int value)
{
    if (top == CAPACITY) {
        return -1;
    }
    stack[top++] = value;
    return 1;
}

/* 返回值表示成功与否，取出的数据通过value带回。 */
int pop(int *value)
{
    if (stack_empty()) {
        return 0;
    }
    *value = stack[--top];
    return 1;
}

int main(void)
{
    int choice, value;
    puts("1 入栈  2 出栈  3 查看栈顶  4 长度  5 判空  6 清空  0 结束");
    for (;;) {
        printf("请选择：");
        if (scanf("%d", &choice) != 1) {
            puts("输入有误。");
            return 1;
        }
        switch (choice) {
            case 0:
                return 0;
            case 1:
                printf("请输入入栈的整数：");
                if (scanf("%d", &value) != 1) {
                    puts("输入有误。");
                    return 1;
                }
                puts(push(value) == 1 ? "入栈成功。" : "栈已满。");
                break;
            case 2:
                if (pop(&value)) {
                    printf("出栈元素：%d\n", value);
                } else {
                    puts("栈为空。");
                }
                break;
            case 3:
                if (get_top(&value)) {
                    printf("栈顶元素：%d\n", value);
                } else {
                    puts("栈为空。");
                }
                break;
            case 4:
                printf("栈的长度：%d\n", stack_length());
                break;
            case 5:
                puts(stack_empty() ? "栈为空。" : "栈不为空。");
                break;
            case 6:
                clear_stack();
                puts("栈已清空。");
                break;
            default:
                puts("请选择0至6。");
                break;
        }
    }
}
