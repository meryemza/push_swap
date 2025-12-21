/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mezahir <mezahir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 19:42:11 by mezahir           #+#    #+#             */
/*   Updated: 2025/12/21 23:51:14 by mezahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int ft_check_sorted(t_list *stack_A)
{
   t_list *node;
   node = stack_A;
   
   while(node != NULL && node -> next != NULL)
   {
    if((node -> value) > ((node -> next )-> value))
        return (0);
    node = node -> next;
   }
   return (1);
}

int ft_strcmp(char *str1, char *str2)
{
    int i;
    
    i = 0;
    while(str1[i] && str2[i])
    {
        if(str1[i] != str2[i])
            return (0);
        else
            i++;
    }
    if(str1[i] ==  '\0' && str2[i] == '\0')
        return (1);
    else
        return(0);
   
}

void ft_fill_stack(t_list **stack,char *argv[])
{
    int i;
    i = 0;
    t_list *node;
    while(argv[i])
    {
        node = ft_lst_new(ft_atoi(argv[i]));
        ft_add_back(stack,node);
        i++;
    }
    return;
}
int ft_check_duplicate(t_list *stack)
{
    t_list *head;
    t_list *tmp;

    head = stack;
    while(head)
    {
        tmp = head;
        while(tmp -> next != NULL)
        {
            if(head-> value == tmp -> next -> value)
                return 0;
            tmp = tmp -> next;
        }
        head = head -> next;
    }
    return 1;
}

int ft_valide_number(char *arg)
{
    int i ;

    i = 0;
    if(arg[i] == '-' || arg[i] == '+' )
        i++;
    if(arg[i] == '\0')
        return 0;
    while(arg[i])
    {
        if(arg[i]>= '0' && arg[i] <= '9')
            i++;
        else
            return 0;
    }
    return 1;
}

int ft_check_args(t_list **stack,char *argv[])
{   
    int i ;
    char **str;
    int j;
    int count;
    
    i = 0;
    while(argv[++i])
    {
        j = 0;
       str = ft_split(argv[i],' ');
       count = ft_count_word(argv[i],' ');
     if (str[j] == NULL)
    {
        free(str);
        return 0;
    }
       while(str[j])
       {
            if(ft_valide_number(str[j]) == 0 || ft_atoi(str[j]) < INT_MIN || ft_atoi(str[j]) > INT_MAX )
               return (ft_freee(str,count));
            j++;
       }
            ft_fill_stack(stack,str);
            ft_freee(str,count);
       i++;
    }
    return 1;
}




long double  ft_atoi(const char *str)
{
	int				i;
	int				s;
	long double n;

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

int	ft_free2(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (0);
}

int ft_freee(char **str,int count)
{
	while (count > 0)
	{
		count--;
		free(str[count]);
	}
	free(str);
	return (0);
}