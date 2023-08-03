/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoklee <seoklee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 17:32:46 by seoklee           #+#    #+#             */
/*   Updated: 2023/05/23 18:18:29 by seoklee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_strs(char *str, char c)
{
	int	i;
	int	count;

	i = 1;
	count = 0;
	if (*str == '\0')
		return (0);
	if (*str != c)
		count++;
	while (str[i])
	{
		if (str[i - 1] == c && str[i] != c)
			count++;
		i++;
	}
	return (count);
}

static int	count_strlen(char **str, char c)
{
	int	count;

	count = 0;
	while (**str)
	{
		if (**str != c)
			count++;
		else
		{
			(*str)++;
			return (count);
		}
		(*str)++;
	}
	return (count);
}

static char	**free_strs(char **strs, int i)
{
	while (i > 0)
		free(strs[--i]);
	free(strs);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		count;
	int		len;
	char	*save;
	char	**strs;

	if (s == NULL)
		return (NULL);
	i = -1;
	count = count_strs((char *)s, c);
	strs = (char **)ft_calloc(count + 1, sizeof(char *));
	if (!strs)
		return (NULL);
	while (++i < count)
	{
		while (*s == c)
			s++;
		save = (char *)s;
		len = count_strlen((char **)&s, c);
		strs[i] = (char *)malloc(sizeof(char) * (len + 1));
		if (!strs[i])
			return (free_strs(strs, i));
		ft_strlcpy(strs[i], save, len + 1);
	}
	return (strs);
}
