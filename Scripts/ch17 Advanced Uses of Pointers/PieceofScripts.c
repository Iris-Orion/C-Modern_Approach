#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

/* 链表中单个节点的结构，假设只包含一个整数 */
struct node{
    int value;
    struct node *next;
};

/* 往链表中插入结点 */
struct node *add_to_list(struct node *list, int n)
{
    struct node *new_node;

    new_node = malloc(sizeof(struct node));
    if (new_node == NULL)
    {
        printf("Error: malloc failed in add_to_list\n");
        exit(EXIT_FAILURE);
    }
    new_node->value = n;
    new_node->next = list;
    return new_node;
}

/* 往链表中插入结点，使用指向指针的指针 */
void add_to_list_V2(struct node **list, int n)
{
    struct node *new_node;

    new_node = malloc(sizeof(struct node));
    if (new_node == NULL)
    {
        printf("Error: malloc failed in add_to_list\n");
        exit(EXIT_FAILURE);
    }
    new_node->value = n;
    new_node->next = list;
    *list = new_node;
}

/* 用 add_to_list 来创建一个含有用户输入的数的链表 */
struct node *read_numbers(void)
{
    struct node *first = NULL;
    int n;

    printf("Enter a series of integers (0 to terminate): ");
    for (;;)
    {
        scanf("%d", &n);
        if (n == 0)
            return first;
        first = add_to_list(first, n);
    }
}

/* 搜索链表， 找到整数n， 如果找到返回含有n的结点的指针，否则返回空指针*/
struct node *search_list(struct node *list, int n)
{
    struct node *p;

    for (p = list; p != NULL; p = p->next)
    {
        if (p->value == n)
        {
            return p;
        }
        return NULL;
    }
}

/* 另一个版本 */
struct node *search_list_V2(struct node *list, int n)
{
    for (; list != NULL; list = list->next)
    {
        if (list->value == n)
        {
            return list;
        }
        return NULL;
    }
}

/* 另一个版本 */
struct node *search_list_V3(struct node *list, int n)
{
    for (; list != NULL && list->value != n; list = list->next)
        ;
    return list;
}

/* while版本 */
struct node *search_list_V3(struct node *list, int n)
{
    while (list != NULL && list->value != n)
        list = list->next;
    return list;
}

/* 删除链表节点 */
struct node *delete_from_list(struct node *list, int n)
{
    struct node *cur, *prev;

    for (cur = list, prev = NULL; 
         cur != NULL && cur->value != n;
         prev = cur, cur = cur->next)
         ;
    if (cur == NULL)
        return list;                //未找到n
    if (prev == NULL)
        list = list->next;          // n是第一个元素
    else
        prev->next = cur->next;
    free(cur);
    return list;
}


