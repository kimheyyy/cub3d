/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoklee <seoklee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 18:49:26 by seoklee           #+#    #+#             */
/*   Updated: 2023/08/08 14:47:53 by seoklee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	move_forward(t_map *map, t_player *player)
{
	int	x;
	int	y;

	x = (int)(player->pos_x + player->dir_x * MOVE_SPEED);
	y = (int)(player->pos_y);
	if (map->map[y][x] != '1')
		player->pos_x += player->dir_x * MOVE_SPEED;
	x = (int)(player->pos_x);
	y = (int)(player->pos_y + player->dir_y * MOVE_SPEED);
	if (map->map[y][x] != '1')
		player->pos_y += player->dir_y * MOVE_SPEED;
}

static void	move_back(t_map *map, t_player *player)
{
	int	x;
	int	y;

	x = (int)(player->pos_x - player->dir_x * MOVE_SPEED);
	y = (int)(player->pos_y);
	if (map->map[y][x] != '1')
		player->pos_x -= player->dir_x * MOVE_SPEED;
	x = (int)(player->pos_x);
	y = (int)(player->pos_y - player->dir_y * MOVE_SPEED);
	if (map->map[y][x] != '1')
		player->pos_y -= player->dir_y * MOVE_SPEED;
}

static void	turn_left(t_player *player)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = player->dir_x;
	old_plane_x = player->plane_x;
	player->dir_x = old_dir_x * cos(-ROT_SPEED) - \
					player->dir_y * sin(-ROT_SPEED);
	player->dir_y = old_dir_x * sin(-ROT_SPEED) + \
					player->dir_y * cos(-ROT_SPEED);
	player->plane_x = old_plane_x * cos(-ROT_SPEED) - \
					player->plane_y * sin(-ROT_SPEED);
	player->plane_y = old_plane_x * sin(-ROT_SPEED) + \
					player->plane_y * cos(-ROT_SPEED);
}

static void	turn_right(t_player *player)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = player->dir_x;
	old_plane_x = player->plane_x;
	player->dir_x = old_dir_x * cos(ROT_SPEED) - player->dir_y * sin(ROT_SPEED);
	player->dir_y = old_dir_x * sin(ROT_SPEED) + player->dir_y * cos(ROT_SPEED);
	player->plane_x = old_plane_x * cos(ROT_SPEED) - \
					player->plane_y * sin(ROT_SPEED);
	player->plane_y = old_plane_x * sin(ROT_SPEED) + \
					player->plane_y * cos(ROT_SPEED);
}

int	key_hook(int key, t_game *game)
{
	if (key == KEY_W)
		move_forward(&(game->map), &(game->player));
	else if (key == KEY_S)
		move_back(&(game->map), &(game->player));
	else if (key == KEY_A)
		move_left(&(game->map), &(game->player));
	else if (key == KEY_D)
		move_right(&(game->map), &(game->player));
	else if (key == KEY_LEFT)
		turn_left(&(game->player));
	else if (key == KEY_RIGHT)
		turn_right(&(game->player));
	else if (key == KEY_ESC)
		exit_game(game);
	return (0);
}
