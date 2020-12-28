/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jkoers <jkoers@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/20 16:39:11 by jkoers        #+#    #+#                 */
/*   Updated: 2020/12/28 17:46:22 by jkoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libft/include/libft.h"
#include "../lib/ft_printf/ft_printf.h"
#include "../lib/minilibx-linux/mlx.h"
#include "gui.h"
#include "shapes.h"
#include "practice.h"

#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int		main(void)
{
	t_gui *gui;

	gui = gui_init("rt/standard.rt");
	fill_random(gui);
	gui_write_canvas(gui);
	mlx_loop(gui->mlx);
	// sleep(10);
	return (0);
}
