/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoklee <seoklee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 14:42:06 by seoklee           #+#    #+#             */
/*   Updated: 2023/08/11 12:24:31 by seoklee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_left(t_map *map, t_player *player)
{
	int	x;
	int	y;

	x = (int)(player->pos_x + player->dir_y * MOVE_SPEED);
	y = (int)(player->pos_y);
	if (map->map[y][x] != '1')
		player->pos_x += player->dir_y * MOVE_SPEED;
	x = (int)(player->pos_x);
	y = (int)(player->pos_y - player->dir_x * MOVE_SPEED);
	if (map->map[y][x] != '1')
		player->pos_y -= player->dir_x * MOVE_SPEED;
}

void	move_right(t_map *map, t_player *player)
{
	int	x;
	int	y;

	x = (int)(player->pos_x - player->dir_y * MOVE_SPEED);
	y = (int)(player->pos_y);
	if (map->map[y][x] != '1')
		player->pos_x -= player->dir_y * MOVE_SPEED;
	x = (int)(player->pos_x);
	y = (int)(player->pos_y + player->dir_x * MOVE_SPEED);
	if (map->map[y][x] != '1')
		player->pos_y += player->dir_x * MOVE_SPEED;
}
