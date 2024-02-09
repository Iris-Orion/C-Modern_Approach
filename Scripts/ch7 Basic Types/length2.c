/* 确定消息的长度, 程序缩短形式 */

#include <stdio.h>

int main(void)
{
    int len = 0;

    printf("Enter a message: ");

    while (getchar() != '\n')
    {
        len++;
    }
    printf("Your message was %d character(s) long.\n", len);
    return 0;
}