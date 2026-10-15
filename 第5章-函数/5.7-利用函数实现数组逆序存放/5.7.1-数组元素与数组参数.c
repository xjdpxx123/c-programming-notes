#include <stdio.h>

void change_element(int value)
{
    /* 数组元素作为实参时，传入的是该元素的值。 */
    value = 9;
    printf("函数内的value = %d\n", value);
}

void change_array(int values[])
{
    /* 数组形参实际接收首元素地址，values[2]就是原数组的第三个元素。 */
    values[2] = 9;
    printf("函数内的values[2] = %d\n", values[2]);
}

int main(void)
{
    int a[] = {1, 2, 3, 4, 5};
    change_element(a[2]);
    printf("传入元素后：a[2] = %d\n", a[2]);
    change_array(a);
    printf("传入数组后：a[2] = %d\n", a[2]);
    return 0;
}
