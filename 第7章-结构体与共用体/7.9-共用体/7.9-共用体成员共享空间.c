#include <stdio.h>

typedef union Data {
    int numbers[3];
    float real;
    char letter;
} Data;

int main(void)
{
    Data data;
    int i;

    printf("共用体大小：%zu字节\n", sizeof data);
    printf("三个成员的大小：%zu、%zu、%zu字节\n",
           sizeof data.numbers, sizeof data.real, sizeof data.letter);
    printf("三个成员的起始地址：%p、%p、%p\n",
           (void *)data.numbers, (void *)&data.real, (void *)&data.letter);
    for (i = 0; i < 3; ++i) {
        data.numbers[i] = i * i + 100;
    }
    printf("保存整数数组：%d %d %d\n",
           data.numbers[0], data.numbers[1], data.numbers[2]);
    /* 写入另一个成员后，只读取刚刚写入的成员。 */
    data.real = 128.6f;
    printf("改存实数：%.1f\n", data.real);
    data.letter = 'C';
    printf("改存字符：%c\n", data.letter);
    return 0;
}
