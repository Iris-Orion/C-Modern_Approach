/* 读取扑克手牌 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_RANKS 13  // 点数 : 2 --- k a
#define NUM_SUITS 4   // 花色 : c d h s
#define NUM_CARDS 5   // 手牌数量

int num_in_rank[NUM_RANKS];
int num_in_suit[NUM_SUITS];
bool straight, flush, four, three;
int pairs;

void read_cards(void);
void analyze_hand(void);
void print_result(void);

int main(void)
{
    for (;;)
    {
        read_cards();
        analyze_hand();
        print_result();
    }
}

/*************************************************************************
*read_cards: 读取手牌，将点数和花色分别存入 num_in_rank 和 num_in_suit数组中
**************************************************************************/
void read_cards(void)
{
    bool card_exists[NUM_RANKS][NUM_SUITS];
    char ch, rank_ch, suit_ch;
    int rank, suit;
    bool bad_card;
    int cards_read = 0;

    // 初始化num_in_rank， card_exists数组
    for (rank = 0; rank < NUM_RANKS; rank++)
    {
        num_in_rank[rank] = 0;
        for (suit = 0; suit < NUM_SUITS; suit++)
        {
            card_exists[rank][suit] = false;
        }
    }

    for (suit = 0; suit < NUM_SUITS; suit++)
    {
        num_in_suit[suit] = 0;
    }

    while (cards_read < NUM_CARDS)
    {
        bad_card = false;
        
        printf("Enter a card: ");

        rank_ch = getchar();

        switch (rank_ch)
        {
            case '0' :            exit(EXIT_SUCCESS);
            case '2' :            rank = 0; break;
            case '3' :            rank = 1; break;
            case '4' :            rank = 2; break;
            case '5' :            rank = 3; break;
            case '6' :            rank = 4; break;
            case '7' :            rank = 5; break;
            case '8' :            rank = 6; break;
            case '9' :            rank = 7; break;
            case 't' : case 'T' : rank = 8; break;
            case 'j' : case 'J' : rank = 9; break;
            case 'q' : case 'Q' : rank = 10; break;
            case 'k' : case 'K' : rank = 11; break;
            case 'a' : case 'A' : rank = 12; break;
            default:              bad_card = true;
        }

        suit_ch = getchar();
        switch(suit_ch)
        {
            case 'c' :  case 'C' : suit = 0; break;
            case 'd' :  case 'D' : suit = 1; break;
            case 'h' :  case 'H' : suit = 2; break;
            case 's' :  case 'S' : suit = 3; break;
            default:               bad_card = true;
        }
    
        while ((ch = getchar()) != '\n')
        {
            if (ch != ' ') bad_card = true;
        }

        if (bad_card)
        {
            printf("Bad card; ignored.\n");
        }
        else if (card_exists[rank][suit])
        {
            printf("Duplicate card; ignored.\n");
        }
        else
        {
            num_in_rank[rank]++;
            num_in_suit[suit]++;
            card_exists[rank][suit] = true;
            cards_read++;
        }
    }
}

/*************************************************************************
*analyze_hand: 分析手牌的情况，顺子 同花 四张 三张 对子可以组成以下的牌面
同花顺（即顺序相连又都是同花色）。
四张（4 张牌点数相同）。
葫芦（3 张牌是同样的点数，另外 2 张牌是同样的点数）。
同花（5 张牌是同花色的）。
顺子（5 张牌的点数顺序相连）。
三张（3 张牌的点数相同）。
两对。
对于（2 张牌的点数相同）。
其他牌（任何其他情况的牌）。
**************************************************************************/
void analyze_hand(void)
{
    int num_consec = 0;
    int rank, suit;

    straight = false;
    flush = false;
    four = false;
    three = false;
    pairs = 0;

    /* 检测同花 */
    for (suit = 0; suit < NUM_SUITS; suit++)
    {
        if (num_in_suit[suit] == NUM_CARDS)
        {
            flush = true;
        }
    }

    /* 检测是否是顺子 */
    rank = 0;
    while (num_in_rank[rank] == 0)
    {
        rank++;
    }
    for (; rank < NUM_RANKS && num_in_rank[rank] > 0; rank++)
    {
        num_consec++;
    }
    if (num_consec == NUM_CARDS)
    {
        straight = true;
        return;
    }

    /* 检测四张相同，三张相同，和对子的数量*/
    for (rank = 0; rank < NUM_RANKS; rank++)
    {
        if (num_in_rank[rank] == 4) four = true;
        if (num_in_rank[rank] == 3) three = true;
        if (num_in_rank[rank] == 2) pairs++; 
    }
}

/*************************************************************************
*print_result: 打印结果
**************************************************************************/
void print_result(void)
{
    if (straight && flush)  printf("Straight flush"); //同花顺（即顺序相连又都是同花色）。
    else if (four)          printf("Four of a kind"); //四张
    else if (three && 
             pairs == 1)    printf("Full house");       //葫芦
    else if (flush)         printf("Flush");            //同花
    else if (straight)      printf("Straight");         //顺子
    else if (three)         printf("Three of a kind");  //三张
    else if (pairs == 2)    printf("Two pairs");        //两对
    else if (pairs == 1)    printf("Pair");             //一对
    else                    printf("High card");        //其他情况

    printf("\n\n");
}