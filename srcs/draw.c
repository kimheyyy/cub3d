/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoklee <seoklee@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 21:09:31 by seoklee           #+#    #+#             */
/*   Updated: 2023/08/03 21:12:00 by seoklee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw(t_game *game)
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