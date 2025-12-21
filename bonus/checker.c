/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mezahir <mezahir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 20:36:34 by mezahir           #+#    #+#             */
/*   Updated: 2025/12/22 00:03:43 by mezahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap_bonus.h"

int instruction(t_list **A,t_list **B,char *line)
{
     if(ft_strcmp(line , "sa"))
            sa(A);
    else if(ft_strcmp(line , "sb"))
            sb(B);
    else if(ft_strcmp(line , "ss"))
            ss(B,A);
    else if(ft_strcmp(line , "pa"))
            push_A(A,B);
    else if(ft_strcmp(line , "pb"))
            push_B(A,B);
    else if(ft_strcmp(line , "rb"))
            rb(B);
    else if(ft_strcmp(line , "ra"))
            ra(A);
    else if(ft_strcmp(line , "rr"))
            rr(A,B);
    else if(ft_strcmp(line , "rra"))
            rra(A);
    else if(ft_strcmp(line , "rrb"))
            rrb(B);
    else if(ft_strcmp(line , "rrr"))
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
     line[ft_strlen(line) - 1] = '\0';
    if(!instruction(A,B,line))
    {
            write(1,"ERROR\n",6);
            return ;
        }
    free(line);
    }
    if(ft_check_sorted(*A) == 1)
        write(1,"OK\n",3);
    else
         write(1,"KO\n",3);
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
        write(2,"ERROR\n",6);
        ft_free_lst(&stack_A);
        return (0);
    }
    ft_fill_stack(&stack_A , argv);
    if(ft_check_sorted(stack_A) == 1)
        {
            ft_free_lst(&stack_A);
            return (0);
        }
    ft_cheker(&stack_A,&stack_B);
    ft_free_lst(&stack_A);
    if(ft_size_lst(stack_B))
        ft_free_lst(&stack_B);
    return(0);
}

