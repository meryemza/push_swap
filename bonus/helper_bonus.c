/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mezahir <mezahir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 19:42:11 by mezahir           #+#    #+#             */
/*   Updated: 2025/12/25 00:07:16 by mezahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	ft_check_sorted(t_list *stack_A)
{
	t_list	*node;

	node = stack_A;
	while (node != NULL && node->next != NULL)
	{
		if ((node->value) > ((node->next)->value))
			return (0);
		node = node->next;
	}
	return (1);
}

void	ft_fill_stack(t_list **stack, char *argv[])
{
	int		i;
	t_list	*node;

	i = 0;
	while (argv[i])
	{
		node = ft_lst_new(ft_atoi(argv[i]));
		ft_add_back(stack, node);
		i++;
	}
	return ;
}

int	ft_valide_number(char *arg)
{
	int	i;

	i = 0;
	if (arg[i] == '-' || arg[i] == '+')
		i++;
	if (arg[i] == '\0')
		return (0);
	while (arg[i])
	{
		if (arg[i] >= '0' && arg[i] <= '9')
			i++;
		else
			return (0);
	}
	return (1);
}

int	helper(char **str)
{
	free(str);
	return (0);
}

int	ft_check_args(t_list **stack, char *argv[])
{
	int		i;
	char	**str;
	int		j;
	int		count;

	i = 0;
	while (argv[++i])
	{
		j = 0;
		str = ft_split(argv[i], ' ');
		count = ft_count_word(argv[i], ' ');
		if (str[j] == NULL)
			return (helper(str));
		while (str[j])
		{
			if (ft_valide_number(str[j]) == 0 || ft_atoi(str[j]) < INT_MIN
				|| ft_atoi(str[j]) > INT_MAX)
				return (ft_freee(str, count));
			j++;
		}
		ft_fill_stack(stack, str);
		ft_freee(str, count);
	}
	return (1);
}
