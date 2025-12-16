/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mezahir <mezahir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 11:07:25 by mezahir           #+#    #+#             */
/*   Updated: 2025/12/16 22:09:33 by mezahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list *ft_last_lst(t_list **stack)
{
    if(!*stack)
        return NULL;
    t_list *head;
    head = *stack;
    while(head -> next != NULL)
        head = head -> next;
    return head;
}

void ft_add_back(t_list **stack,t_list *node)
{   
    if(!stack || !node)
        return ;
    t_list *head;
    head = *stack;
    if(*stack)
    {
    while(head -> next != NULL)
        head = head -> next;
    head -> next = node;
    }
    else
        *stack = node;
    return ;
}

t_list *ft_lst_new(int value)
{
    t_list *node;
    node = malloc(sizeof(t_list));
    if(!node)
        return (NULL);
    node -> value = value;
    node -> next = NULL;
    return (node);
}
void ft_free_lst(t_list *lst)
{
    t_list *tmp;
   tmp = lst;
    while(tmp)
    {
        tmp = lst -> next;
        free(lst);
        lst = tmp;
    }
}

int ft_size_lst(t_list *str)
{
    t_list *tmp;
    tmp = str;
    int size;
    
    size = 0;
    while(tmp)
    {
       size++;
       tmp = tmp -> next;  
    }
    return (size);
}