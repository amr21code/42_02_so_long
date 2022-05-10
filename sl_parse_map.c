/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_parse_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anruland <anruland@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 17:05:55 by anruland          #+#    #+#             */
/*   Updated: 2022/05/10 13:53:24 by anruland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	sl_read_map(t_map *map)
{
	int		fd;
	char	*tmp;
	int		i;

	i = 0;
	map->y = ft_linecount(map->path);
	map->map = ft_calloc(map->y + 1, sizeof(*map->map));
	if (!map->map)
		ft_printerror("Error allocating map data");
	fd = open(map->path, O_RDONLY);
	tmp = get_next_line(fd);
	map->x = ft_strlen_c(tmp, '\n');
	while (tmp)
	{
		map->map[i] = ft_strndup(tmp, ft_strlen_c(tmp, '\n'));
		if (!map->map[i])
			ft_printerror("Error allocating line");
		i++;
		free(tmp);
		tmp = get_next_line(fd);
	}
	close(fd);
	free(tmp);
}
