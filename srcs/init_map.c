/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoklee <seoklee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 16:51:19 by seoklee           #+#    #+#             */
/*   Updated: 2023/08/08 16:21:59 by seoklee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	set_map_element(t_map *map, char *line)
{
	char	**strs;

	strs = ft_split(line, ' ');
	if (!strs || !strs[0] || !strs[1] || strs[2])
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

static void	init_map_element(t_map *map, int fd)
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

static void	set_map_content(t_map *map, t_list *head)
{
	int	i;

	map->map = ft_malloc(ft_lstsize(head) + 1, sizeof(char *));
	i = 0;
	while (head)
	{
		map->map[i++] = ft_strdup(head->content);
		free(head->content);
		head = head->next;
	}
	map->map[i] = NULL;
}

static void	init_map_content(t_map *map, int fd)
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
	game->player.pos_x = -1;
	init_map_element(&(game->map), fd);
	init_map_content(&(game->map), fd);
	validate_map(&(game->player), game->map.map);
	close(fd);
}
