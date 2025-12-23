/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mezahir <mezahir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 19:37:35 by mezahir           #+#    #+#             */
/*   Updated: 2025/12/23 23:19:43 by mezahir          ###   ########.fr       */
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
}
void rrb(t_list **stack_B)
{
    reverse_rotate(stack_B);
}
void rrr(t_list **stack_A,t_list **stack_B)
{
    reverse_rotate(stack_A);
    reverse_rotate(stack_B);
}