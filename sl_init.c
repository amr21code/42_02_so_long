/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anruland <anruland@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 17:07:48 by anruland          #+#    #+#             */
/*   Updated: 2022/04/27 22:56:05 by anruland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	sl_init_win(t_data *data)
{
	data->mlx.width = data->map.x * data->images[0].size_x;
	if (data->mlx.width < 300)
		data->mlx.width = 300;
	data->mlx.height = data->map.y * data->images[0].size_y + 50;
	data->mlx.win = mlx_new_window(data->mlx.mlx, data->mlx.width,
			data->mlx.height, "So Long...");
}

void	sl_init_sprite(void *mlx, t_image *image)
{
	image->img = mlx_xpm_file_to_image(mlx, image->path,
			&image->size_x, &image->size_y);
	// image->data = mlx_get_data_addr(image->img, &image->bpp,
	// 		&image->line_size, &image->endian);
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

void	sl_init_tex_paths(t_data *data)
{
	data->images[wall].path = "./sprites/wall_1.xpm";
	data->images[floor].path = "./sprites/floor_2.xpm";
	data->images[collectible].path = "./sprites/collectible_potion_yellow.xpm";
	data->images[stair].path = "./sprites/stair_nextlevel.xpm";
	data->images[player].path = "./sprites/player_knight_idle_anim_f1.xpm";
	data->images[blank].path = "./sprites/blank.xpm";
}
