#include <stdio.h>
#include <string.h>

int main(void)
{
    char words[5][100] = {"woYaoZiXueWang", "ziXueWangZhan", "cYuYanCheng", "shuZu", "ziFuChuan"};
    char temp[100];

    printf("排序前：\n");
    for (int i = 0; i < 5; i++) {
        puts(words[i]);
    }
    for (int i = 0; i < 4; i++) {
        // minimum 保存剩余字符串中按 strcmp 比较最小的那一行下标。
        int minimum = i;
        for (int k = i + 1; k < 5; k++) {
            if (strcmp(words[k], words[minimum]) < 0) {
                minimum = k;
            }
        }
        // 一行是一个字符数组，不能直接赋值，用 strcpy 交换内容。
        if (minimum != i) {
            strcpy(temp, words[i]);
            strcpy(words[i], words[minimum]);
            strcpy(words[minimum], temp);
        }
    }
    printf("按字节顺序排序后：\n");
    for (int i = 0; i < 5; i++) {
        puts(words[i]);
    }
    return 0;
}
