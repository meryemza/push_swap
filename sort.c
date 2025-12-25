/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mezahir <mezahir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 11:28:21 by mezahir           #+#    #+#             */
/*   Updated: 2025/12/25 11:00:22 by mezahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pos2(t_list **stack_A, t_list **stack_B)
{
	ra(stack_A);
	ra(stack_A);
	push_b(stack_A, stack_B);
}

void	pos3(t_list **stack_A, t_list **stack_B)
{
	rra(stack_A);
	rra(stack_A);
	push_b(stack_A, stack_B);
}

void	sort_3(t_list **stack_A)
{
	if ((*stack_A)->value == ft_max(*stack_A))
		ra(stack_A);
	else if ((*stack_A)->next->value == ft_max(*stack_A))
		rra(stack_A);
	if ((*stack_A)->value > (*stack_A)->next->value)
		sa(stack_A);
	else
		return ;
}

void	sort_4(t_list **stack_A, t_list **stack_B)
{
	int	pos;

	pos = ft_min(*stack_A);
	if (pos < 0)
		return ;
	if (pos == 0)
		push_b(stack_A, stack_B);
	else if (pos == 1)
	{
		sa(stack_A);
		push_b(stack_A, stack_B);
	}
	else if (pos == 2)
		pos2(stack_A, stack_B);
	else if (pos == 3)
	{
		rra(stack_A);
		if (ft_check_sorted(*stack_A))
			return ;
		push_b(stack_A, stack_B);
	}
	sort_3(stack_A);
	push_a(stack_A, stack_B);
}

void	sort_5(t_list **stack_A, t_list **stack_B)
{
	int	pos;

	pos = ft_min(*stack_A);
	if (pos < 0)
		return ;
	if (pos == 0)
		push_b(stack_A, stack_B);
	else if (pos == 1)
	{
		ra(stack_A);
		push_b(stack_A, stack_B);
	}
	else if (pos == 2)
		pos2(stack_A, stack_B);
	else if (pos == 3)
		pos3(stack_A, stack_B);
	else if (pos == 4)
	{
		rra(stack_A);
		if (ft_check_sorted(*stack_A))
			return ;
		push_b(stack_A, stack_B);
	}
	sort_4(stack_A, stack_B);
	push_a(stack_A, stack_B);
}
