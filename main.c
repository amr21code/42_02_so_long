/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anruland <anruland@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 18:13:19 by anruland          #+#    #+#             */
/*   Updated: 2022/04/11 20:02:20 by anruland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	sl_exit(int keycode, t_winvars *win)
{
	if (keycode == 0xff1b)
	{
		mlx_destroy_window(win->id, win->win);
		exit(0);
	}
	return (0);
}

char	*sl_read_map(char *dir)
{
	int		fd;
	char	*tmp;
	char	*map;
	int		line;
	int		size;
	int		strlcat;

	size = 0;
	strlcat = 0;
	fd = open(dir, O_RDONLY);
	tmp = get_next_line(fd);
	line = ft_strlen(tmp);
	while (tmp)
	{
		if (!map)
			map = tmp;
		else
		{
			size = ft_strlen(map);
			map = ft_realloc(map, (size + line + 1));
			strlcat = ft_strlcat(map, tmp, line);
			ft_printf("%d\n", strlcat);
		}
		tmp = get_next_line(fd);
		if (line != (int)ft_strlen(tmp))
		{
			ft_printf("Error\n Wrong file Format");
			exit(0);
		}
	}
	close(fd);
	return (map);
}

int	main(int ac, char **av)
{
	if (ac != 2)
		return (0);
	sl_read_map(av[1]);
	ft_printf("File correct");

	// t_data		img;
	// t_winvars	win;

	// win.id = mlx_init();
	// win.win = mlx_new_window(win.id, 200, 200, "Test");
	// img.img = mlx_new_image(win.id, 200, 200);
	// img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.x, &img.endian);
	// sl_draw_square(&img, 200, 200, 0xFFFFFFFF);
	// sl_draw_caro(&img, 160, 160);
	// sl_draw_square(&img, 160, 160, 0x99999999);
	// mlx_put_image_to_window(win.id, win.win, img.img, 0, 0);
	// mlx_string_put(win.id, win.win, 30, 40, 0x000000FF, "Test");
	// mlx_key_hook(win.win, sl_exit, &win);
	// mlx_loop(win.id);
	return (0);
}
