/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoklee <seoklee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 21:59:51 by seoklee           #+#    #+#             */
/*   Updated: 2023/05/23 18:11:08 by seoklee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	unsigned long long	result;
	int					sign;

	result = 0;
	sign = 1;
	while (*str && (*str == ' ' || *str == '\t' || *str == '\n'
			|| *str == '\r' || *str == '\f' || *str == '\v'))
		str++;
	if (*str && (*str == '-' || *str == '+'))
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str && *str >= '0' && *str <= '9' && result <= MIN_ULL)
	{
		result = result * 10 + *str - '0';
		str++;
	}
	if (result > MAX_ULL && sign == 1)
		return (-1);
	else if (result > MIN_ULL && sign == -1)
		return (0);
	return ((long long)result * sign);
}
