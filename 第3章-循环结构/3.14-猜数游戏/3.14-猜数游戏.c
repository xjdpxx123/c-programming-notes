#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    int answer;
    int guess;
    unsigned long long attempts = 0;

    // 随机数种子只在游戏开始时设置一次。
    srand((unsigned int)time(NULL));
    answer = rand() % 100 + 1;
    printf("我想好了一个 1 到 100 之间的整数，输入 999 退出。\n");
    while (1) {
        printf("请输入你的猜测：");
        int status = scanf("%d", &guess);
        if (status == EOF) {
            printf("\n输入结束，游戏退出。\n");
            break;
        }
        if (status != 1) {
            int ch;
            while ((ch = getchar()) != '\n' && ch != EOF) {
                // 丢弃这一行无法识别的输入。
            }
            printf("请输入整数。\n");
            continue;
        }
        if (guess == 999) {
            printf("游戏结束，答案是 %d。\n", answer);
            break;
        }
        if (guess < 1 || guess > 100) {
            printf("猜测范围是 1 到 100。\n");
            continue;
        }
        // 只有 1 到 100 之间的整数才计入猜测次数。
        attempts++;
        if (guess > answer) {
            printf("大了。\n");
        } else if (guess < answer) {
            printf("小了。\n");
        } else {
            printf("猜对了！共猜了 %llu 次。\n", attempts);
            break;
        }
    }
    return 0;
}
