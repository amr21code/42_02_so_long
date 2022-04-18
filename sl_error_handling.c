/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_error_handling.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anruland <anruland@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 09:29:56 by anruland          #+#    #+#             */
/*   Updated: 2022/04/18 17:04:29 by anruland         ###   ########.fr       */
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

int	sl_check_items(t_map *map)
{
	int	i;
	int	items[3];

	i = 0;
	items[0] = 0;
	items[1] = 0;
	items[2] = 0;
	while (i < map->y)
	{
		if (ft_strchr(map->map[i], 'C'))
			items[0]++;
		if (ft_strchr(map->map[i], 'E'))
			items[1]++;
		if (ft_strchr(map->map[i], 'P'))
			items[2]++;
		i++;
	}
	if (items[0] > 0 && items[1] > 0 && items[2] > 0)
		return (1);
	else
		return (0);
}

int	sl_check_map(t_map *map)
{
	int	i;

	while (map->map[i])
	{
		if (map->x != (int)ft_strlen(map->map[i]))
			return (2);
		if (!sl_check_items(map))
			return (1);
		i++;
	}
	if (!sl_check_walls(map))
		return (3);
	return (0);
}

void	sl_error_msg(int errno)
{
	if (errno == 1)
		ft_printerror("Error: No collectible, exit or starting position!\n");
	else if (errno == 2)
		ft_printerror("Error: Map not rectangular!\n");
	else if (errno == 3)
		ft_printerror("Error: Map not surrounded by walls!\n");
	else if (errno > 0)
		ft_printerror("unknown error\n");
}

void	sl_pre_error_check(int ac, char **av)
{
	int	fd;

	if (ac != 2)
		ft_printerror("Usage: ./so_long map-path");
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		ft_printerror("File not found");
	if (!ft_strnstr(av[1], ".ber", ft_strlen(av[1])))
		ft_printerror("Not a .ber map");
}
