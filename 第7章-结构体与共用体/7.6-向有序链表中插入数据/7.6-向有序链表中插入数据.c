#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node *next;
} Node;

static void free_list(Node *head)
{
    while (head != NULL) {
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

static int create_list(Node **head)
{
    Node *tail = NULL;
    int value;

    *head = NULL;
    for (value = 1; value <= 91; value += 10) {
        Node *node = malloc(sizeof *node);
        if (node == NULL) {
            free_list(*head);
            *head = NULL;
            return 0;
        }
        node->value = value;
        node->next = NULL;
        if (*head == NULL) {
            *head = node;
        } else {
            tail->next = node;
        }
        tail = node;
    }
    return 1;
}

/* 传入表头指针的地址，才能在函数中改变调用处的表头。 */
static int insert_value(Node **head, int value)
{
    Node *previous = NULL;
    Node *current = *head;
    Node *node = malloc(sizeof *node);

    if (node == NULL) {
        return 0;
    }
    /* 找到第一个不小于新值的结点，在它前面插入。 */
    while (current != NULL && current->value < value) {
        previous = current;
        current = current->next;
    }
    node->value = value;
    /* 先让新结点接上后半段，再让前驱或表头指向它。 */
    node->next = current;
    if (previous == NULL) {
        *head = node;
    } else {
        previous->next = node;
    }
    return 1;
}

int main(void)
{
    Node *head;
    int value;

    if (!create_list(&head)) {
        puts("内存申请失败。");
        return 1;
    }
    print_list(head);
    printf("请输入要插入的整数：");
    if (scanf("%d", &value) != 1) {
        puts("请输入整数。");
        free_list(head);
        return 1;
    }
    if (!insert_value(&head, value)) {
        puts("内存申请失败。");
        free_list(head);
        return 1;
    }
    puts("插入后的链表：");
    print_list(head);
    free_list(head);
    return 0;
}
