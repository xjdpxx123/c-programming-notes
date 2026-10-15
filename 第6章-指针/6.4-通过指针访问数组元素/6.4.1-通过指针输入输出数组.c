#include <stdio.h>

#define LENGTH 10

int main(void)
{
    int values[LENGTH];
    int *p = values;

    printf("请输入10个整数：");
    /* p + i等价于&values[i]，scanf通过这个地址写入values[i]。 */
    for (int i = 0; i < LENGTH; i++) {
        if (scanf("%d", p + i) != 1) {
            puts("输入有误。");
            return 1;
        }
    }
    printf("数组元素：");
    for (int i = 0; i < LENGTH; i++) {
        printf("%d%s", *(p + i), i + 1 == LENGTH ? "\n" : " ");
    }
    printf("第三个元素的四种写法：%d %d %d %d\n",
           values[2], *(values + 2), *(p + 2), p[2]);
    return 0;
}
