/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoklee <seoklee@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 14:56:43 by seoklee           #+#    #+#             */
/*   Updated: 2020/12/26 18:25:03 by seoklee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*save;

	save = *lst;
	if (*lst == NULL)
		*lst = new;
	else
	{
		while (save->next)
			save = save->next;
		save->next = new;
	}
}
