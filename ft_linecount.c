/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_linecount.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anruland <anruland@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 19:09:45 by anruland          #+#    #+#             */
/*   Updated: 2022/04/16 19:15:53 by anruland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_linecount(char *dir)
{
	int		lines;
	char	*line;
	int		fd;

	lines = 0;
	fd = open(dir, O_RDONLY);
	if (fd < 0)
		return (ft_printerror("Error opening file"));
	line = get_next_line(fd);
	while (line)
	{
		lines++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (lines);
}
