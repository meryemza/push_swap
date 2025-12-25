/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mezahir <mezahir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 13:30:00 by mezahir           #+#    #+#             */
/*   Updated: 2025/12/25 00:08:45 by mezahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				value;
	int				index;
	struct s_list	*next;
}					t_list;

long double			ft_atoi(const char *str);
int					ft_check_duplicate(t_list *stack);
int					ft_valide_number(char *arg);
void				ft_fill_stack(t_list **stack, char *argv[]);
char				**ft_split(char const *s, char c);
int					ft_check_args(t_list **stack, char *argv[]);
int					ft_check_sorted(t_list *stack_A);
int					ft_free2(char **str);
int					ft_strcmp(char *str1, char *str2);
void				ft_cheker(t_list **A, t_list **B);
int					instruction(t_list **A, t_list **B, char *line);
int					ft_freee(char **str, int count);
unsigned int		ft_count_word(char const *s, char c);

int					ft_size_lst(t_list *str);
void				ft_free_lst(t_list **lst);
t_list				*ft_last_lst(t_list **stack);
void				ft_add_back(t_list **stack, t_list *node);
t_list				*ft_lst_new(int value);

char				*ft_search(char *str, int c);
size_t				ft_strlen(char *str);
char				*ft_strcpy(char *dest, char *src);
char				*ft_strdup(char *str);
char				*ft_concat_str(char *str, char *buffer);
char				*get_next_line(int fd);
char				*ft_rest(char *str);
char				*ft_line(char *str);
char				*read_until_newline(int fd, char *str);

void				ra(t_list **stack_A);
void				rb(t_list **stack_B);
void				rr(t_list **stack_A, t_list **stack_B);

void				sa(t_list **stack_A);
void				sb(t_list **stack_B);
void				ss(t_list **stack_B, t_list **stack_A);

void				rra(t_list **stack_A);
void				rrb(t_list **stack_B);
void				rrr(t_list **stack_A, t_list **stack_B);
void				push_a(t_list **stack_A, t_list **stack_B);
void				push_b(t_list **stack_A, t_list **stack_B);

#endif