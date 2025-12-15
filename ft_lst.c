
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

void ft_add_back(t_list **stack,t_list *node)
{   
    if(!stack || !node)
        return ;
    t_list *head;
    head = *stack;
    if(*stack)
    {
    while(head -> next != NULL)
        head = head -> next;
    head -> next = node;
    }
    else
        *stack = node;
    return ;
}

t_list *ft_lst_new(int value)
{
    t_list *node;
    node = malloc(sizeof(t_list));
    if(!node)
        return (NULL);
    node -> value = value;
    node -> next = NULL;
    return (node);
}