/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoklee <seoklee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 05:31:52 by lucku             #+#    #+#             */
/*   Updated: 2023/05/23 18:20:46 by seoklee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_set(char c, char *set)
{
	if (set == NULL)
		return (0);
	while (*set)
		if (c == *set++)
			return (1);
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*save;
	char	*str;
	int		len_s1;

	if (s1 == NULL)
		return (NULL);
	while (*s1 && is_set(*s1, (char *)set))
		s1++;
	len_s1 = ft_strlen(s1);
	save = (char *)(s1 + len_s1);
	while (is_set(*--save, (char *)set))
	{
		if (save < s1)
			break ;
		len_s1--;
	}
	str = (char *)malloc(sizeof(char) * (len_s1 + 1));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1, len_s1 + 1);
	return (str);
}
