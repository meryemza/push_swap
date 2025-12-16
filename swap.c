/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mezahir <mezahir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 11:08:45 by mezahir           #+#    #+#             */
/*   Updated: 2025/12/16 11:09:07 by mezahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void swap(t_list **stack)
{
    t_list *node1;
    t_list *node2;
    int swap;

    node1 = *stack;
    node2 = node1 -> next;
    if(!node1 || !node2)
        return;
    swap = node1 -> value;
    node1 -> value = node2 -> value;
    node2 -> value = swap;
}
void sa(t_list **stack_A)
{
    swap(stack_A);
    write(1,"sa\n",3);
}
void sb(t_list **stack_B)
{
    swap(stack_B);
    write(1,"sb\n",3);
}
void ss(t_list **stack_B,t_list **stack_A)
{
    swap(stack_B);
    swap(stack_A);
    write(1,"ss\n",3);
}