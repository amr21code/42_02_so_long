/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anruland <anruland@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 19:25:49 by anruland          #+#    #+#             */
/*   Updated: 2022/05/08 19:37:52 by anruland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	sl_free_images(t_data *data)
{
	int	i;

	i = 0;
	while (i < TEX)
	{
		if (data->images[i].img)
			mlx_destroy_image(data->mlx.mlx, data->images[i].img);
		data->images[i].img = NULL;
		i++;
	}
}

void	sl_free_map(t_data *data)
{
	int	i;

	i = 0;
	while (data->map.map[i])
	{
		free(data->map.map[i]);
		i++;
	}
	free(data->map.map);
}
