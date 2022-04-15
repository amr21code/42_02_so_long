/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anruland <anruland@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 18:13:19 by anruland          #+#    #+#             */
/*   Updated: 2022/04/15 20:37:23 by anruland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	sl_esc(int keycode, t_winvars *win)
{
	if (keycode == 0xff1b)
	{
		mlx_destroy_window(win->id, win->win);
		exit(0);
	}
	return (0);
}

int	sl_exit_x(t_winvars *win)
{
	mlx_destroy_window(win->id, win->win);
	exit(0);
	return (0);
}

void	sl_read_map(char *dir, t_map **map)
{
	int		fd;
	char	*tmp;
	int		size;

	size = 0;
	fd = open(dir, O_RDONLY);
	tmp = get_next_line(fd);
	*map = (t_map *)malloc(sizeof(t_map));
	(*map)->map = NULL;
	(*map)->x = ft_strlen(tmp);
	while (tmp)
	{
		if (!(*map)->map)
			(*map)->map = tmp;
		else
		{
			size = ft_strlen((*map)->map);
			(*map)->map = ft_realloc((*map)->map, (size + (*map)->x + 1));
			ft_strlcat((*map)->map, tmp, (size + (*map)->x + 1));
		}
		tmp = get_next_line(fd);
	}
	close(fd);
	free(tmp);
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
	t_map		*map;
	// t_data		img;
	t_winvars	win;
	int			pos[2];
	t_data		*img2;
	char		*path = "./sprites/wall_1.xpm";
	int			fd;

	if (ac != 2 || !ft_strnstr(av[1], ".ber", ft_strlen(av[1])))
		return (0);
	sl_read_map(av[1], &map);
	if (sl_error_msg(sl_check_map(&map)))
		return (1);
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