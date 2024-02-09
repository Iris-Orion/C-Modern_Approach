/* 记账本程序
* 清空账户余额、往账户上存钱、从账户上取钱、显示当前余额、退出程序。选择项分别
* 用整数 0、1、2、3 和 4 表示。
*/

#include <stdio.h>

int main(void)
{
    int cmd;
    float balance = 0.0f, credit, debit;

    printf("*** ACME checkbox-balancing program ***\n");
    printf("Commands: 0=clear, 1=credit, 2=debit, 3=balance, 4=exit\n\n");

    for(;;)
    {
        printf("Enter command: ");
        scanf("%d", &cmd);
        switch (cmd)
        {
            case 0:
                balance = 0.0f;
                break;
            case 1:
                printf("Enter amount of credit: ");
                scanf("%f", &credit);
                balance += credit;
                break;
            case 2:
                printf("Enter amount of debit: ");
                scanf("%f", &debit);
                balance -= debit;
                break;
            case 3:
                printf("Current balance: $%.2f\n", balance);
                break;
            case 4:
                return 0;
            default:
            printf("Commands: 0=clear, 1=credit, 2=debit, 3=balance, 4=exit\n\n");
            break;
        }
    }   
}