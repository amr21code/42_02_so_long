/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anruland <anruland@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 13:48:32 by anruland          #+#    #+#             */
/*   Updated: 2022/05/10 13:52:33 by anruland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	sl_exit_x(t_data *data)
{
	sl_free_images(data);
	sl_free_map(data);
	mlx_destroy_window(data->mlx.mlx, data->mlx.win);
	mlx_destroy_display(data->mlx.mlx);
	if (data->mlx.mlx)
		free(data->mlx.mlx);
	data->mlx.mlx = NULL;
	exit(0);
	return (0);
}

int	sl_exit_map(t_data *data)
{
	sl_free_map(data);
	exit(1);
	return (1);
}
