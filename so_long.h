/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anruland <anruland@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 18:13:14 by anruland          #+#    #+#             */
/*   Updated: 2022/04/15 17:43:31 by anruland         ###   ########.fr       */
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

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bpp;
	int		x;
	int		endian;
	int		size_x;
	int		size_y;
}	t_data;

typedef struct s_winvars
{
	void	*id;
	void	*win;
}	t_winvars;

typedef struct s_map
{
	char	*map;
	int		x;
	int		y;
	int		pps;
}	t_map;

void	*ft_realloc(void *addr, size_t size);

/* sl_draw.c */
void	sl_draw_px(t_data *img, int x, int y, int color);
void	sl_draw_square(t_data *img, int width, int height, int color);
int		sl_convert_trgb(int t, int r, int g, int b);
void	sl_draw_caro(t_data *img, int width, int height);

/* sl_error_handling.c */
int		ft_strlen_c(char *str, char c);
int		sl_check_walls(t_map *map);
int		sl_check_map(t_map **map);
int		sl_error_msg(int errno);

#endif
