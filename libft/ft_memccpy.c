/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoklee <seoklee@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 18:54:04 by seoklee           #+#    #+#             */
/*   Updated: 2020/12/26 18:35:28 by seoklee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char		*dst_save;
	const char	*src_save;

	dst_save = (char *)dst;
	src_save = (const char *)src;
	while (n--)
	{
		*dst_save++ = *src_save++;
		if (*(unsigned char *)(src_save - 1) == (unsigned char)c)
			return (dst_save);
	}
	return (NULL);
}
