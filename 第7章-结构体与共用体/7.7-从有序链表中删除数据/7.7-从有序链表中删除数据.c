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

/* 删除首结点时需要修改表头，因此接收表头指针的地址。 */
static int delete_value(Node **head, int value)
{
    Node *previous = NULL;
    Node *current = *head;

    while (current != NULL && current->value < value) {
        previous = current;
        current = current->next;
    }
    if (current == NULL || current->value != value) {
        return 0;
    }
    /* 前驱不存在时，待删除的是首结点，也可能是唯一的结点。 */
    if (previous == NULL) {
        *head = current->next;
    } else {
        previous->next = current->next;
    }
    /* 链接已绕过 current，此时再释放它，剩余链表仍然完整。 */
    free(current);
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
    printf("请输入要删除的整数：");
    if (scanf("%d", &value) != 1) {
        puts("请输入整数。");
        free_list(head);
        return 1;
    }
    puts(delete_value(&head, value) ? "已删除一个结点。" : "没有找到该数据。");
    print_list(head);
    free_list(head);
    return 0;
}
