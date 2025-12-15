#include "push_swap.h"

void rotate(t_list **stack)
{
    t_list *head;
    t_list *last;

    head = *stack;
    last = ft_last_lst(stack);
    if(!*stack || (*stack) -> next == NULL )
        return ;
    *stack = head -> next;
    last -> next = head;
    head -> next = NULL;
}
void ra(t_list **stack_A)
{
    rotate(stack_A);
    write(1,"ra\n",3);
}
void rb(t_list **stack_B)
{
    rotate(stack_B);
    write(1,"rb\n",3);
}
void rr(t_list **stack_A,t_list **stack_B)
{
    rotate(stack_A);
    rotate(stack_B);
    write(1,"rr\n",3);
}