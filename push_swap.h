/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mezahir <mezahir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 18:46:57 by mezahir           #+#    #+#             */
/*   Updated: 2025/12/22 20:05:32 by mezahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <unistd.h>

typedef struct s_list
{
    int             value;
    int             index;
    struct s_list   *next;
} t_list;

int ft_max(t_list *stack_A);
int ft_freee(char **str,int count);
unsigned int	ft_count_word(char const *s, char c);
long double  ft_atoi(const char *str);
int ft_check_duplicate(t_list *stack);
int ft_valide_number(char *arg);
void ft_fill_stack(t_list **stack,char *argv[]);
int	ft_free2(char **str);
char	**ft_split(char const *s, char c);
int ft_check_args(t_list **stack,char *argv[]);
int ft_check_sorted(t_list *stack_A);
void ft_sort(t_list **stack_A,t_list **stack_B,int size);
void sort_4(t_list **stack_A,t_list **stack_B);
void sort_5(t_list **stack_A,t_list **stack_B);
void sort_3(t_list **stack_A);
void push_to_B(t_list **stack_A,t_list **stack_B,int *array,int size);
void push_to_A(t_list **stack_A,t_list **stack_B,int *array,int size);
void ft_add_index(t_list **stack_B);

void big_sort(t_list **stack_A, t_list **stack_B);
void push_B_TO_A(t_list **A,t_list **B);

int ft_size_lst(t_list *str);
void ft_free_lst(t_list **lst);
t_list *ft_last_lst(t_list **stack);
void ft_add_back(t_list **stack,t_list *node);
t_list *ft_lst_new(int value);

void sort_A(t_list **stack_A,t_list **stack_B,int p);
int pos_first_min_index(t_list *stack,int n);
int    ft_search_max_pos(t_list *b, t_list **max_node);

void push_B_TO_A(t_list **A,t_list **B);
int get_pos_max(t_list *B, int max);
int ft_search_max(t_list *stack_B);

void ra(t_list **stack_A);
void rb(t_list **stack_B);
void rr(t_list **stack_A,t_list **stack_B);

void sa(t_list **stack_A);
void sb(t_list **stack_B);
void ss(t_list **stack_B,t_list **stack_A);

void rra(t_list **stack_A);
void rrb(t_list **stack_B);
void rrr(t_list **stack_A,t_list **stack_B);
void push_A(t_list **stack_A,t_list **stack_B);
void push_B(t_list **stack_A,t_list **stack_B);

#endif
