/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A_to_B.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mezahir <mezahir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 12:04:08 by mezahir           #+#    #+#             */
/*   Updated: 2025/12/18 14:56:33 by mezahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_choix_div(int size)
{
    int div;
    
    if(size <= 10)
        div = 5;
    else if(size <= 100)
        div = 6;
    else 
        div = 13;
    return (div);
}

void push_A_TO_B(t_list **stack_A,t_list **stack_B,int *array,t_range range)
{
    int size;

    size =  ft_size_lst(*stack_B);
    while((*stack_A) && size <= (range.end - range.start))
    {
        if((*stack_A) -> value >= array[range.start] && (*stack_A) -> value <= array[range.end] )
        {
            push_B(stack_A,stack_B);
            size++;
            if( size > 1 && (*stack_A) -> value < array[range.mid])
                rb(stack_B);
        }
        else
            ra(stack_A);
    }  
}

void push_to_B(t_list **stack_A,t_list **stack_B,int *array,int size)
{
    t_range range;
    int div;
    
    div = ft_choix_div(size);
    range.mid = (size / 2) - 1;
    range.offset = size / div;
    range.end = range.mid + range.offset;
    range.start = range.mid - range.offset;
    while(*stack_A)
    {
        push_A_TO_B(stack_A,stack_B,array,range);
        range.start = range.start - range.offset;
        if(range.start < 0)
            range.start = 0;
        range.end = range.end + range.offset;
        if(range.end >= size)
            range.end = size - 1;
    }
}
