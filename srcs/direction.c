/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direction.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoklee <seoklee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 16:00:29 by seoklee           #+#    #+#             */
/*   Updated: 2023/08/11 12:37:53 by seoklee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	set_north(t_player *player, double x, double y)
{
	player->pos_x = x + 0.5;
	player->pos_y = y + 0.5;
	player->dir_x = 0;
	player->dir_y = -1.01;
	player->plane_x = 0.66;
	player->plane_y = 0;
}

static void	set_south(t_player *player, double x, double y)
{
	player->pos_x = x + 0.5;
	player->pos_y = y + 0.5;
	player->dir_x = 0;
	player->dir_y = 1.01;
	player->plane_x = -0.66;
	player->plane_y = 0;
}

static void	set_west(t_player *player, double x, double y)
{
	player->pos_x = x + 0.5;
	player->pos_y = y + 0.5;
	player->dir_x = -1.01;
	player->dir_y = 0;
	player->plane_x = 0;
	player->plane_y = -0.66;
}

static void	set_east(t_player *player, double x, double y)
{
	player->pos_x = x + 0.5;
	player->pos_y = y + 0.5;
	player->dir_x = 1.01;
	player->dir_y = 0;
	player->plane_x = 0;
	player->plane_y = 0.66;
}

void	set_direction(t_player *player, double x, double y, char dir)
{
	static int	count = 0;

	++count;
	if (count != 1)
		exit_err("Invalid map file");
	if (dir == 'N')
		set_north(player, x, y);
	else if (dir == 'S')
		set_south(player, x, y);
	else if (dir == 'W')
		set_west(player, x, y);
	else if (dir == 'E')
		set_east(player, x, y);
}
