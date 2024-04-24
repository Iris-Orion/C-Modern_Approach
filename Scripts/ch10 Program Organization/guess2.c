/* 猜测随机数 使用形式参数版本*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUMBER 100

void initialize_number_generator(void);
int new_secret_number(void);
void read_guesses(int secret_number);

int main(void)
{
    char command;
    int secret_number;

    printf("Guess the secret number between 1 and %d.\n\n", MAX_NUMBER);
    initialize_number_generator();
    do{
        secret_number = new_secret_number();
        printf("A new number has been choosen.\n");
        read_guesses(secret_number);
        printf("Play again? (Y/N) ");
        scanf(" %c", &command);
        printf("\n");
    }while (command == 'y' || command == 'Y');

    return 0;
}

/*******************************************************************
*initialize_number_generator: 用于设置伪随机数生成器的种子(seed)的代码。
*srand 函数用于设置随机数生成器的初始值，
*而time(NULL)函数返回当前时间的秒数。
********************************************************************/
void initialize_number_generator(void)
{
    srand((unsigned) time(NULL));
}

/*********************************************************************
*new_secret_number: 随机选择一个在1和MAX_NUMBER之间的数并把它存到
*secret_number中
*********************************************************************/
int new_secret_number(void)
{
    return rand() % MAX_NUMBER + 1;
}

/*********************************************************************
*read_guesses: 随机选择一个在1和MAX_NUMBER之间的数并把它存到
*secret_number中
*********************************************************************/
void read_guesses(int secret_number)
{
    int guess, num_guesses = 0;

    for(;;)
    {
        num_guesses++;
        printf("Enter guess: ");
        scanf("%d", &guess);
        if (guess == secret_number)
        {
            printf("You won in %d guesses\n\n", num_guesses);
            return;
        }
        else if (guess < secret_number)
        {
            printf("Too low; try again.\n");
        }
        else
        {
            printf("Too high; try again.\n");
        }
    }
}