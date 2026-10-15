#include <stdio.h>

typedef struct Node {
    int value;
    struct Node *next;
} Node;

int main(void)
{
    /* 最后一个结点的 next 为 NULL，遍历到这里结束。 */
    Node second = {98, NULL};
    Node first = {99, &second};
    Node *head = &first;
    Node *p;

    for (p = head; p != NULL; p = p->next) {
        printf("%d%s", p->value, p->next == NULL ? "\n" : " -> ");
    }
    /* 这两个结点是局部变量，不需要调用 free。 */
    return 0;
}
