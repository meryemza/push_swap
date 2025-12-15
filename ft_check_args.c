#include "push_swap.h"

int ft_check_duplicate(t_list *stack)
{
    t_list *head;
    t_list *tmp;

    head = stack;
    while(head)
    {
        tmp = head;
        while(tmp -> next != NULL)
        {
            if(head-> value == tmp -> next -> value)
                return 0;
            tmp = tmp -> next;
        }
        head = head -> next;
    }
    return 1;
}

int ft_valide_number(char *arg)
{
    int i ;

    i = 1;
    if(arg[i] == '-' || arg[i] == '+' )
        i++;
    if(arg[i] == '\0')
        return 0;
    while(arg[i])
    {
        if(arg[i]>= '0' && arg[i] <= '9')
            i++;
        else
            return 0;
    }
    return 1;
}

void ft_fill_stack(t_list **stack,char *argv[])
{
    int i;
    i = 1;
    t_list *node;
    while(argv[i])
    {
        node = ft_lst_new(ft_atoi(argv[i]));
        if(!node)
            return;
        ft_add_back(stack,node);
        i++;
    }
}

int ft_check_args(t_list **stack,char *argv[])
{
    int i ;
    i = 1;
    while(argv[i])
    {
        if(ft_valide_number(char *arg))
            i++;
        else
        {
            write(2,"error\n",6);
            return 0;
        }
    }
    i = 1;
    while(argv[i])
    {
        ft_fill_stack(stack,&argv[i]);
        i++;
    }
    
}
