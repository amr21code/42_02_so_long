/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_error_handling.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anruland <anruland@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 09:29:56 by anruland          #+#    #+#             */
/*   Updated: 2022/04/15 12:05:15 by anruland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

int	sl_check_walls(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->y)
	{
		j = 0;
		while (j < map->x - 1)
		{
			if (map->map[(i * (map->x + 1)) + j] == '\n')
				j++;
			else if (i == 0 && map->map[(i * (map->x + 1)) + j] != '1')
				return (0);
			else if (i > 0 && i < (map->y - 1)
				&& (map->map[(i * (map->x))] != '1'
					|| map->map[(i * (map->x)) + map->x - 2] != '1'))
				return (0);
			else if (i == (map->y - 1)
				&& (map->map[i * (map->x) + j] != '1' ))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	sl_check_map(t_map **map)
{
	int	line;
	int	i;

	if (!(ft_strchr((*map)->map, 'C') && ft_strchr((*map)->map, 'E')
			&& ft_strchr((*map)->map, 'P')))
	{
		return (1);
	}
	line = ft_strlen_c((*map)->map, '\n');
	i = line;
	while ((*map)->map[i])
	{
		if (i % (line + 1) == 0)
		{
			if (line != ft_strlen_c(((*map)->map + i), '\n'))
			{
				return (2);
			}
		}
		i++;
	}
	(*map)->y = (i / line);
	if (!sl_check_walls(*map))
		return (3);
	return (0);
}

int	sl_error_msg(int errno)
{
	if (errno == 1)
		ft_printf("Error: collectible, exit or starting position missing!\n");
	else if (errno == 2)
		ft_printf("Error: Map not rectangular!\n");
	else if (errno == 3)
		ft_printf("Error: Map not surrounded by walls!\n");
	else if (errno > 0)
		ft_printf("unknown error (%d)", errno);
	if (errno > 0)
		return (1);
	return (0);
}
