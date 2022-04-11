/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anruland <anruland@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 18:13:14 by anruland          #+#    #+#             */
/*   Updated: 2022/04/11 19:29:14 by anruland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include "./libft/libft.h"
# include "./libftprintf/ft_printf.h"
# include "./gnl/get_next_line.h"
# include <fcntl.h>

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bpp;
	int		x;
	int		endian;
}	t_data;

typedef struct s_winvars
{
	void	*id;
	void	*win;
}	t_winvars;

void	*ft_realloc(void *addr, size_t size);

#endif
