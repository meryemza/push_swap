/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   B_to_A.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mezahir <mezahir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 12:05:31 by mezahir           #+#    #+#             */
/*   Updated: 2025/12/19 15:59:49 by mezahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_max_to_a(t_list **stack_A, t_list **stack_B,int *array, int *size)
{
    if ((*stack_B)->value == array[(*size )-1])
        pa(stack_A, stack_B);
    else if(ft_last_lst(*stack_B)->value == array[(*size) -1])
    {
        rrb(stack_B);
        pa(stack_A, stack_B);
    }
    (*size)--;
    if ((*stack_A)->next && (*stack_A)->value > (*stack_A)->next->value)
    {
        sa(stack_A);
        (*size)--;
    }
}
void ft_push(t_list **stack_A, t_list **stack_B,int *count)
{
    push_A(stack_A,stack_B);
    ra(stack_A);
    (*count)++;
}

void ft_rra(t_list **stack_A,int *count,int *size)
{
    rra(stack_A);
    (*count)--;
    (*size)--;
}
void push_to_A(t_list **stack_A,t_list **stack_B,int *array,int size)
{
    int count_ra;
    
    count_ra = 0;
    while(*stack_B)
    {
       if (ft_search_max(*stack_B, array[size - 1]))
        {
            if ((*stack_B)->value == array[size - 1]||ft_last_lst(stack_B)->value == array[size - 1])
                push_max_to_a(stack_A, stack_B, array,&size);
            else if ((*stack_B)->value == array[size - 2])
				pa(stack_A, stack_B);
            else if ((count_ra == 0 || (*stack_B)->value > ft_last_lst(stack_A)->value) && (*stack_A))
                ft_push(stack_A, stack_B, &count_ra);
			else
                ft_search_index(stack_B, array[size - 1]);
        }
        else if(ft_search_max(*stack_A, array[size - 1]) && count_ra > 0 && ft_last_lst(stack_A) -> value == array[size - 1])
            ft_rra(stack_A,&count_ra,&size);
        }   
        while(count_ra > 0 && size > 0)
            ft_rra(stack_A,&count_ra,&size);
}
