#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node *next;
} Node;

static void free_list(Node *head)
{
    while (head != NULL) {
        /* 释放前保存后继地址，释放后不能再读取 head->next。 */
        Node *next = head->next;
        free(head);
        head = next;
    }
}

static void print_list(const Node *head)
{
    if (head == NULL) {
        puts("空链表");
        return;
    }
    while (head != NULL) {
        printf("%d%s", head->value, head->next == NULL ? "\n" : " -> ");
        head = head->next;
    }
}

int main(void)
{
    Node *head = NULL;
    Node *tail = NULL;
    int i;

    for (i = 0; i < 10; ++i) {
        int value;
        Node *node;
        printf("请输入第%d个整数：", i + 1);
        if (scanf("%d", &value) != 1) {
            puts("请输入整数。");
            free_list(head);
            return 1;
        }
        node = malloc(sizeof *node);
        if (node == NULL) {
            puts("内存申请失败。");
            free_list(head);
            return 1;
        }
        node->value = value;
        node->next = NULL;
        /* 首个结点成为表头；以后先接到原表尾，再移动 tail。 */
        if (head == NULL) {
            head = node;
        } else {
            tail->next = node;
        }
        tail = node;
    }
    print_list(head);
    free_list(head);
    return 0;
}
