/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoklee <seoklee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 15:53:26 by seoklee           #+#    #+#             */
/*   Updated: 2023/08/04 20:28:03 by seoklee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	exit_err(char *str)
{
	printf("Error\n%s\n", str);
	exit(1);
}

int	exit_game(t_game *game)
{
	printf("GAME OVER\n");
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
	return (0);
}
