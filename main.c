/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anruland <anruland@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 18:13:19 by anruland          #+#    #+#             */
/*   Updated: 2022/04/17 19:47:08 by anruland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	sl_exit_x(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx, mlx->win);
	exit(0);
	return (0);
}

int	sl_esc(int keycode, t_mlx *mlx)
{
	if (keycode == 0xff1b)
	{
		sl_exit_x(mlx);
	}
	return (0);
}

void	sl_read_map(t_map *map)
{
	int		fd;
	char	*tmp;
	int		i;

	i = 0;
	map->y = ft_linecount(map->path);
	map->map = ft_calloc(map->y + 1, sizeof(*map->map));
	if (!map->map)
		ft_printerror("Error allocating map data");
	fd = open(map->path, O_RDONLY);
	tmp = get_next_line(fd);
	map->x = ft_strlen_c(tmp, '\n');
	while (tmp)
	{
		map->map[i] = ft_strndup(tmp, ft_strlen_c(tmp, '\n'));
		if (!map->map[i])
			ft_printerror("Error allocating line");
		i++;
		free(tmp);
		tmp = get_next_line(fd);
	}
	close(fd);
	free(tmp);
	sl_error_msg(sl_check_map(map));
}

void	sl_init_tex_paths(t_data *data)
{
	data->images[wall].path = "./sprites/wall_1.xpm";
	data->images[floor].path = "./sprites/floor_2.xpm";
	data->images[collectible].path = "./sprites/collectible_potion_yellow.xpm";
	data->images[door].path = "./sprites/exit_door_anim_opening_f6.xpm";
	data->images[player].path = "./sprites/player_knight_idle_anim_f1.xpm";
}

int	sl_min(int x, int y, int img_size)
{
	int	minx;
	int	miny;

	minx = img_size / x;
	miny = img_size / y;
	if (minx < miny)
		return (minx);
	else
		return (miny);
}

void	sl_init_sprite(void *mlx, t_image *image)
{
	image->img = mlx_xpm_file_to_image(mlx, image->path,
			&image->size_x, &image->size_y);
	image->data = mlx_get_data_addr(image->img, &image->bpp,
			&image->line_size, &image->endian);
}

void	sl_load_tex(t_data *data)
{
	int	i;
	int	fd;

	i = 0;
	while (i < TEX)
	{
		fd = open(data->images[i].path, O_RDONLY);
		sl_init_sprite(data->mlx.mlx, &data->images[i]);
		if (!data->images[i].img)
			ft_printerror("Error creating sprite");
		i++;
		close(fd);
	}
}

int	main(int ac, char **av)
{
	t_data		*data;

	sl_pre_error_check(ac, av);
	data = malloc(sizeof(*data));
	if (!data)
		return (ft_printerror("Error allocating data struct"));
	data->map.path = av[1];
	sl_read_map(&data->map);
	ft_printf("File correct\n");
	data->mlx.mlx = mlx_init();
	if (data->mlx.mlx == NULL)
		ft_printerror("Error initializing MiniLibX");
	sl_init_tex_paths(data);
	ft_printf("Paths init\n");
	sl_load_tex(data);
	data->mlx.width = data->map.x * data->images[0].size_x;
	data->mlx.height = data->map.y * data->images[0].size_y;
	ft_printf("Tex Loaded\n");
	data->mlx.win = mlx_new_window(data->mlx.mlx, data->mlx.width,
			data->mlx.height, "So Long...");
	ft_printf("Win Init\n");
	mlx_put_image_to_window(data->mlx.mlx, data->mlx.win, data->images[0].img, 0, 0);
/* next draw map */

	mlx_key_hook(data->mlx.win, sl_esc, &data->mlx);
	mlx_hook(data->mlx.win, 17, 0, sl_exit_x, &data->mlx);
	mlx_loop(data->mlx.mlx);
	return (0);
}

	// sl_draw_square(&img, 160, 160, 0x99999999);
	// sl_draw_caro(&img, 600, 600);
	// sl_draw_square(&img2, 16, 16, 0xFFFFFFFF);