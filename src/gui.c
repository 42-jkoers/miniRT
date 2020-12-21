/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   gui.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: jkoers <jkoers@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/20 18:50:36 by jkoers        #+#    #+#                 */
/*   Updated: 2020/12/21 16:45:47 by jkoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "gui.h"
#include "helpers.h"
#include "../lib/minilibx-linux/mlx.h"
#include "../lib/ft_printf/ft_printf.h"

void	destroy_gui(t_gui *gui)
{
	if (gui->window)
		mlx_destroy_window(gui->mlx, gui->window);
	if (gui->mlx)
		mlx_destroy_display(gui->mlx);
}	

t_gui	init_gui(void)
{
	t_gui gui;

	gui.mlx = mlx_init();
	if (gui.mlx == NULL)
		exit_error("Failed to init mlx\n");
	gui.x_size = 1920;
	gui.y_size = 1080;
	gui.fov_deg = 100;
	gui.window = mlx_new_window(\
		gui.mlx, (int)(gui.x_size), (int)(gui.y_size), "miniRT");
	if (gui.window == NULL)
	{
		destroy_gui(&gui);
		exit_error("Failed to open window\n");
	}
	// mlx_loop(gui.mlx);
	return (gui);
}
