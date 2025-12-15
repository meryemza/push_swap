
#include "push_swap.h"

t_list *ft_last_lst(t_list **stack)
{
    if(!*stack)
        return NULL;
    t_list *head;
    head = *stack;
    while(head -> next != NULL)
        head = head -> next;
    return head;
}

