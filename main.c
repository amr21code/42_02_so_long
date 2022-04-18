/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anruland <anruland@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 18:13:19 by anruland          #+#    #+#             */
/*   Updated: 2022/04/18 17:27:28 by anruland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	sl_exit_x(t_data *data)
{
	int	i;

	i = 0;
	while (i < TEX)
	{
		free(data->images[i].data);
		free(data->images[i].img);
		i++;
	}
	i = 0;
	while (data->map.map[i])
	{
		free(data->map.map[i]);
		i++;
	}
	mlx_destroy_window(data->mlx.mlx, data->mlx.win);
	free(data->mlx.mlx);
	exit(0);
	return (0);
}

void	sl_update_map(t_data *data, int x, int y)
{
	mlx_put_image_to_window(data->mlx.mlx, data->mlx.win,
		data->images[floor].img, data->images->size_x * x,
		data->images->size_y * y);
	mlx_put_image_to_window(data->mlx.mlx, data->mlx.win,
		data->images[player].img, data->images->size_x * data->player.x,
		data->images->size_y * data->player.y);
	if (data->map.map[y][x] == 'E')
		mlx_put_image_to_window(data->mlx.mlx, data->mlx.win,
			data->images[stair].img, data->images->size_x * data->player.x,
			data->images->size_y * data->player.y);
	if (data->map.map[y][x] == 'C')
	{
		data->player.collected++;
		data->map.map[y][x] = '0';
	}
	else if (data->map.map[y][x] == 'E'
		&& data->collectibles == data->player.collected)
	{
		ft_printf("You won the game! Congrats!\n");
		sl_exit_x(data);
	}
}

void	sl_update_text(t_data *data)
{
	char	status[100];

	status[0] = '\0';
	strcat(status, "Moves: ");
	strcat(status, ft_itoa(data->moves));
	strcat(status, " Collectibles: ");
	strcat(status, ft_itoa(data->player.collected));
	strcat(status, " / ");
	strcat(status, ft_itoa(data->collectibles));
	mlx_put_image_to_window(data->mlx.mlx, data->mlx.win,
		data->images[blank].img, 0,
		data->mlx.height - 50);
	mlx_string_put(data->mlx.mlx, data->mlx.win, 10,
		data->mlx.height - 25, 0xFFFFFFFF, status);
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
	data->mlx.mlx = mlx_init();
	if (data->mlx.mlx == NULL)
		ft_printerror("Error initializing MiniLibX");
	sl_init_tex_paths(data);
	sl_load_tex(data);
	sl_init_win(data);
	sl_draw_map(data);
	mlx_key_hook(data->mlx.win, sl_input, &data);
	mlx_hook(data->mlx.win, 17, 0, sl_exit_x, &data);
	mlx_loop(data->mlx.mlx);
	return (0);
}

/*
free 
- data
- map
*/