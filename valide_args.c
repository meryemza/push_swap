/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valide_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mezahir <mezahir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 11:06:53 by mezahir           #+#    #+#             */
/*   Updated: 2025/12/24 23:41:32 by mezahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_duplicate(t_list *stack)
{
	t_list	*head;
	t_list	*tmp;

	head = stack;
	while (head)
	{
		tmp = head;
		while (tmp->next != NULL)
		{
			if (head->value == tmp->next->value)
				return (0);
			tmp = tmp->next;
		}
		head = head->next;
	}
	return (1);
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

int	free2(char **str)
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
			return (free2(str));
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
