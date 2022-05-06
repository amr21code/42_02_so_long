/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anruland <anruland@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 18:13:14 by anruland          #+#    #+#             */
/*   Updated: 2022/05/06 07:45:37 by anruland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include "./libft/libft.h"

# define TEX 6

enum e_tex
{
	wall = 0,
	floor = 1,
	collectible = 2,
	stair = 3,
	player = 4,
	blank = 5
};

// Linux
// enum e_keys
// {
// 	KEY_A = 97,
// 	KEY_S = 115,
// 	KEY_D = 100,
// 	KEY_W = 119,
// 	KEY_ESCAPE = 65307
// };

// Mac
enum e_keys
{
	KEY_A = 0,
	KEY_S = 1,
	KEY_D = 2,
	KEY_W = 13,
	KEY_ESCAPE = 53
};

typedef struct s_image
{
	void	*img;
	char	*data;
	char	*path;
	int		bpp;
	int		line_size;
	int		endian;
	int		size_x;
	int		size_y;
}	t_image;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	int		width;
	int		height;
}	t_mlx;

typedef struct s_player
{
	int	collected;
	int	x;
	int	y;
}	t_player;

typedef struct s_map
{
	char	**map;
	int		x;
	int		y;
	int		pps;
	char	*path;
}	t_map;

typedef struct s_data
{
	t_mlx		mlx;
	t_map		map;
	t_image		images[TEX];
	int			moves;
	int			collectibles;
	t_player	player;
}	t_data;

/* sl_draw.c */
void	sl_draw_tile(t_data *data, int i, int j);
void	sl_draw_map(t_data *data);

/* sl_error_handling.c */
int		sl_check_walls(t_map *map);
int		sl_check_items(t_map *map);
int		sl_check_map(t_map *map);
void	sl_error_msg(int errno);
void	sl_pre_error_check(int ac, char **av);

/* sl_parse_map.c */
void	sl_read_map(t_map *map);

/* sl_init.c */
void	sl_init_win(t_data *data);
void	sl_init_sprite(void *mlx, t_image *image);
void	sl_load_tex(t_data *data);
void	sl_init_tex_paths(t_data *data);

/* sl_input_handling.c */
int		sl_check_move(t_data *data, int x, int y);
void	sl_move(t_data *data, int x, int y);
int		sl_input(int keycode, t_data **data);

/* main.c */
int		sl_exit_x(t_data **data);
void	sl_update_map(t_data *data, int x, int y);
void	sl_update_text(t_data *data);

#endif
