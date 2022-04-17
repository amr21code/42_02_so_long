/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anruland <anruland@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 18:13:14 by anruland          #+#    #+#             */
/*   Updated: 2022/04/17 19:19:23 by anruland         ###   ########.fr       */
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
# include "./libftprintf/ft_printf.h"
# include "./gnl/get_next_line.h"
# include <fcntl.h>

# define TEX 5

enum e_tex {
	wall = 0,
	floor = 1,
	collectible = 2,
	door = 3,
	player = 4,
	enemy = 5
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
	t_mlx	mlx;
	t_map	map;
	t_image	images[TEX];
}	t_data;

void	*ft_realloc(void *addr, size_t size);
int		ft_printerror(char *errormsg);
int		ft_linecount(char *dir);
char	*ft_strndup(char *src, int len);

/* sl_draw.c */
// void	sl_draw_px(t_data *img, int x, int y, int color);
// void	sl_draw_square(t_data *img, int width, int height, int color);
// int		sl_convert_trgb(int t, int r, int g, int b);
// void	sl_draw_caro(t_data *img, int width, int height);

/* sl_error_handling.c */
int		ft_strlen_c(char *str, char c);
int		sl_check_walls(t_map *map);
int		sl_check_map(t_map *map);
void		sl_error_msg(int errno);
void	sl_pre_error_check(int ac, char **av);

#endif
