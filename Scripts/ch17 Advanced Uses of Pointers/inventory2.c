/* 维护零件数据库，链表实现 */
#include <stdio.h>
#include <stdlib.h>
#include "readline.h"

#define NAME_LEN 25

struct part
{
    int number;
    char name[NAME_LEN+1];
    int on_hand;
    struct part *next;
};

struct part *inventory = NULL;  /* 指向第一个零件 */

struct part *find_part(int number); /* 查找 */
void insert(void);
void search(void);
void update(void);
void print(void);

/************************************************************
* main: 提示用户输入操作代码，然后调用函数来执行请求的**操作。
* 重复直到用户输入命令'q'。如果用户输入了非法代码，则打印错误消息。
*************************************************************/
int main(void)
{
    char code;

    for (;;)
    {
        printf("Enter operation code: ");
        scanf(" %c", &code);
        while (getchar() != '\n')
            ;
        switch (code)
        {
            case 'i': insert();
                      break;
            case 's': search();
                      break;
            case 'u': update();
                      break;
            case 'p': print();
                      break;
            case 'q': return 0;
            default: printf("Illeagel code\n");
        }
        printf("\n");
    }
}

/************************************************************
* find_part: 在库存列表中查找零件号。返回指向包含零件号的节点的指针；
* 如果找不到零件号，则返回NULL。
*************************************************************/
struct part *find_part(int number)
{
    struct part *p;

    for (p = inventory; p != NULL && number > p->number; p = p->next)
        ;
    if (p != NULL && number == p->number)
        return p;
    return NULL;
}

/************************************************************
* insert: 提示用户输入有关新零件的信息，然后将该零件插入库存列表；
* 列表仍按零件号排序。如果零件已存在**或无法为零件分配空间，
* 则打印错误消息并提前返回
*************************************************************/
void insert(void)
{
    struct part *cur, *prev, *new_node;

    new_node = malloc(sizeof(struct part));
    if (new_node == NULL)
    {
        printf("Database is full; can't add more parts.\n");
        return;
    }

    printf("Enter part number: ");
    scanf("%d", &new_node->number);

    for (cur = inventory, prev = NULL; 
         cur != NULL && new_node->number > cur->number;
         prev = cur, cur = cur->next)
         ;
    if (cur != NULL && new_node->number == cur->number)
    {
        printf("Part already exists.\n");
        free(new_node);
        return;
    }

    printf("Enter part name: ");
    read_line(new_node->name, NAME_LEN);
    printf("Enter quantity on hand: ");
    scanf("%d", &new_node->on_hand);
    new_node->next = cur;
    if (prev == NULL)
        inventory = new_node;
    else
        prev->next = new_node;
}

/********************************************************** 
 * search: 提示用户输入零件号，然后在数据库中查找零件。
 * 如果零件存在，则打印现有的名称和数量；
 * 如果没有，则打印一条错误消息。
 **********************************************************/ 
void search(void)
{
    int number;
    struct part *p;

    printf("Enter part number: ");
    scanf("%d", &number);
    p = find_part(number);
    if (p != NULL)
    {
        printf("Part name: %s\n", p->name);
        printf("Quantity on hand: %d\n", p->on_hand);
    }
    else
    {
        printf("Part not found.\n");
    }
}

/********************************************************** 
 * update: 提示用户输入零件号。如果零件不存在，则打印错误消息；
 * 否则，提示用户输入库存量变化并更新数据库。
 **********************************************************/ 
void update(void)
{
    int number, change;
    struct part *p;

    printf("Enter part number: ");
    scanf("%d", &number);
    p = find_part (number);
    if (p != NULL)
    {
        printf("Enter change in quantity on hand: ");
        scanf("%d", &change);
        p->on_hand += change;
    }
    else
    {
        printf("Part not found.\n");
    }
}

/********************************************************** 
 * print: 打印数据库中所有零件的列表，
 * 显示零件号、零件名称和现有数量。零件号将按升序显示。
 **********************************************************/
void print(void)
{
    struct part *p;
    printf("Part Number     Part Name                   "
           "Quantity on hand\n");
    for (p = inventory; p != NULL; p = p->next)
    {
        printf("%7d         %-25s%11d\n", p->number, p->name, p->on_hand);
    }
}









