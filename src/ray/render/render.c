/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jkoers <jkoers@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/11 01:20:24 by jkoers        #+#    #+#                 */
/*   Updated: 2021/03/11 01:20:24 by jkoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "constants.h"
#if BONUS == 0
#include "gui.h"
#include "ray.h"
#include <stdio.h>
#include <math.h>

static void	log_progress(unsigned int i, const t_gui *gui)
{
	static unsigned int	skip = 0;

	if (i + 1 == gui->y_size)
	{
		printf("\rProgress %7.3lf%%  \n", 100.0);
		return ;
	}
	if (skip != 0)
	{
		skip--;
		return ;
	}
	skip = (unsigned int)round(gui->y_size * 0.001);
	printf("\rProgress %7.3lf%%  ", ((double)(i + 1) / gui->y_size) * 100.0);
}


void	render(t_gui *gui)
{
	unsigned int	x;
	unsigned int	y;

	y = 0;
	while (y < gui->y_size)
	{
		x = 0;
		while (x < gui->x_size)
		{
			gui_set_pixel(gui, x, y, compute_color(x, y, gui));
			x++;
		}
		if (LOG_PROGRESS)
			log_progress(y, gui);
		y++;
	}
}

#endif
