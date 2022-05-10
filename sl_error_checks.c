/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_error_checks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anruland <anruland@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 09:29:56 by anruland          #+#    #+#             */
/*   Updated: 2022/05/10 20:27:32 by anruland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	sl_check_walls(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->y)
	{
		j = 0;
		while (j < map->x)
		{
			if (i == 0 && map->map[i][j] != '1')
				return (0);
			else if (i > 0 && i < map->y
				&& (map->map[i][0] != '1'
				|| map->map[i][map->x - 1] != '1'))
				return (0);
			else if (i == (map->y - 1)
				&& (map->map[i][j] != '1' ))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	sl_convert_item_to_int(char c)
{
	if (c == 'C')
		return (0);
	else if (c == 'E')
		return (1);
	else if (c == 'P')
		return (2);
	else
		return (4);
}

int	sl_check_items(t_map *map)
{
	int		i;
	int		j;
	int		items[4];

	i = 0;
	j = 0;
	items[0] = 0;
	items[1] = 0;
	items[2] = 0;
	items[3] = 0;
	while (i < map->y)
	{
		j = 0;
		while (map->map[i][j])
		{
			items[sl_convert_item_to_int(map->map[i][j])]++;
			j++;
		}
		i++;
	}
	if (items[0] > 0 && items[1] > 0 && items[2] == 1)
		return (1);
	else
		return (0);
}

int	sl_check_valid_elem(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->y)
	{
		j = 0;
		while (map->map[i][j])
		{
			if (!ft_strchr("CEP10", map->map[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	sl_check_map(t_data *data)
{
	int	i;

	i = 0;
	while (data->map.map[i])
	{
		if (data->map.x != (int)ft_strlen(data->map.map[i]))
			return (2);
		i++;
	}
	if (!sl_check_items(&data->map))
		return (1);
	if (!sl_check_valid_elem(&data->map))
		return (4);
	if (!sl_check_walls(&data->map))
		return (3);
	return (0);
}
