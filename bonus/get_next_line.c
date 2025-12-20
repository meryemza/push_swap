/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mezahir <mezahir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 21:39:52 by mezahir           #+#    #+#             */
/*   Updated: 2025/12/03 22:41:43 by mezahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_until_newline(int fd, char *str)
{
	char	*buffer;
	int		count_rd;

	buffer = malloc((size_t)BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	count_rd = 1;
	while (!(ft_search(str, '\n')) && count_rd != 0)
	{
		count_rd = read(fd, buffer, BUFFER_SIZE);
		if (count_rd < 0)
		{
			free(buffer);
			free(str);
			return (NULL);
		}
		buffer[count_rd] = '\0';
		str = ft_concat_str(str, buffer);
	}
	free(buffer);
	return (str);
}

char	*ft_line(char *str)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	line = malloc(i + 1);
	if (!line)
		return (NULL);
	j = 0;
	i = 0;
	while (str[i] && str[i] != '\n')
		line[j++] = str[i++];
	if (str[i] == '\n')
	{
		line[j] = '\n';
		j++;
	}
	line[j] = '\0';
	return (line);
}

char	*ft_rest(char *str)
{
	char	*rest;
	int		i;
	int		j;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\0')
	{
		free(str);
		return (NULL);
	}
	rest = malloc(ft_strlen(str) - i);
	if (!rest)
		return (NULL);
	j = 0;
	if (str[i] == '\n')
		i++;
	while (str[i])
		rest[j++] = str[i++];
	rest[j] = '\0';
	free(str);
	return (rest);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	str = read_until_newline(fd, str);
	if (!str)
		return (NULL);
	line = ft_line(str);
	str = ft_rest(str);
	return (line);
}
