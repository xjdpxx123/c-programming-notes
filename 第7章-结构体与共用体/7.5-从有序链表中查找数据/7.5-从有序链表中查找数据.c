#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node *next;
} Node;

static void free_list(Node *head)
{
    while (head != NULL) {
        /* 先保存后继地址，再释放当前结点。 */
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
    const Node *p;
    int value;
    int target;

    puts("按从小到大的顺序输入整数，输入-99999结束：");
    for (;;) {
        Node *node;
        if (scanf("%d", &value) != 1) {
            puts("请输入整数。");
            free_list(head);
            return 1;
        }
        if (value == -99999) {
            break;
        }
        if (tail != NULL && value < tail->value) {
            puts("数据必须按从小到大的顺序输入。");
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
        if (head == NULL) {
            head = node;
        } else {
            tail->next = node;
        }
        tail = node;
    }
    print_list(head);
    printf("请输入要查找的数据：");
    if (scanf("%d", &target) != 1) {
        puts("请输入整数。");
        free_list(head);
        return 1;
    }
    p = head;
    /* 链表已按升序排列，遇到较大的值就不必继续向后找。 */
    while (p != NULL && p->value < target) {
        p = p->next;
    }
    puts(p != NULL && p->value == target ? "查找成功。" : "没有找到该数据。");
    free_list(head);
    return 0;
}
