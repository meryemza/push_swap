/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mezahir <mezahir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 11:07:35 by mezahir           #+#    #+#             */
/*   Updated: 2025/12/20 18:43:43 by mezahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_sort(t_list **stack_A,t_list **stack_B,int size)
{
    if(size == 2)
    {
        if((*stack_A) -> value > ((*stack_A )-> next) -> value)
            sa(stack_A);
        else
            return ;
    }
    else if(size == 3)
        sort_3(stack_A);
    else if (size == 4)
        sort_4(stack_A,stack_B);
    else if (size == 5)
        sort_5(stack_A,stack_B);
    else
        big_sort(stack_A,stack_B);
}

int ft_check_sorted(t_list *stack_A)
{
   t_list *node;
   node = stack_A;
   
   while(node != NULL && node -> next != NULL)
   {
    if((node -> value) > ((node -> next )-> value))
        return (0);
    node = node -> next;
   }
   return (1);
}

int main(int argc, char *argv[])
{
    t_list *stack_A;
    t_list *stack_B;
    int size;
    
    if(argc < 2)
        return (0);
    stack_A = NULL;
    stack_B = NULL;
    if(ft_check_args(&stack_A,argv) == 0 || ft_check_duplicate(stack_A) == 0)
    {
        write(2,"ERROR\n",6);
        ft_free_lst(stack_A);
        return (0);
    }
    size = ft_size_lst(stack_A);
   
    if(ft_check_sorted(stack_A) == 1)
        {
            ft_free_lst(stack_A);
            return (0);
        }
    else
        ft_sort(&stack_A,&stack_B,size);
    ft_free_lst(stack_A);
    return (0);
}

