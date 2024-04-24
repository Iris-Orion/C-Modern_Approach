/* 下面这个程序显示一个表格，
*  这个表格显示了在几年时间内 100 美元投资在不同利率下的
*  价值。用户输入利率和要投资的年数。
*  投资总价值每年计算一次，表格将显示出在输入利率和
*  紧随其后的 4 个更高的利率下投资的总价值。 */

#include <stdio.h>

#define NUM_RATES ((int) (sizeof(value) / sizeof(value[0])))
#define INITIAL_BALANCE 100.00

int main(void)
{
    int i, low_rate, num_years, year;
    double value[5];

    printf("Enter interest rate: ");
    scanf("%d", &low_rate);
    printf("Enter number of years: ");
    scanf("%d", &num_years);

    printf("\nYears");
    for (i = 0; i < NUM_RATES; i++)
    {
        printf("%6d%%", low_rate + i);
        value[i] = INITIAL_BALANCE;
    }
    printf("\n");

    for (year = 1; year <= num_years; year++)
    {
        printf("%3d    ", year);
        for (i = 0; i < NUM_RATES; i++)
        {
            value[i] += value[i] * (low_rate + i) / 100; 
            printf("%7.2f", value[i]);
        }
        printf("\n");
    }

    return 0;
}