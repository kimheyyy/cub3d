/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoklee <seoklee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 14:48:01 by seoklee           #+#    #+#             */
/*   Updated: 2023/08/05 16:55:28 by seoklee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	main_loop(t_game *game)
{
	set_background(game);
	calculate(game);
	draw_wall(game);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;
	int		size_l;
	int		bpp;
	int		endian;

	if (argc != 2)
		exit_err("Invalid arguments");
	init_game(&game, argv[1]);
	game.img = mlx_new_image(game.mlx, MAP_WIDTH, MAP_HEIGHT);
	game.data = (int *)mlx_get_data_addr(game.img, &bpp, &size_l, &endian);
	mlx_hook(game.win, 17, 0, &exit_game, &game);
	mlx_hook(game.win, 2, 0, &key_hook, &game);
	mlx_loop_hook(game.mlx, &main_loop, &game);
	mlx_loop(game.mlx);
	return (0);
}
