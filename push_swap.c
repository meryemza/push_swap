/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mezahir <mezahir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 11:07:35 by mezahir           #+#    #+#             */
/*   Updated: 2025/12/25 12:49:48 by mezahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort(t_list **stack_a, t_list **stack_b, int size)
{
	if (size == 2)
	{
		if ((*stack_a)->value > ((*stack_a)->next)->value)
			sa(stack_a);
		else
			return ;
	}
	else if (size == 3)
		sort_3(stack_a);
	else if (size == 4)
		sort_4(stack_a, stack_b);
	else if (size == 5)
		sort_5(stack_a, stack_b);
	else
		big_sort(stack_a, stack_b);
}

int	ft_check_sorted(t_list *stack_a)
{
	t_list	*node;

	node = stack_a;
	while (node != NULL && node->next != NULL)
	{
		if ((node->value) > ((node->next)->value))
			return (0);
		node = node->next;
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		size;

	if (argc < 2)
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	if (ft_check_args(&stack_a, argv) == 0 || ft_check_duplicate(stack_a) == 0)
	{
		write(2, "Error\n", 6);
		ft_free_lst(&stack_a);
		exit(1);
	}
	size = ft_size_lst(stack_a);
	if (ft_check_sorted(stack_a) == 1)
	{
		ft_free_lst(&stack_a);
		return (0);
	}
	else
		ft_sort(&stack_a, &stack_b, size);
	ft_free_lst(&stack_a);
	return (0);
}
