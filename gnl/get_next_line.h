/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoklee <seoklee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 11:28:16 by seoklee           #+#    #+#             */
/*   Updated: 2023/05/23 19:20:49 by seoklee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

char	*ft_tailjoin(char *s1, char *s2);
char	*ft_line(char *tail, int *n);
char	*ft_tail(char *tail, int *n);
char	*ft_read(char *tail, int fd);
char	*get_next_line(int fd);

#endif