/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mezahir <mezahir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 20:36:34 by mezahir           #+#    #+#             */
/*   Updated: 2025/12/25 11:14:10 by mezahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	instruction(t_list **A, t_list **B, char *line)
{
	if (ft_strcmp(line, "sa\n"))
		sa(A);
	else if (ft_strcmp(line, "sb\n"))
		sb(B);
	else if (ft_strcmp(line, "ss\n"))
		ss(B, A);
	else if (ft_strcmp(line, "pa\n"))
		push_a(A, B);
	else if (ft_strcmp(line, "pb\n"))
		push_b(A, B);
	else if (ft_strcmp(line, "rb\n"))
		rb(B);
	else if (ft_strcmp(line, "ra\n"))
		ra(A);
	else if (ft_strcmp(line, "rr\n"))
		rr(A, B);
	else if (ft_strcmp(line, "rra\n"))
		rra(A);
	else if (ft_strcmp(line, "rrb\n"))
		rrb(B);
	else if (ft_strcmp(line, "rrr\n"))
		rrr(A, B);
	else
		return (0);
	return (1);
}

void	ft_cheker(t_list **A, t_list **B)
{
	char	*line;

	line = get_next_line(0);
	while (line != NULL)
	{
		if (!instruction(A, B, line))
		{
			write(2, "Error\n", 6);
			free(line);
			ft_free_lst(A);
			exit(1);
		}
		free(line);
		line = get_next_line(0);
	}
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

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
	ft_cheker(&stack_a, &stack_b);
	if (ft_check_sorted(stack_a) == 1 && !stack_b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	ft_free_lst(&stack_a);
	if (ft_size_lst(stack_b))
		ft_free_lst(&stack_b);
	return (0);
}
