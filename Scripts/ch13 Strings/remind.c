/* 显示一个月的每日提醒列表。用户需要输入一系列提醒，
** 每条提醒都要有一个前缀来说明是一个月中的哪一天。
** 当用户输入的是 0 而不是有效的日期时，
** 程序会显示出输入的全部提醒的列表，并按日期排序。*/

#include <stdio.h>
#include <string.h>

#define MAX_REMIND 50   /* 最多提醒数量 */
#define MSG_LEN 60     /* 提醒信息最长长度  */

int read_line(char str[], int n);

int main(void)
{
    char reminders[MAX_REMIND][MSG_LEN+3];
    char day_str[3], msg_str[MSG_LEN+1];    /* sprintf会自动添加\0，day_str因此长度为3 */
    int day, i, j, num_remind = 0;

    for (;;)
    {
        if (num_remind == MAX_REMIND)
        {
            printf("-- No space left --\n");
            break;
        }

        printf("Enter day and reminder: ");
        scanf("%2d", &day);
        if (day == 0)
            break;
        sprintf(day_str, "%2d", day);
        read_line(msg_str, MSG_LEN);

        /* 插入排序, 保证提醒信息按日期排序 */
        /* strcmp函数逐个比较字符，所以这里只会比较日期，同一天的也会插入 */
        for (i = 0; i < num_remind; i++)
        {
            if(strcmp(day_str, reminders[i]) < 0)
                break;
        }
        for (j = num_remind; j > i; j--)
        {
            strcpy(reminders[j], reminders[j-1]);
        }

        strcpy(reminders[i], day_str);
        strcat(reminders[i], msg_str);

        num_remind++;
    }
    printf("\nDay Reminder\n");
    for (i = 0; i < num_remind; i++)
    {
        printf(" %s\n", reminders[i]);
    }

    return 0;
}

int read_line(char str[], int n)
{
    int ch, i = 0;

    while ((ch = getchar()) != '\n')
    {
        if (i < n)
        {
            str[i++] = ch;
        }
    }
    str[i] = '\0';
    return i;
}