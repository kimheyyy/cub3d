/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoklee <seoklee@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 19:35:04 by seoklee           #+#    #+#             */
/*   Updated: 2020/12/26 18:26:12 by seoklee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*dst_save;
	const char	*src_save;

	if (dst == src || len == 0)
		return (dst);
	if (dst > src)
	{
		dst_save = (char *)dst + len - 1;
		src_save = (const char *)src + len - 1;
		while (len--)
		{
			*dst_save-- = *src_save--;
		}
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
