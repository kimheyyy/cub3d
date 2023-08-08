/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoklee <seoklee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 15:42:02 by seoklee           #+#    #+#             */
/*   Updated: 2023/08/08 16:24:36 by seoklee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	check_value(char c)
{
	if (c != '1' && c != '0' && c != 'N' && \
		c != 'S' && c != 'W' && c != 'E' && c != ' ')
		exit_err("Invalid map file");
}

static char	check_player(char c)
{
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (1);
	return (0);
}

static void	check_border(char **map, int len_y)
{
	int	i;
	int	j;

	i = -1;
	while (++i < len_y)
	{
		j = -1;
		while (++j < (int)ft_strlen(map[i]))
		{
			check_value(map[i][j]);
			if (map[i][j] != '1' && map[i][j] != ' ')
				if ((i == 0 || i == len_y - 1) || \
					(j == 0 || j == (int)ft_strlen(map[i]) - 1))
					exit_err("Invalid map file");
		}
	}
}

void	validate_map(t_player *player, char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[++i + 1])
	{
		j = 0;
		while (map[i][++j + 1])
		{
			if (check_player(map[i][j]))
				set_direction(player, (double)j, (double)i, map[i][j]);
			if ((map[i][j] == '0' || check_player(map[i][j])) && \
				(map[i - 1][j] == ' ' || map[i + 1][j] == ' ' || \
				map[i][j - 1] == ' ' || map[i][j + 1] == ' '))
				exit_err("Invalid map file");
		}
	}
	check_border(map, i + 1);
	if (player->pos_x == -1)
		exit_err("Invalid map file");
}
