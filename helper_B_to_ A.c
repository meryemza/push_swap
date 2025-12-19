/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_B_to_ A.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mezahir <mezahir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 21:45:06 by mezahir           #+#    #+#             */
/*   Updated: 2025/12/19 13:53:04 by mezahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_add_index(t_list **stack_B)
{
    int i;
    t_list *tmp;

    i = 0;
    tmp = *stack_B;
    while(tmp)
    {
        tmp -> index = i;
        tmp = tmp -> next;
        i++;
    }
}

int ft_max_index(t_list *stack_B,int max)
{
    int index;
    t_list *tmp;
    
    tmp = stack_B;
    while(tmp)
    {
        if(tmp -> value == max)
            return (tmp -> index);
        tmp = tmp -> next;
    }
    return(-1);
}
void ft_search_index(t_list **stack_B,int max)
{
        int size ;
        int index_max;
        
        ft_add_index(stack_B);
        size = ft_size_lst(*stack_B);
        index_max = ft_max_index(*stack_B ,max);
        if((*stack) && index_max <= size/2)
            rb(stack_B);
        else
            rrb(stack_B);
}

int	ft_search_max(t_list *stack_B, int max)
{
	while (stack_B)
	{
		if (stack_B->value == max)
			return (1);
		stack_B = stack_B->next;
	}
	return (0);
}