/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoklee <seoklee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 14:48:13 by seoklee           #+#    #+#             */
/*   Updated: 2023/08/04 20:31:07 by seoklee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include "../mlx/mlx.h"
# include "../gnl/get_next_line.h"
# include "../libft/libft.h"

# define MAP_WIDTH 1920
# define MAP_HEIGHT 1080
# define NO 0
# define SO 1
# define WE 2
# define EA 3
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_W 13
# define KEY_ESC 53
# define MOVE_SPEED 0.2
# define ROT_SPEED 0.2

typedef struct s_color {
	int	r;
	int	g;
	int	b;
}	t_color;

typedef struct s_img {
	void	*img;
	int		*addr;
	int		size_l;
	int		bpp;
	int		endian;
}	t_img;

typedef struct s_player {
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
}	t_player;

typedef struct s_map {
	char	**map;
	char	*wall_no;
	char	*wall_so;
	char	*wall_we;
	char	*wall_ea;
	t_color	floor;
	t_color	ceiling;
}	t_map;

typedef struct s_game {
	void		*mlx;
	void		*win;
	void		*img;
	int			**buf;
	int			*data;
	t_img		walls[4];
	t_map		map;
	t_player	player;
}	t_game;

typedef struct s_ray {
	double	cam_x;
	double	ray_x;
	double	ray_y;
	int		map_x;
	int		map_y;
	double	side_x;
	double	side_y;
	double	delta_x;
	double	delta_y;
	double	perp_wall_dist;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	int		line_height;
	int		draw_start;
	int		draw_end;
	double	wall_x;
	int		tex_x;
	int		tex_y;
	int		tex_dir;
	double	step;
	double	tex_pos;
	int		color;
}	t_ray;

//main
int		main_loop(t_game *game);

//init game
void	init_game(t_game *game, char *file_path);
void	init_map(t_game *game, char *file_path);
void	init_map_element(t_map *map, int fd);
void	init_map_content(t_map *map, int fd);
void	set_map_element(t_map *map, char *line);
void	set_rgb(t_color *color, char *rgb);
void	load_texture(t_game *game, t_img *wall, char *file_path);
void	init_buf(t_game *game);

//exit
void	exit_err(char *str);
int		exit_game(t_game *game);

//key hook
int		key_hook(int key, t_game *game);

//calculate
void	calculate(t_game *game);
void	init_ray(t_ray *ray, t_game *game, t_player *player, int x);
void	init_step(t_ray *ray, t_player *player);
void	check_hit(t_ray *ray, t_game *game);
void	set_perp_wall_dist(t_ray *ray, t_player *player);
void	set_draw_start_end(t_ray *ray);
void	set_texture(t_ray *ray, t_player *player);
void	set_y_color(t_ray *ray, t_game *game, int x);

//draw
void	set_background(t_game *game);
void	draw_wall(t_game *game);

//utils
void	*ft_malloc(size_t count, size_t size);
void	free_strs(char **strs);

#endif
