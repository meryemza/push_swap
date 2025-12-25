/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mezahir <mezahir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 11:07:51 by mezahir           #+#    #+#             */
/*   Updated: 2025/12/24 23:30:45 by mezahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_list **stack_A, t_list **stack_B)
{
	t_list	*head_a;
	t_list	*head_b;

	if (!*stack_B)
		return ;
	head_a = *stack_A;
	head_b = *stack_B;
	*stack_B = head_b->next;
	*stack_A = head_b;
	head_b->next = head_a;
	write(1, "pa\n", 3);
}

void	push_b(t_list **stack_A, t_list **stack_B)
{
	t_list	*head_a;
	t_list	*head_b;

	if (!*stack_A)
		return ;
	head_a = *stack_A;
	head_b = *stack_B;
	*stack_A = head_a->next;
	*stack_B = head_a;
	head_a->next = head_b;
	write(1, "pb\n", 3);
}
