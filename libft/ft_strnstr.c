/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoklee <seoklee@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 20:01:11 by seoklee           #+#    #+#             */
/*   Updated: 2020/12/26 18:27:24 by seoklee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *find, size_t len)
{
	size_t	len_find;

	if (!(*find))
		return ((char *)str);
	len_find = ft_strlen(find);
	while (*str && len-- >= len_find)
	{
		if (!ft_strncmp(str, find, len_find))
			return ((char *)str);
		str++;
	}
	return (NULL);
}
