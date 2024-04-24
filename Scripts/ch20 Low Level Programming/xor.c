/* XOR 加密*/
/********** in powershell use these command***********
***Get-Content msg | .\xor.exe | Set-Content newmsg***
*******************************************************/
#include <ctype.h>
#include <stdio.h>

#define KEY '&'

int main(void)
{
    int orig_char, new_char;

    while ((orig_char = getchar()) != EOF)
    {
        new_char = orig_char ^ KEY;
        // isprint用于检查传递给它的字符是否是可打印的字符
        if (isprint(orig_char) && isprint(new_char))
            putchar(new_char);
        else
            putchar(orig_char);
    }
    return 0;
}