/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mezahir <mezahir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 13:45:08 by mezahir           #+#    #+#             */
/*   Updated: 2025/12/21 13:37:37 by mezahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap_bonus.h"

char	*ft_search(char *str, int c)
{
	int	i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i])
	{
		if (str[i] == (char)c)
			return (str + i);
		i++;
	}
	if ((char)c == '\0')
		return (str + i);
	return (NULL);
}

size_t	ft_strlen(char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strdup(char *str)
{
	size_t	len;
	char	*dup;
	size_t	i;

	if (!str)
		return (NULL);
	len = ft_strlen(str);
	dup = malloc(len + 1);
	if (!dup)
		return (NULL);
	i = 0;
	while (str[i])
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*ft_concat_str(char *str, char *buffer)
{
	int		i;
	size_t	len1;
	size_t	len2;
	char	*res;

	if (!str)
		return (ft_strdup(buffer));
	if (!buffer)
		return (NULL);
	len1 = ft_strlen(str);
	len2 = ft_strlen(buffer);
	res = malloc(len1 + len2 + 1);
	if (!res)
		return (NULL);
	ft_strcpy(res, str);
	i = 0;
	while (buffer[i])
	{
		res[len1 + i] = buffer[i];
		i++;
	}
	res[len2 + len1] = '\0';
	free(str);
	return (res);
}
