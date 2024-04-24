#include <stdio.h>
#include "word.h"

int read_char(void)
{
    int ch = getchar();

    if (ch == '\n' || ch == '\t')    /*换行或者制表符*/
    {
        return ' ';
    }
    return ch;
}

int read_word(char *word, int len)
{
    int ch, pos = 0;

    while ((ch = read_char()) == ' ')
        ;
    while (ch != ' ' && ch != EOF)
    {
        if (pos < len)
        {
            word[pos++] = ch;
        }
        ch = read_char();
    }
    return pos;
}