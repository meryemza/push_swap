/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mezahir <mezahir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 19:26:50 by mezahir           #+#    #+#             */
/*   Updated: 2025/12/23 23:19:26 by mezahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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
}
void rb(t_list **stack_B)
{
    rotate(stack_B);
}
void rr(t_list **stack_A,t_list **stack_B)
{
    rotate(stack_A);
    rotate(stack_B);
}