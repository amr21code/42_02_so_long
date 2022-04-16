/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anruland <anruland@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 18:13:19 by anruland          #+#    #+#             */
/*   Updated: 2022/04/16 19:58:02 by anruland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	sl_esc(int keycode, t_mlx *mlx)
{
	if (keycode == 0xff1b)
	{
		sl_exit_x(mlx);
	}
	return (0);
}

int	sl_exit_x(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx, mlx->win);
	exit(0);
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
	map->x = ft_strlen(tmp);
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

int	main(int ac, char **av)
{
	t_data		*data;

	sl_pre_error_check(ac, av);
	data = malloc(sizeof(*data));
	if (!data)
		return (ft_printerror("Error allocating data struct"));
	data->map.path = av[1];
	sl_read_map(&data->map);


	/* next */
	ft_printf("File correct");
	img2 = malloc(sizeof(t_data));
	map->pps = sl_min(map->x, map->y, 992);
	win.id = mlx_init();
	win.win = mlx_new_window(win.id, 1024, 768, "Test");
	// img.img = mlx_new_image(win.id, 992, 704);
	// img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.x, &img.endian);
	fd = open(path, O_RDONLY);
	ft_printf("test\n");
	img2->img = mlx_xpm_file_to_image(&win.id, path, &pos[0], &pos[1]);
	img2->addr = mlx_get_data_addr(img2->img, &img2->bpp, &img2->x, &img2->endian);
	close(fd);
	// sl_draw_square(&img, 992, 704, 0xFFFFFFFF);
	mlx_put_image_to_window(win.id, win.win, img2->img, 100, 100);
	// mlx_put_image_to_window(win.id, win.win, img.img, 16, 52);
	mlx_string_put(win.id, win.win, 30, 40, 0x00FFFFFF, "Test");
	mlx_key_hook(win.win, sl_esc, &win);
	mlx_hook(win.win, 17, 0, sl_exit_x, &win);
	mlx_loop(win.id);
	return (0);
}

	// sl_draw_square(&img, 160, 160, 0x99999999);
	// sl_draw_caro(&img, 600, 600);
	// sl_draw_square(&img2, 16, 16, 0xFFFFFFFF);