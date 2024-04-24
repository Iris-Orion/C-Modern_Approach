/* 检查数中是否有出现多于一次的数字 */

#include <stdbool.h>
#include <stdio.h>

int main(void)
{
    bool digit_seen[10] = {false};
    int digit;  // 数字的每一位
    long n;     //输入的数字

    printf("Enter a number: ");
    scanf("%ld", &n);
    
    while (n > 0)
    {
        digit = n % 10;
        if (digit_seen[digit])
            break;
        digit_seen[digit] = true;
        n /= 10;
    }

    if (n > 0)
    {
        printf("Repeated digit\n");
    }
    else 
    {
        printf("No repeated digit\n");
    }

    return 0;
}