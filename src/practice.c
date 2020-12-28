/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   practice.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jkoers <jkoers@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/20 22:21:07 by jkoers        #+#    #+#                 */
/*   Updated: 2020/12/28 17:46:22 by jkoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/minilibx-linux/mlx.h"
#include "../lib/ft_printf/ft_printf.h"
#include "gui.h"
#include "shapes.h"

#include <stdlib.h>
#include <stdio.h>

void	fill_random(t_gui *gui)
{
	unsigned long	x;
	unsigned long	y;
	int				color;

	x = 0;
	while (x < gui->x_size)
	{
		y = 0;
		color = rand() & 0xFFFFFF;
		while (y < gui->y_size)
		{
			gui_set_pixel(gui, x, y, color);
			y++;
		}
		x++;
	}
}
