/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anruland <anruland@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 18:13:19 by anruland          #+#    #+#             */
/*   Updated: 2022/04/14 20:11:57 by anruland         ###   ########.fr       */
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

char	*sl_read_map(char *dir, char *map)
{
	int		fd;
	char	*tmp;
	int		line;
	int		size;

	size = 0;
	fd = open(dir, O_RDONLY);
	tmp = get_next_line(fd);
	line = ft_strlen(tmp);
	while (tmp)
	{
		if (!map)
		{
			map = tmp;
		}
		else
		{
			size = ft_strlen(map);
			map = ft_realloc(map, (size + line + 1));
			ft_strlcat(map, tmp, (size + line + 1));
		}
		tmp = get_next_line(fd);
	}
	close(fd);
	return (map);
}

int	ft_strlen_c(char *str, char c)
{
	int	str_count;

	str_count = 0;
	while (str[str_count] != c && str[str_count] != '\0')
	{
		str_count++;
	}
	return (str_count);
}

int	sl_check_walls(char *map, int cols, int rows)
{
	int	i;
	int	j;

	i = 0;
	while (i < rows)
	{
		j = 0;
		while (j < cols)
		{
			if (map[(i * (cols + 1)) + j] == '\n')
				j++;
			else if (i == 0 && map[(i * (cols + 1)) + j] != '1')
				return (0);
			else if (i > 0 && i < (rows - 1)
				&& (map[(i * (cols + 1))] != '1'
					|| map[(i * (cols + 1)) + cols - 1] != '1'))
				return (0);
			else if (i == (rows - 1) && (map[i * (cols + 1) + j] != '1' ))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	sl_check_map(char *map)
{
	int	line;
	int	i;

	if (!(ft_strchr(map, 'C') && ft_strchr(map, 'E') && ft_strchr(map, 'P')))
		return (0);
	line = ft_strlen_c(map, '\n');
	i = line;
	while (map[i])
	{
		if (i % (line + 1) == 0)
		{
			if (line != ft_strlen_c((map + i), '\n'))
				return (0);
		}
		i++;
	}
	if (!sl_check_walls(map, line, (i / line)))
	{
		ft_printf("Error: Map not surrounded by walls!\n");
		return (0);
	}
	return (1);
}

int	main(int ac, char **av)
{
	char	*map;

	if (ac != 2)
		return (0);
	map = sl_read_map(av[1], NULL);
	if (!sl_check_map(map))
		return (0);
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
