/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_A.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mezahir <mezahir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 14:48:17 by mezahir           #+#    #+#             */
/*   Updated: 2025/12/25 10:58:53 by mezahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pos_first_min_index(t_list *stack, int n)
{
	t_list	*node;
	int		i;

	i = 0;
	node = stack;
	while (node)
	{
		if (node->index < n)
			break ;
		i++;
		node = node->next;
	}
	return (i);
}

void	sort_a(t_list **stack_A, t_list **stack_B, int p)
{
	int	i;
	int	size;

	i = 0;
	size = ft_size_lst(*stack_A);
	while (i < size)
	{
		if ((*stack_A)->index <= i)
		{
			push_b(stack_A, stack_B);
			rb(stack_B);
			i++;
		}
		else if ((*stack_A)->index <= (p + i))
		{
			push_b(stack_A, stack_B);
			i++;
		}
		else if (pos_first_min_index(*stack_A, (i + p)) < ft_size_lst(*stack_A)
			/ 2)
			ra(stack_A);
		else
			rra(stack_A);
	}
	push_b_to_a(stack_A, stack_B);
}
