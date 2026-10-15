#include <stdio.h>
#include <stdlib.h>

typedef struct Worker {
    int number;
    char name[50];
    char sex[16];
    int age;
    struct Worker *next;
} Worker;

static void free_list(Worker *head)
{
    while (head != NULL) {
        Worker *next = head->next;
        free(head);
        head = next;
    }
}

static void print_worker(const Worker *worker)
{
    printf("编号：%d，姓名：%s，性别：%s，年龄：%d\n",
           worker->number, worker->name, worker->sex, worker->age);
}

/* 排序只调整结点间的链接，原有结点仍在返回的链表中。 */
static Worker *sort_by_age(Worker *head)
{
    Worker *sorted = NULL;
    Worker *tail = NULL;

    while (head != NULL) {
        Worker *minimum = head;
        Worker *minimum_previous = NULL;
        Worker *previous = head;
        Worker *p;

        for (p = head->next; p != NULL; p = p->next) {
            if (p->age < minimum->age) {
                minimum = p;
                minimum_previous = previous;
            }
            previous = p;
        }
        /* 从原链表取下最年轻者，接到新链表尾部。 */
        if (minimum_previous == NULL) {
            head = minimum->next;
        } else {
            minimum_previous->next = minimum->next;
        }
        minimum->next = NULL;
        if (sorted == NULL) {
            sorted = minimum;
        } else {
            tail->next = minimum;
        }
        tail = minimum;
    }
    return sorted;
}

int main(void)
{
    Worker *head = NULL;
    Worker *tail = NULL;
    Worker *p;
    int count;
    int i;
    int age;
    int found = 0;

    printf("请输入人数（1～100，三人示例输入3）：");
    if (scanf("%d", &count) != 1 || count < 1 || count > 100) {
        puts("人数应在1～100之间。");
        return 1;
    }
    for (i = 0; i < count; ++i) {
        Worker *node = calloc(1, sizeof *node);
        if (node == NULL) {
            puts("内存申请失败。");
            free_list(head);
            return 1;
        }
        printf("第%d人，请输入编号、姓名、性别、年龄：", i + 1);
        if (scanf("%d%49s%15s%d", &node->number, node->name,
                  node->sex, &node->age) != 4 || node->number <= 0 ||
            node->age < 0 || node->age > 150) {
            puts("输入有误，编号应为正整数，年龄应在0～150之间。");
            free(node);
            free_list(head);
            return 1;
        }
        node->next = NULL;
        if (head == NULL) {
            head = node;
        } else {
            tail->next = node;
        }
        tail = node;
    }
    head = sort_by_age(head);
    puts("按年龄从小到大排列：");
    for (p = head; p != NULL; p = p->next) {
        print_worker(p);
    }
    puts(count % 2 == 0 ? "中间两人的信息：" : "年龄居中者的信息：");
    p = head;
    /* 奇数人数停在正中间；偶数人数停在中间两个位置中靠前的一个。 */
    for (i = 0; i < (count - 1) / 2; ++i) {
        p = p->next;
    }
    print_worker(p);
    if (count % 2 == 0) {
        print_worker(p->next);
    }
    printf("请输入要查找的年龄（0～150）：");
    if (scanf("%d", &age) != 1 || age < 0 || age > 150) {
        puts("年龄输入有误。");
        free_list(head);
        return 1;
    }
    for (p = head; p != NULL && p->age <= age; p = p->next) {
        if (p->age == age) {
            print_worker(p);
            found = 1;
        }
    }
    if (!found) {
        puts("没有找到该年龄的人员。");
    }
    free_list(head);
    return 0;
}
