#include "push_swap.h"

void push_A(t_list **stack_A,t_list **stack_B)
{
    t_list *head_A;
    t_list *head_B;
    
    if(!*stack_B)
        return;
    head_A  = *stack_A;
    head_B = *stack_B;
    *stack_B = head_B -> next;
    *stack_A = head_B;
    head_B -> next = head_A;
    write(1,"pa\n",3);
}
void push_B(t_list **stack_A,t_list **stack_B)
{
    t_list *head_A;
    t_list *head_B;
    
    if(!*stack_A)
        return;
    head_A  = *stack_A;
    head_B = *stack_B;
    *stack_A = head_A -> next;
    *stack_B = head_A;
    head_A -> next = head_B;
    write(1,"pb\n",3);
}