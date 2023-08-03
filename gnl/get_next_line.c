/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoklee <seoklee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 11:27:41 by seoklee           #+#    #+#             */
/*   Updated: 2023/05/24 17:51:01 by seoklee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_tailjoin(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * (i + j + 1));
	if (str == NULL)
		return (NULL);
	i = -1;
	while (s1[++i])
		str[i] = s1[i];
	j = -1;
	while (s2[++j])
		str[i + j] = s2[j];
	str[i + j] = '\0';
	free(s1);
	return (str);
}

char	*ft_line(char *tail, int *n)
{
	char	*line;
	int		i;

	i = 0;
	while (tail[i] && tail[i] != '\n')
		i++;
	line = ft_substr(tail, 0, i);
	*n = i + 1;
	return (line);
}

char	*ft_tail(char *tail, int *n)
{
	char	*str;

	str = tail;
	tail = ft_substr(str, *n, ft_strlen(tail) - *n);
	free(str);
	return (tail);
}

char	*ft_read(char *tail, int fd)
{
	char	buf[BUFFER_SIZE + 1];
	int		count;

	count = 1;
	while (count > 0 && ft_strchr(tail, '\n') == NULL)
	{
		count = read(fd, buf, BUFFER_SIZE);
		if (count < 0)
			return (NULL);
		buf[count] = '\0';
		if (tail)
			tail = ft_tailjoin(tail, buf);
		else
			tail = ft_substr(buf, 0, count);
	}
	return (tail);
}

char	*get_next_line(int fd)
{
	static char	*tail = 0;
	char		*line;
	int			n;

	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, 0, 0) < 0)
		return (NULL);
	tail = ft_read(tail, fd);
	if (!tail[0])
	{
		free(tail);
		return (NULL);
	}
	n = 0;
	line = ft_line(tail, &n);
	tail = ft_tail(tail, &n);
	return (line);
}
