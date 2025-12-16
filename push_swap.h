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
}   t_list;

long double  ft_atoi(const char *str);
int ft_check_duplicate(t_list *stack);
int ft_valide_number(char *arg);
void ft_fill_stack(t_list **stack,char *argv[]);
char	**ft_free(char **p, unsigned int word);
unsigned int	ft_count_word(char const *s, char c);
char	**ft_split(char const *s, char c);
int ft_check_args(t_list **stack,char *argv[]);
int ft_check_sorted(t_list *stack_A);


int ft_size_lst(t_list *str);
void ft_free_lst(t_list *lst);
t_list *ft_last_lst(t_list **stack);
void ft_add_back(t_list **stack,t_list *node);
t_list *ft_lst_new(int value);

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
