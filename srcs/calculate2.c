/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoklee <seoklee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 16:46:24 by seoklee           #+#    #+#             */
/*   Updated: 2023/08/05 16:49:14 by seoklee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_draw_start_end(t_ray *ray)
{
	ray->line_height = (int)(MAP_HEIGHT / ray->perp_wall_dist);
	ray->draw_start = -ray->line_height / 2 + MAP_HEIGHT / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + MAP_HEIGHT / 2;
	if (ray->draw_end >= MAP_HEIGHT)
		ray->draw_end = MAP_HEIGHT - 1;
}

void	set_texture(t_ray *ray, t_player *player)
{
	if (ray->side == 0)
		ray->wall_x = player->pos_y + ray->perp_wall_dist * ray->ray_y;
	else
		ray->wall_x = player->pos_x + ray->perp_wall_dist * ray->ray_x;
	ray->wall_x -= floor(ray->wall_x);
	ray->tex_x = (int)(ray->wall_x * 64.0);
	if (ray->side == 0 && ray->ray_x < 0)
		ray->tex_x = 64 - ray->tex_x - 1;
	if (ray->side == 1 && ray->ray_y > 0)
		ray->tex_x = 64 - ray->tex_x - 1;
	if (ray->side == 0)
	{
		ray->tex_dir = EA;
		if (ray->ray_x < 0)
			ray->tex_dir = WE;
	}
	if (ray->side == 1)
	{
		ray->tex_dir = SO;
		if (ray->ray_y < 0)
			ray->tex_dir = NO;
	}
}

void	set_y_color(t_ray *ray, t_game *game, int x)
{
	int	y;

	ray->step = 64.0 / ray->line_height;
	ray->tex_pos = (ray->draw_start - MAP_HEIGHT / \
				2 + ray->line_height / 2) * ray->step;
	y = ray->draw_start;
	while (y < ray->draw_end)
	{
		ray->tex_y = (int)ray->tex_pos & 63;
		ray->tex_pos += ray->step;
		ray->color = game->walls[ray->tex_dir].\
					addr[64 * ray->tex_y + ray->tex_x];
		if (ray->side == 0)
			ray->color = (ray->color >> 1) & 8355711;
		game->buf[y][x] = ray->color;
		++y;
	}
}
