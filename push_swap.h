#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdlib.h>
typedef struct s_list
{
    int             value;
    int             index;
    struct s_list   *next;
}   t_list;

int ft_atoi(char *str);
int ft_check_duplicate(t_list **stack);

t_list *ft_last_lst(t_list **stack);


void ra(t_list **stack_A);
void rb(t_list **stack_B);
void rr(t_list **stack_A,t_list **stack_B);

void sa(t_list **stack_A);
void sb(t_list **stack_B);
void ss(t_list **stack_B,t_list **stack_A);

void rra(t_list **stack_A);
void rrb(t_list **stack_B);
void rrr(t_list **stack_A,t_list **stack_B);

void push_A(t_list **stack_A,t_list **stack_B);
void push_B(t_list **stack_A,t_list **stack_B);

#endif
