/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mezahir <mezahir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 19:37:35 by mezahir           #+#    #+#             */
/*   Updated: 2025/12/21 13:38:16 by mezahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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