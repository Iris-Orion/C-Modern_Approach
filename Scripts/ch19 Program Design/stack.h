#ifndef STACK_H_
#define STACK_H_

#include <stdbool.h>   /*introduced in C99*/

void make_empty(void);
bool is_empty(void);
bool is_full(void);
void push(int i);
int pop(void);

#endif