/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoklee <seoklee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 21:09:31 by seoklee           #+#    #+#             */
/*   Updated: 2023/08/04 16:20:21 by seoklee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		get_color(t_color color)
{
	int res;

	res = color.r << 16;
	res += color.g << 8;
	res += color.b;
	return (res);
}

void	set_background(t_game *game)
{
	int	x;
	int	y;

	y = -1;
	while (++y < MAP_HEIGHT / 2)
	{
		x = -1;
		while (++x < MAP_WIDTH)
		{
				game->buf[y][x] = get_color(game->map.ceiling);
				game->buf[MAP_HEIGHT - y - 1][x] = get_color(game->map.floor);
		}
	}
}

void	draw_wall(t_game *game)
{
	int	x;
	int	y;

	y = -1;
	while (++y < MAP_HEIGHT)
	{
		x = -1;
		while (++x < MAP_WIDTH)
			game->data[y * MAP_WIDTH + x] = game->buf[y][x];
	}
	mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
}