/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mezahir <mezahir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 12:03:12 by mezahir           #+#    #+#             */
/*   Updated: 2025/12/16 15:12:22 by mezahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

unsigned int	ft_count_word(char const *s, char c)
{
	unsigned int	i;
	unsigned int	count;

	i = 0;
	count = 0;
	if (s == NULL)
		return (0);
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

static char	*ft_fill_word(unsigned int len_w, char *p, int i, char const *s)
{
	unsigned int	j;

	j = 0;
	while (len_w > 0)
	{
		p[j] = s[i - len_w];
		len_w--;
		j++;
	}
	p[j] = '\0';
	return (p);
}

char	**ft_free(char **p, unsigned int word)
{
	while (word > 0)
	{
		word--;
		free(p[word]);
	}
	free(p);
	return (NULL);
}

static char	**ft_div_word(char const *s, unsigned int count_w, char **p, char c)
{
	unsigned int	i;
	unsigned int	len_w;
	unsigned int	word;

	word = 0;
	i = 0;
	len_w = 0;
	while (word < count_w)
	{
		while (s[i] && s[i] == c)
			i++;
		while (s[i] && s[i] != c)
		{
			len_w++;
			i++;
		}
		p[word] = malloc(sizeof(char) * (len_w + 1));
		if (p[word] == NULL)
			return (ft_free(p, word));
		p[word] = ft_fill_word(len_w, p[word], i, s);
		len_w = 0;
		word++;
	}
	p[word] = NULL;
	return (p);
}

char	**ft_split(char const *s, char c)
{
	unsigned int	count_w;
	char			**p;

	if (!s)
		return (NULL);
	count_w = ft_count_word(s, c);
	p = malloc(sizeof(char *) * (count_w + 1));
	if (!p)
		return (NULL);
	p = ft_div_word(s, count_w, p, c);
	return (p);
}
