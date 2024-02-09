/*
* Name : upc.c
* Purpose : 计算任意通用产品代码的校验位
* 输入： 产品代码的前11位。 输出：校验位
*/

#include <stdio.h>

int main(void)
{
    int d, i1, i2, i3, i4, i5, j1, j2, j3, j4, j5, first_sum, second_sum, check_digit;
    printf("Enter 11 digit: ");
    scanf("%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d", &d, &i1, &i2, &i3, &i4, &i5, &j1, &j2, &j3, &j4, &j5);
    first_sum = d + i2 + i4 + j1 + j3 + j5;
    second_sum = i1 + i3 + i5 + j2 + j4;
    check_digit = 9 - (first_sum * 3 + second_sum - 1) % 10;
    printf("Check digit: %d\n", check_digit);
    return 0;
}