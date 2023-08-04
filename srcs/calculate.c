/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoklee <seoklee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 20:06:19 by seoklee           #+#    #+#             */
/*   Updated: 2023/08/04 20:28:11 by seoklee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_ray(t_ray *ray, t_game *game, t_player *player, int x)
{
	ray->cam_x = (2 * x / (double)MAP_WIDTH) - 1;
	ray->ray_x = game->player.dir_x + player->plane_x * ray->cam_x;
	ray->ray_y = game->player.dir_y + player->plane_y * ray->cam_x;
	ray->map_x = (int)(player->pos_x);
	ray->map_y = (int)(player->pos_y);
	ray->delta_x = fabs(1 / ray->ray_x);
	ray->delta_y = fabs(1 / ray->ray_y);
	ray->hit = 0;
	init_step(ray, player);
}

void	init_step(t_ray *ray, t_player *player)
{
	if (ray->ray_x < 0)
	{
		ray->step_x = -1;
		ray->side_x = (player->pos_x - ray->map_x) * ray->delta_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_x = (ray->map_x + 1.0 - player->pos_x) * ray->delta_x;
	}
	if (ray->ray_y < 0)
	{
		ray->step_y = -1;
		ray->side_y = (player->pos_y - ray->map_y) * ray->delta_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_y = (ray->map_y + 1.0 - player->pos_y) * ray->delta_y;
	}
}

void	check_hit(t_ray *ray, t_game *game)
{
	while (ray->hit == 0)
	{
		if (ray->side_x < ray->side_y)
		{
			ray->side_x += ray->delta_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_y += ray->delta_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (game->map.map[ray->map_x][ray->map_y] == '1')
			ray->hit = 1;
	}
}

void	set_perp_wall_dist(t_ray *ray, t_player *player)
{
	if (ray->side == 0)
		ray->perp_wall_dist = (ray->map_x - player->pos_x + (1 - ray->step_x) / 2) / ray->ray_x;
	else
		ray->perp_wall_dist = (ray->map_y - player->pos_y + (1 - ray->step_y) / 2) / ray->ray_y;
}

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
	if (ray->side == 0 && ray->ray_x > 0)
		ray->tex_x = 64 - ray->tex_x - 1;
	if (ray->side == 1 && ray->ray_y < 0)
		ray->tex_x = 64 - ray->tex_x - 1;
	if (ray->side == 0)
	{
		ray->tex_dir = NO;
		if (ray->ray_x > 0)
			ray->tex_dir = SO;
	}
	if (ray->side == 1)
	{
		ray->tex_dir = WE;
		if (ray->ray_y > 0)
			ray->tex_dir = EA;
	}
}

void	set_y_color(t_ray *ray, t_game *game, int x)
{
	int	y;

	ray->step = 64.0 / ray->line_height;
	ray->tex_pos = (ray->draw_start - MAP_HEIGHT / 2 + ray->line_height / 2) * ray->step;
	y = ray->draw_start;
	while (y < ray->draw_end)
	{
		ray->tex_y = (int)ray->tex_pos & 63;
		ray->tex_pos += ray->step;
		ray->color = game->walls[ray->tex_dir].addr[64 * ray->tex_y + ray->tex_x];
		if (ray->side == 1)
			ray->color = (ray->color >> 1) & 8355711;
		game->buf[y][x] = ray->color;
		++y;
	}
}

void	calculate(t_game *game)
{
	t_player	*player;
	t_ray		ray;
	int			x;

	player = &game->player;
	x = -1;
	while (++x < MAP_WIDTH)
	{
		init_ray(&ray, game, player, x);
		check_hit(&ray, game);
		set_perp_wall_dist(&ray, player);
		set_draw_start_end(&ray);
		set_texture(&ray, player);
		set_y_color(&ray, game, x);
	}
}
