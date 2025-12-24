/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mezahir <mezahir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 20:36:34 by mezahir           #+#    #+#             */
/*   Updated: 2025/12/24 20:38:40 by mezahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap_bonus.h"

int instruction(t_list **A,t_list **B,char *line)
{
     if(ft_strcmp(line , "sa\n"))
            sa(A);
    else if(ft_strcmp(line , "sb\n"))
            sb(B);
    else if(ft_strcmp(line , "ss\n"))
            ss(B,A);
    else if(ft_strcmp(line , "pa\n"))
            push_A(A,B);
    else if(ft_strcmp(line , "pb\n"))
            push_B(A,B);
    else if(ft_strcmp(line , "rb\n"))
            rb(B);
    else if(ft_strcmp(line , "ra\n"))
            ra(A);
    else if(ft_strcmp(line , "rr\n"))
            rr(A,B);
    else if(ft_strcmp(line , "rra\n"))
            rra(A);
    else if(ft_strcmp(line , "rrb\n"))
            rrb(B);
    else if(ft_strcmp(line , "rrr\n"))
            rrr(A,B);
    else
        return(0);
    return(1);
}
void ft_cheker(t_list **A,t_list **B)
{
    char *line ;
    while((line = get_next_line(0)) != NULL)
    {
    if(!instruction(A,B,line))
        {
            write(2,"Error\n",6);
            free(line);
            ft_free_lst(A);
            exit(1) ;
        }
        free(line);
    }
}

int main(int argc,char **argv)
{
    t_list *stack_A ;
    t_list *stack_B ;
    
    if(argc < 2)
        return (0);
    stack_A = NULL;
    stack_B = NULL;
    if(ft_check_args(&stack_A,argv) == 0 || ft_check_duplicate(stack_A) == 0)
    {
        write(2,"Error\n",6);
        ft_free_lst(&stack_A);
        exit (1);
    }
    ft_cheker(&stack_A,&stack_B);
    if(ft_check_sorted(stack_A) == 1 && !stack_B)
        write(1,"OK\n",3);
    else
         write(1,"KO\n",3);
    ft_free_lst(&stack_A);
    if(ft_size_lst(stack_B))
        ft_free_lst(&stack_B);
    return(0);
}


