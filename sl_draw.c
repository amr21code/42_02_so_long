/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anruland <anruland@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 18:54:46 by anruland          #+#    #+#             */
/*   Updated: 2022/04/15 12:15:27 by anruland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	sl_draw_px(t_data *img, int x, int y, int color)
{
	int		offset;
	char	*px;

	offset = y * img->x + x * (img->bpp / 8);
	px = img->addr + offset;
	*(unsigned int *)px = color;
}

void	sl_draw_square(t_data *img, int width, int height, int color)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < height)
	{
		while (j < width)
		{
			sl_draw_px(img, j, i, color);
			j++;
		}
		j = 0;
		i++;
	}
}

int	sl_convert_trgb(int t, int r, int g, int b)
{
	int	color;

	color = 0;
	color = color | t << 24;
	color = color | r << 16;
	color = color | g << 8;
	color = color | b;
	return (color);
}

void	sl_draw_caro(t_data *img, int width, int height)
{
	int		i;
	int		j;

	i = 0;
	j = width / 2;
	while (i < height)
	{
		if (i <= height / 2)
		{
			while (j < (width / 2 + i) && j)
			{
				sl_draw_px(img, j + 20, i + 20, sl_convert_trgb(0, 0, j + 40, i + 40));
				j++;
			}
			j = width / 2 - i;
		}
		else
		{
			while (j < (width - (i - height / 2)) && j)
			{
				sl_draw_px(img, j + 20, i + 20, sl_convert_trgb(0, 0, j + 40, i + 40));
				j++;
			}
			j = 0 + i - height / 2;
		}
		i++;
	}
}
