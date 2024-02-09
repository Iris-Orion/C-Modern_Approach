/*
* Name: addfrac.c
* Purpose: 修改 3.2 节的 addfrac.c 程序，使用户可以同时输入两个分数，中间用加号隔开：
*
* Enter two fractions separated by a plus sign: 5/6+3/4
* The sum is 38/24
*/

#include <stdio.h>

int main(void)
{
    int num1, denom1, num2, denom2, result_num, result_denom;
    printf("Enter two fractions separated by a plus sign: ");
    scanf("%d/%d+%d/%d", &num1, &denom1, &num2, &denom2);

    result_num = num1 * denom2 + num2 * denom1;
    result_denom = denom1 * denom2;
    printf("The sum is %d/%d", result_num, result_denom);

    return 0;
}