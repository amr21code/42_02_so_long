/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anruland <anruland@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 18:54:46 by anruland          #+#    #+#             */
/*   Updated: 2022/04/18 17:02:13 by anruland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	sl_draw_tile(t_data *data, int i, int j)
{
	if (data->map.map[i][j] == '1')
		mlx_put_image_to_window(data->mlx.mlx, data->mlx.win,
			data->images[wall].img, data->images->size_x * j,
			data->images->size_y * i);
	else if (data->map.map[i][j] == '0')
		mlx_put_image_to_window(data->mlx.mlx, data->mlx.win,
			data->images[floor].img, data->images->size_x * j,
			data->images->size_y * i);
	else if (data->map.map[i][j] == 'C')
		mlx_put_image_to_window(data->mlx.mlx, data->mlx.win,
			data->images[collectible].img, data->images->size_x * j,
			data->images->size_y * i);
	else if (data->map.map[i][j] == 'E')
		mlx_put_image_to_window(data->mlx.mlx, data->mlx.win,
			data->images[stair].img, data->images->size_x * j,
			data->images->size_y * i);
	else if (data->map.map[i][j] == 'P')
		mlx_put_image_to_window(data->mlx.mlx, data->mlx.win,
			data->images[player].img, data->images->size_x * j,
			data->images->size_y * i);
}

void	sl_draw_map(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	data->collectibles = 0;
	while (data->map.map[i])
	{
		j = 0;
		while (data->map.map[i][j])
		{
			sl_draw_tile(data, i, j);
			if (data->map.map[i][j] == 'C')
				data->collectibles++;
			else if (data->map.map[i][j] == 'P')
			{
				data->player.x = j;
				data->player.y = i;
			}
			j++;
		}
		i++;
	}
	data->moves = 0;
	data->player.collected = 0;
}
