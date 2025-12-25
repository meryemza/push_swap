/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mezahir <mezahir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 00:18:18 by mezahir           #+#    #+#             */
/*   Updated: 2025/12/25 00:19:22 by mezahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_last_lst(t_list **stack)
{
	t_list	*head;

	if (!*stack)
		return (NULL);
	head = *stack;
	while (head->next != NULL)
		head = head->next;
	return (head);
}

void	ft_add_back(t_list **stack, t_list *node)
{
	t_list	*head;

	if (!stack || !node)
		return ;
	head = *stack;
	if (*stack)
	{
		while (head->next != NULL)
			head = head->next;
		head->next = node;
	}
	else
		*stack = node;
	return ;
}

t_list	*ft_lst_new(int value)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->value = value;
	node->next = NULL;
	return (node);
}

void	ft_free_lst(t_list **lst)
{
	t_list	*tmp;

	while (*lst)
	{
		tmp = (*lst)->next;
		free(*lst);
		*lst = tmp;
	}
}

int	ft_size_lst(t_list *str)
{
	t_list	*tmp;
	int		size;

	tmp = str;
	size = 0;
	while (tmp)
	{
		size++;
		tmp = tmp->next;
	}
	return (size);
}
