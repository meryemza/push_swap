/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mezahir <mezahir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 15:31:55 by mezahir           #+#    #+#             */
/*   Updated: 2025/12/20 18:51:22 by mezahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int *fill_array(t_list *stack_A , int *array , int size)
{
    int i;
    i = 0;
    while(stack_A && size > i)
    {
        array[i] = stack_A -> value;
        stack_A = stack_A -> next ;
        i++;
    }
    return (array);
}

void sort_array(int *array , int size)
{
    int i ;
    int j ;
    int tmp;
    i = 0;
    while(i < size)
    {   
    j = i + 1;
    while(j < size)
    {
        if(array[i] > array[j])
        {
            tmp = array[i];
            array[i] = array[j];
            array[j] = tmp;
        }
        j++;
    }
    i++;
    }    
}
void ft_index_A(t_list **stack_A, int *array, int size)
{
    int i;
    t_list *node;
    
    node = *stack_A;
    
    while(node)
    {
        i = 0;
        while(i < size)
        {
            if(node -> value == array[i])
            {
               node -> index = i; 
               break;
            }
            i++;
        }
        node = node -> next;
    }
}

void big_sort(t_list **stack_A, t_list **stack_B)
{
    int *array;
    int size;

    size = ft_size_lst(*stack_A);
    array = malloc(sizeof(int) * size);
    if(!array)
        return ;
    array = fill_array(*stack_A,array,size);
    sort_array(array,size);
    ft_index_A(stack_A,array,size);
    if(ft_size_lst(*stack_A) < 250)
        sort_A(stack_A,stack_B,15);
    else
        sort_A(stack_A,stack_B,40);
    free(array);
}