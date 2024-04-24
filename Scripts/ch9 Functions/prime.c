/* 检查一个数是否为素数 
*  给定数 n 后，is_prime函数把 n 除以从
*  2 到 n 的平方根之间的每一个数，只要有一个余数为 0，n 就不是素数。
*/

#include <stdbool.h>
#include <stdio.h>

bool is_prime(int n)
{
    int divisor;

    if (n <= 1)
        return false;
    for (divisor = 2; divisor * divisor <= n; divisor++)
    {
        if (n % divisor == 0)
            return false;
    }
    return true;
}

int main(void)
{
    int n;

    printf("Enter a number: ");
    scanf("%d", &n);
    if  (is_prime(n))
        printf("Prime\n");
    else
        printf("Not prime\n");
    
    return 0;
}

