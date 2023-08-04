/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoklee <seoklee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 15:51:19 by seoklee           #+#    #+#             */
/*   Updated: 2023/08/04 20:51:12 by seoklee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	(void)m;
	// m->map = (char **)ft_malloc(5, sizeof(char *));
	// m->map[0] = ft_strdup("11111");
	// m->map[1] = ft_strdup("10001");
	// m->map[2] = ft_strdup("10N01");
	// m->map[3] = ft_strdup("10001");
	// m->map[4] = ft_strdup("11111");
	// m->wall_no = ft_strdup("./textures/beigerock.xpm");
	// m->wall_so = ft_strdup("./textures/mossystone.xpm");
	// m->wall_we = ft_strdup("./textures/greystone.xpm");
	// m->wall_ea = ft_strdup("./textures/wood.xpm");
	// m->floor.r = 110;
	// m->floor.g = 110;
	// m->floor.b = 110;
	// m->ceiling.r = 0;
	// m->ceiling.g = 0;
	// m->ceiling.b = 0;
	p->pos_x = 11.5;
	p->pos_y = 26.5;
	p->dir_x = 0;
	p->dir_y = 1;
	p->plane_x = 0.66;
	p->plane_y = 0;
}

void	set_rgb(t_color *color, char *rgb)
{
	char	**strs;

	strs = ft_split(rgb, ',');
	if (!strs || !strs[0] || !strs[1] || !strs[2])
		exit_err("Invalid map file");
	color->r = ft_atoi(strs[0]);
	color->g = ft_atoi(strs[1]);
	color->b = ft_atoi(strs[2]);
	if (color->r < 0 || color->r > 255 || \
		color->g < 0 || color->g > 255 || \
		color->b < 0 || color->b > 255)
		exit_err("Invalid map file");
	free_strs(strs);
}

void	set_map_element(t_map *map, char *line)
{
	char	**strs;

	strs = ft_split(line, ' ');
	if (!strs || !strs[0] || !strs[1])
		exit_err("Invalid map file");
	if (ft_strncmp(strs[0], "NO", 3) == 0 && !map->wall_no)
		map->wall_no = ft_strdup(strs[1]);
	else if (ft_strncmp(strs[0], "SO", 3) == 0 && !map->wall_so)
		map->wall_so = ft_strdup(strs[1]);
	else if (ft_strncmp(strs[0], "WE", 3) == 0 && !map->wall_we)
		map->wall_we = ft_strdup(strs[1]);
	else if (ft_strncmp(strs[0], "EA", 3) == 0 && !map->wall_ea)
		map->wall_ea = ft_strdup(strs[1]);
	else if (ft_strncmp(strs[0], "F", 2) == 0 && map->floor.r == -1)
		set_rgb(&(map->floor), strs[1]);
	else if (ft_strncmp(strs[0], "C", 2) == 0 && map->ceiling.r == -1)
		set_rgb(&(map->ceiling), strs[1]);
	else
		exit_err("Invalid map file");
	free_strs(strs);
}

void	init_map_element(t_map *map, int fd)
{
	char	*line;
	int		count;

	count = 0;
	while (count != 6)
	{
		line = get_next_line(fd);
		if (!line)
			exit_err("Invalid map file");
		if (!line[0])
		{
			free(line);
			continue ;
		}
		set_map_element(map, line);
		free(line);
		count++;
	}
}

void	set_map_content(t_map *map, t_list *head)
{
	int	i;

	map->map = ft_malloc(ft_lstsize(head) + 1, sizeof(char *));
	i = 0;
	while (head)
	{
		map->map[i++] = ft_strdup(head->content);
		head = head->next;
		printf("%s\n", map->map[i - 1]);
	}
	map->map[i] = NULL;
}

void	init_map_content(t_map *map, int fd)
{
	t_list	*head;
	char	*line;

	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			exit_err("Invalid map file");
		if (!line[0])
			free(line);
		else
			break ;
	}
	head = ft_lstnew(ft_strdup(line));
	while (line)
	{
		ft_lstadd_back(&head, ft_lstnew(ft_strdup(line)));
		free(line);
		line = get_next_line(fd);
	}
	set_map_content(map, head);
	ft_lstclear(&head, 0);
}

void	init_map(t_game *game, char *file_path)
{
	int	fd;

	fd = open(file_path, O_RDONLY);
	if (fd == -1)
		exit_err("Map file open fail");
	game->map.wall_no = NULL;
	game->map.wall_so = NULL;
	game->map.wall_we = NULL;
	game->map.wall_ea = NULL;
	game->map.floor.r = -1;
	game->map.ceiling.r = -1;
	init_map_element(&(game->map), fd);
	init_map_content(&(game->map), fd);
	close(fd);
}

void	init_game(t_game *game, char *file_path)
{
	if (ft_strncmp(file_path + ft_strlen(file_path) - 4, ".cub", 5) != 0)
		exit_err("Wrong extension");
	init_map(game, file_path);
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
