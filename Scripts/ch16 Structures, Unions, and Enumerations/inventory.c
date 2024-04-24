/* maintain a database */

#include <stdio.h>
#include "readline.h"

#define NAME_LEN 25
#define MAX_PARTS 100

struct part {
    int number;
    char name[NAME_LEN+1];
    int on_hand;
} inventory[MAX_PARTS];

int num_parts = 0; /* 当前存储的零件数量 */

int find_part(int number);
void insert(void);
void search(void);
void update(void);
void print(void);

/***********************************************
* 提示用户输入操作代码，然后调用函数来执行请求的操作。
* 重复直到用户输入命令'q'。如果用户输入了非法代码，则打印错误消息。
************************************************/
int main(void)
{
    char code;

    for (;;)
    {
        printf("Enter operation code: ");
        scanf(" %c", &code);
        while (getchar() != '\n')
        {
            ;
        }
        switch (code)
        {
            case 'i':
                    insert();
                    break;
            case 's':
                    search();
                    break;
            case 'u':
                    update();
                    break;
            case 'p':
                    print();
                    break;
            case 'q':
                    return 0;
            default:
                    printf("Illeagal code\n");
        }
        printf("\n");
    }
}


/**************************************************
* find_part: 在库存数组中查找零件号。如果找到零件编号，
* 则返回数组索引；否则，返回-1。
***************************************************/
int find_part(int number)
{
    int i;

    for (i = 0; i < num_parts; i++)
    {
        if (inventory[i].number == number)
        {
            return i;
        }
    }
    return -1;
}

/**************************************************
* insert: 提示用户输入有关新零件的信息，
* 然后将该零件插入数据库。如果零件已存在或数据库已满，
* 则打印错误消息并提前返回。
***************************************************/
void insert(void)
{
    int part_number;

    /*数据库已满返回*/
    if (num_parts == MAX_PARTS)
    {
        printf("Database is full; can't add more parts.\n");
        return;
    }

    printf("Enter part number: ");
    scanf("%d", &part_number);

    /*零件存在返回*/
    if (find_part(part_number) >= 0)
    {
        printf("Part already exists.\n");
        return;
    }

    /*存入新零件信息*/
    inventory[num_parts].number = part_number;
    printf("Enter part name: ");
    read_line(inventory[num_parts].name, NAME_LEN);
    printf("Enter quantity on hand: ");
    scanf("%d", &inventory[num_parts].on_hand);
    num_parts++;
}

/**************************************************
* search: 提示用户输入零件号，然后在数据库中查找零件。
* 如果零件存在，则打印现有的名称和数量；
* 如果没有，则打印一条错误消息。
***************************************************/
void search(void)
{
    int i, number;

    printf("Enter part number: ");
    scanf("%d", &number);
    i = find_part(number);
    if (i >= 0)
    {
        printf("Part name: %s\n", inventory[i].name);
        printf("Quantity on hand: %d\n", inventory[i].on_hand);
    }
    else
    {
        printf("Part not found.\n");
    }
}

/**************************************************
* update: 提示用户输入零件号。如果零件不存在，
* 则打印错误消息；否则，提示用户输入库存量变化并更新数据库。
***************************************************/
void update(void)
{
    int i, number, change;

    printf("Enter part number: ");
    scanf("%d", &number);
    i = find_part(number);
    if (i >= 0)
    {
        printf("Enter change in quantity on hand: ");
        scanf("%d", &change);
        inventory[i].on_hand += change;
    }
    else
    {
        printf("Part not found.\n");
    }
}

/**************************************************
* print: 打印数据库中所有零件的列表，
* 显示零件号、零件名称和现有数量。零件按输入数据库时的顺序打印。
***************************************************/
void print(void)
{
    int i;

    printf("Part Number     Part name           "
           "Quantity on Hand\n");
    for (i = 0; i < num_parts; i++)
    {
        printf("%7d     %-25s%11d\n", inventory[i].number, 
                inventory[i].name, inventory[i].on_hand);
    }
}

