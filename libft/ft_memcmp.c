/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoklee <seoklee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 17:16:51 by seoklee           #+#    #+#             */
/*   Updated: 2023/05/23 18:16:44 by seoklee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*s1_save;
	const unsigned char	*s2_save;

	if (s1 == s2 || n == 0)
		return (0);
	s1_save = (const unsigned char *)s1;
	s2_save = (const unsigned char *)s2;
	while (n && *s1_save == *s2_save)
	{
		s1_save++;
		s2_save++;
		n--;
	}
	if (!n)
		return (0);
	return (*s1_save - *s2_save);
}
