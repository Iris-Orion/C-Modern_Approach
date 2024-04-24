/* 程序负责发一副标准纸牌。每张标准纸
*  牌都有一种花色（梅花、方块、红桃或黑桃）
*  和一个点数（2、3、4、5、6、7、8、9、10、J、
*  Q、K 或 A）。程序需要用户指明手里应该握有几张牌：*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_SUITS 4    // 花色、梅花、方块、黑桃
#define NUM_RANKS 13   // 点数

int main(void)
{
    bool in_hand[NUM_SUITS][NUM_RANKS] = {false};
    int num_cards, rank, suit;
    const char rank_code[] = {'2', '3', '4', '5', '6', '7', '8',
                              '9', 't', 'j', 'q', 'k', 'a'};
    const char suit_code[] = {'c', 'd', 'h', 's'};
    srand((unsigned) time(NULL));
    printf("Enter number of cards in hand: ");
    scanf("%d", &num_cards);
    printf("Your hand: ");
    while (num_cards > 0)
    {
        suit = rand() % NUM_SUITS;
        rank = rand() % NUM_RANKS;
        if (!in_hand[suit][rank])
        {
            in_hand[suit][rank] = true;
            num_cards--;
            printf(" %c%c", rank_code[rank], suit_code[suit]);
        }
    }
    printf("\n");

    return 0;
}