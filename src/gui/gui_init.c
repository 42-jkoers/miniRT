/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   gui_init.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jkoers <jkoers@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/10 14:09:36 by jkoers        #+#    #+#                 */
/*   Updated: 2021/01/12 14:30:42 by jkoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "gui.h"
#include "constants.h"
#include "parse_rt.h"
#include "../lib/minilibx-linux/mlx.h"
#include <stdint.h>
#include <stdlib.h>

static void	set_canvas(t_canvas *canvas, const t_gui *gui)
{
	canvas->mlx_img = mlx_new_image(
		gui->mlx, (int)gui->x_resolution, (int)gui->y_resolution);
	if (canvas->mlx_img == NULL)
		exit_e("Can't create canvas image 1");
	canvas->data = mlx_get_data_addr(canvas->mlx_img, &canvas->bpp,
		&canvas->line_length, &canvas->byte_order);
	if (canvas->data == NULL)
		exit_e("Can't create canvas image 2");
}

static int	on_keypress(int keycode, void *mlx)
{
	if (keycode == XK_Escape)
		mlx_loop_end(mlx);
	return (0);
}

static void	open_window(t_gui *gui)
{
	int		screen_x;
	int		screen_y;

	mlx_get_screen_size(gui->mlx, &screen_x, &screen_y);
	if (screen_x < (int)gui->x_resolution)
	{
		gui->x_resolution = screen_x;
		gui->x_resolution = (double)screen_x;
		verbose("Note: decreased x resolution\n");
	}
	if (screen_y < (int)gui->y_resolution)
	{
		gui->y_resolution = screen_y;
		gui->y_resolution = (double)screen_y;
		verbose("Note: decreased y resolution\n");
	}
	gui->window = mlx_new_window(
		gui->mlx, (int)gui->x_resolution, (int)gui->y_resolution, "miniRT");
	if (gui->window == NULL)
		exit_e("malloc");
	mlx_key_hook(gui->window, on_keypress, gui);
	mlx_hook(gui->window, 33, 0L, mlx_loop_end, gui->mlx);
	mlx_loop(gui->mlx);
	mlx_destroy_window(gui->mlx, gui->window);
}

t_gui		*gui_init(char *rt_filename, t_gui_mode mode)
{
	t_gui	*gui;
	
	gui = calloc_safe(sizeof(t_gui));
	gui->mlx = mlx_init();
	if (gui->mlx == NULL)
		exit_e("malloc");
	parse_rt(gui, rt_filename);
	set_canvas(&gui->canvas, gui);
	if (mode == WINDOW)
	{
		open_window(gui);
	}
	else if (mode == CREATE_BMP)
	{
		if (save_bmp(gui) != 0)
			exit_errno("Failed to create bmp image");
	}
	return (gui);
}
