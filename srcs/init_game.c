/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoklee <seoklee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 15:51:19 by seoklee           #+#    #+#             */
/*   Updated: 2023/08/04 17:37:04 by seoklee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// void	init_map(t_map *map, t_player *player, char *file_path)
// {
// }

void	init_buf(t_game *game)
{
	int	x;
	int	y;

	game->buf = (int **)ft_malloc(MAP_HEIGHT, sizeof(int *));
	y = -1;
	while (++y < MAP_HEIGHT)
		game->buf[y] = (int *)ft_malloc(MAP_WIDTH, sizeof(int));
	y = -1;
	while (++y < MAP_HEIGHT)
	{
		x = -1;
		while (++x < MAP_WIDTH)
			game->buf[y][x] = 0;
	}
}

void	load_texture(t_game *game, t_img *wall, char *file_path)
{
	int	width;
	int	height;

	wall->img = mlx_xpm_file_to_image(game->mlx, file_path, &width, &height);
	if (wall->img == NULL)
		exit_err("Texture file open fail");
	wall->addr = (int *)mlx_get_data_addr(wall->img, &(wall->bpp), &(wall->size_l), &(wall->endian));
}

void	test(t_map *m, t_player *p)
{
	m->map = (char **)ft_malloc(5, sizeof(char *));
	m->map[0] = ft_strdup("11111");
	m->map[1] = ft_strdup("10001");
	m->map[2] = ft_strdup("10N01");
	m->map[3] = ft_strdup("10001");
	m->map[4] = ft_strdup("11111");
	m->wall_no = ft_strdup("./textures/beigerock.xpm");
	m->wall_so = ft_strdup("./textures/mossystone.xpm");
	m->wall_we = ft_strdup("./textures/greystone.xpm");
	m->wall_ea = ft_strdup("./textures/wood.xpm");
	m->floor.r = 110;
	m->floor.g = 110;
	m->floor.b = 110;
	m->ceiling.r = 0;
	m->ceiling.g = 0;
	m->ceiling.b = 0;
	p->pos_x = 2.5;
	p->pos_y = 2.5;
	p->dir_x = 0;
	p->dir_y = 1;
	p->plane_x = 0.66;
	p->plane_y = 0;
}

void	init_game(char *file_path, t_game *game)
{
	if (ft_strncmp(file_path + ft_strlen(file_path) - 4, ".cub", 5) != 0)
		exit_err("Wrong extension");
	// init_map(&(game->map), &(game->player), file_path);
	test(&(game->map), &(game->player));
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, MAP_WIDTH, MAP_HEIGHT, "cub3D");
	load_texture(game, &(game->walls[NO]), game->map.wall_no);
	load_texture(game, &(game->walls[SO]), game->map.wall_so);
	load_texture(game, &(game->walls[WE]), game->map.wall_we);
	load_texture(game, &(game->walls[EA]), game->map.wall_ea);
	// validate_map(game);
	init_buf(game);
}