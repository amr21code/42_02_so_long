/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anruland <anruland@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 18:13:19 by anruland          #+#    #+#             */
/*   Updated: 2022/04/10 20:09:34 by anruland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	sl_exit(int keycode, t_winvars *win)
{
	if (keycode == 0xff1b)
	{
		mlx_destroy_window(win->id, win->win);
		exit(0);
	}
	return (0);
}

int	main(int ac, char **av)
{
	if (ac != 2)
		return (0);
	

	// t_data		img;
	// t_winvars	win;

	// win.id = mlx_init();
	// win.win = mlx_new_window(win.id, 200, 200, "Test");
	// img.img = mlx_new_image(win.id, 200, 200);
	// img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.x, &img.endian);
	// sl_draw_square(&img, 200, 200, 0xFFFFFFFF);
	// sl_draw_caro(&img, 160, 160);
	// sl_draw_square(&img, 160, 160, 0x99999999);
	// mlx_put_image_to_window(win.id, win.win, img.img, 0, 0);
	// mlx_string_put(win.id, win.win, 30, 40, 0x000000FF, "Test");
	// mlx_key_hook(win.win, sl_exit, &win);
	// mlx_loop(win.id);
	return (0);
}
