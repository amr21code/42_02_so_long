/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_input_handling.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anruland <anruland@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 17:12:55 by anruland          #+#    #+#             */
/*   Updated: 2022/04/19 18:20:51 by anruland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	sl_check_move(t_data *data, int x, int y)
{
	if (data->map.map[data->player.y][data->player.x] == 'E'
		&& data->collectibles == data->player.collected)
	{
		ft_printf("You won the game! Congrats!\n");
		sl_exit_x(&data);
	}
	if (data->map.map[data->player.y + y][data->player.x + x] != '1')
		return (1);
	return (0);
}

void	sl_move(t_data *data, int x, int y)
{
	int	prev_x;
	int	prev_y;

	if (sl_check_move(data, x, y))
	{
		ft_printf("%d moves\n", data->moves);
		prev_x = data->player.x;
		prev_y = data->player.y;
		data->player.x += x;
		data->player.y += y;
		sl_update_map(data, prev_x, prev_y);
		sl_update_text(data);
		data->moves++;
	}
}

int	sl_input(int keycode, t_data **data)
{
	if (keycode == KEY_ESCAPE)
		sl_exit_x(data);
	else if (keycode == KEY_W)
		sl_move(*data, 0, -1);
	else if (keycode == KEY_A)
		sl_move(*data, -1, 0);
	else if (keycode == KEY_S)
		sl_move(*data, 0, 1);
	else if (keycode == KEY_D)
		sl_move(*data, 1, 0);
	return (0);
}
