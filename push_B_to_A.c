/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_B_to_A.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mezahir <mezahir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 20:01:44 by mezahir           #+#    #+#             */
/*   Updated: 2025/12/25 00:26:34 by mezahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_search_max(t_list *stack_b)
{
	int	max;

	max = stack_b->value;
	while (stack_b)
	{
		if (stack_b->value > max)
			max = stack_b->value;
		stack_b = stack_b->next;
	}
	return (max);
}

int	get_pos_max(t_list *B, int max)
{
	int		i;
	t_list	*node;

	i = 0;
	node = B;
	while (node)
	{
		if (node->value == max)
			break ;
		i++;
		node = node->next;
	}
	return (i);
}

void	push_b_to_a(t_list **A, t_list **B)
{
	int	max;
	int	pos_max;

	if (!(*B))
		return ;
	max = ft_search_max(*B);
	pos_max = get_pos_max(*B, max);
	while (ft_size_lst(*B) > 0)
	{
		if (max == (*B)->value)
		{
			push_a(A, B);
			if (ft_size_lst(*B) > 0)
			{
				max = ft_search_max(*B);
				pos_max = get_pos_max(*B, max);
			}
		}
		else if (pos_max <= ft_size_lst(*B) / 2)
			rb(B);
		else
			rrb(B);
	}
}
