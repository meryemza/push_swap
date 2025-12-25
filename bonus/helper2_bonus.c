/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper2_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mezahir <mezahir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 23:52:47 by mezahir           #+#    #+#             */
/*   Updated: 2025/12/25 00:03:08 by mezahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

long double	ft_atoi(const char *str)
{
	int			i;
	int			s;
	long double	n;

	i = 0;
	s = 1;
	n = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		s = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = n * 10 + (str[i] - '0');
		i++;
	}
	return (n * s);
}

int	ft_freee(char **str, int count)
{
	while (count > 0)
	{
		count--;
		free(str[count]);
	}
	free(str);
	return (0);
}

int	ft_strcmp(char *str1, char *str2)
{
	int	i;

	i = 0;
	while (str1[i] && str2[i])
	{
		if (str1[i] != str2[i])
			return (0);
		else
			i++;
	}
	if (str1[i] == '\0' && str2[i] == '\0')
		return (1);
	else
		return (0);
}

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
