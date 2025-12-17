/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mezahir <mezahir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 11:28:21 by mezahir           #+#    #+#             */
/*   Updated: 2025/12/17 14:27:16 by mezahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_min(t_list *stack_A)
{
   int min;
   int i;
   int pos;
   t_list *node;
   
   node = stack_A;
   if(!node)
        return (-1);
   i = 0;
   pos = 0;
   min = node -> value;
   while(node)
   {
    if(min > (node -> value))
    {
        min = node -> value;
        pos = i;
    }
    node = node -> next ;
    i++;
   }
   return (pos);
}
void pos2(t_list **stack_A,t_list **stack_B)
{
    ra(stack_A);
    ra(stack_A);
    push_B(stack_A,stack_B);
}

void pos3(t_list **stack_A,t_list **stack_B)
{
    rra(stack_A);
    rra(stack_A);
    push_B(stack_A,stack_B);
}
void sort_3(t_list **stack_A)
{
    int x;
    int y;
    int z;
    
    x = (*stack_A) -> value;
    y = (*stack_A) -> next -> value ;
    z = (*stack_A) -> next-> next -> value;
    if(x > y && x > z)
        ra(stack_A);
    else if(y > x && y > z)
        rra(stack_A);
    if(x > y)
        sa(stack_A);
}
void sort_4(t_list **stack_A,t_list **stack_B)
{
   int pos;
    
   pos = ft_min(*stack_A);
   if(pos < 0)
        return;
   if(pos == 0)
    push_B(stack_A,stack_B);
   else if (pos == 1)
   {
    sa(stack_A);
    push_B(stack_A,stack_B);
   }
   else if(pos == 2)
        pos2(stack_A,stack_B);
   else
    {
        rra(stack_A);
        push_B(stack_A,stack_B);
    }
    sort_3(stack_A);
    push_A(stack_A,stack_B);
}
void sort_5(t_list **stack_A,t_list **stack_B)
{
int pos;

   pos = ft_min(*stack_A);
   if(pos < 0)
        return;
   if(pos == 0)
        push_B(stack_A,stack_B);
    else if(pos == 1)
    {
        ra(stack_A);
        push_B(stack_A,stack_B);
    }
    else if(pos == 2)
        pos2(stack_A,stack_B);
    else if(pos == 3)
       pos3(stack_A,stack_B);
    else  
    {
        rra(stack_A);
        push_B(stack_A,stack_B);
    } 
    sort_4(stack_A,stack_B);
    push_A(stack_A,stack_B);
}
