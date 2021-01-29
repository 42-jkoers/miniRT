/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   practice.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jkoers <jkoers@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/20 22:21:07 by jkoers        #+#    #+#                 */
/*   Updated: 2021/01/12 14:15:10 by jkoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/minilibx-linux/mlx.h"
#include "gui.h"
#include "parse_rt.h"

#include <stdlib.h>
#include <stdio.h>

void	fill_random(t_gui *gui)
{
	double	x;
	double	y;
	t_rgb			color;

	color.b = 64;
	y = 0;
	while (y < gui->y_size)
	{
		x = 0;
		while (x < gui->x_size)
		{
			color.r = 255.0 * ((double)x / (double)(gui->x_size - 1));
			color.g = 255.0 * ((double)y / (double)(gui->y_size - 1));
			gui_set_pixel(gui, x, y, color);
			x++;
		}
		y++;
	}
}
