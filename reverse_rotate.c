/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mezahir <mezahir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 11:07:59 by mezahir           #+#    #+#             */
/*   Updated: 2025/12/16 11:08:53 by mezahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void reverse_rotate(t_list **stack)
{
    t_list *head;
    t_list *last;
    t_list *tmp;
    
    head = *stack;
    tmp = head;
    if(!*stack || (*stack) -> next == NULL)
        return ;
    while(head -> next -> next != NULL)
        head = head -> next ;
    last = head -> next;
    head -> next = NULL;
    *stack = last;
    last -> next = tmp;
}
void rra(t_list **stack_A)
{
    reverse_rotate(stack_A);
    write(1,"rra\n",4);
}
void rrb(t_list **stack_B)
{
    reverse_rotate(stack_B);
    write(1,"rrb\n",4);
}
void rrr(t_list **stack_A,t_list **stack_B)
{
    reverse_rotate(stack_A);
    reverse_rotate(stack_B);
    write(1,"rrr\n",4);
}