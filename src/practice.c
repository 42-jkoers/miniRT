/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   practice.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jkoers <jkoers@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/20 22:21:07 by jkoers        #+#    #+#                 */
/*   Updated: 2020/12/21 16:41:35 by jkoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/minilibx-linux/mlx.h"
#include "../lib/ft_printf/ft_printf.h"
#include "gui.h"
#include "helpers.h"

#include <stdlib.h>
#include <stdio.h>

void	fill_random(t_gui *gui)
{
	unsigned long	x;
	unsigned long	y;

	x = 0;
	while (x < gui->x_size)
	{
		y = 0;
		while (y < gui->y_size)
		{
			mlx_pixel_put(gui->mlx, gui->window, (int)x, (int)y, rand() | 0xFFFFFF);
			y++;
		}
		x++;
	}
}
