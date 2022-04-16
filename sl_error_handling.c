/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_error_handling.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anruland <anruland@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 09:29:56 by anruland          #+#    #+#             */
/*   Updated: 2022/04/16 19:57:47 by anruland         ###   ########.fr       */
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

int	sl_check_map(t_map *map)
{
	int	line;
	int	i;

	while (map->map[i])
	{
		if (map->x != ft_strlen(map->map[i]))
			return (2);
		if (!(ft_strchr(map->map[i], 'C') && ft_strchr(map->map[i], 'E')
				&& ft_strchr(map->map[i], 'P')))
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
		ft_printerror("unknown error (%d)", errno);
}

void	sl_pre_error_check(int ac, char **av)
{
	int	fd;

	if (ac != 2)
		return (ft_printerror("Usage: ./so_long map-path"));
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		return (ft_printerror("File not found"));
	if (!ft_strnstr(av[1], ".ber", ft_strlen(av[1])))
		return (ft_printerror("Not a .ber map"));
	return (0);
}
