/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_error_msg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anruland <anruland@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 19:24:16 by anruland          #+#    #+#             */
/*   Updated: 2022/05/10 20:15:08 by anruland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	sl_error_msg(int errno, t_data *data)
{
	if (errno == 1)
		ft_printf("Error\nIncorrect amount of components!\n");
	else if (errno == 2)
		ft_printf("Error\nMap not rectangular!\n");
	else if (errno == 3)
		ft_printf("Error\nMap not surrounded by walls!\n");
	else if (errno == 4)
		ft_printf("Error\nInvalid map elements!\n");
	else if (errno > 0)
		ft_printf("Error\nunspecified\n");
	if (errno > 0)
		sl_exit_map(data);
}

void	sl_pre_error_check(int ac, char **av)
{
	int	fd;

	if (ac != 2)
		ft_printerror("Error\nInvalid Arguments - Usage: ./so_long map-path");
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		ft_printerror("Error\nFile not found");
	if (!ft_strnstr(av[1], ".ber", ft_strlen(av[1])))
		ft_printerror("Error\nNot a .ber map");
}
