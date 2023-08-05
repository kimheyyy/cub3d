/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoklee <seoklee@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 17:39:23 by seoklee           #+#    #+#             */
/*   Updated: 2020/12/26 18:26:08 by seoklee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*dst_save;
	const char	*src_save;

	if (dst == src || n == 0)
		return (dst);
	dst_save = (char *)dst;
	src_save = (const char *)src;
	while (n--)
		*dst_save++ = *src_save++;
	return (dst);
}
