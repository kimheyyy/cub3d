/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoklee <seoklee@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 15:51:19 by seoklee           #+#    #+#             */
/*   Updated: 2023/08/03 22:38:13 by seoklee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// void	init_map(t_map *map, t_game *game, char *filePath)
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

void	init_game(char *file_path, t_game *game)
{
	if (ft_strncmp(file_path + ft_strlen(file_path) - 4, ".cub", 5) != 0)
		exit_err("Wrong extension");
	// init_map(&(game->map), game, argv);
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, MAP_WIDTH, MAP_HEIGHT, "cub3D");
	load_texture(game, &(game->walls[NO]), game->map.wall_no);
	load_texture(game, &(game->walls[SO]), game->map.wall_so);
	load_texture(game, &(game->walls[WE]), game->map.wall_we);
	load_texture(game, &(game->walls[EA]), game->map.wall_ea);
	// validate_map(game);
	init_buf(game);
}