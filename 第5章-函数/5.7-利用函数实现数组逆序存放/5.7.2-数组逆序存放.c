#include <stdio.h>

void reverse(int values[], int length)
{
    /* 从两端向中间交换；下标相遇或交错后，逆序完成。 */
    for (int left = 0, right = length - 1; left < right; left++, right--) {
        int temp = values[left];
        values[left] = values[right];
        values[right] = temp;
    }
}

void print_array(const int values[], int length)
{
    for (int i = 0; i < length; i++) {
        printf("%d%s", values[i], i + 1 == length ? "\n" : " ");
    }
}

int main(void)
{
    int a[] = {1, 2, 3, 4, 5};
    printf("逆序前：");
    print_array(a, 5);
    reverse(a, 5);
    printf("逆序后：");
    print_array(a, 5);
    return 0;
}
