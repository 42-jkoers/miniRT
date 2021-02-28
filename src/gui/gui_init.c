/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   gui_init.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jkoers <jkoers@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/10 14:09:36 by jkoers        #+#    #+#                 */
/*   Updated: 2021/01/12 15:00:02 by jkoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "gui.h"
#include "constants.h"
#include "parse_rt.h"
#include "../lib/minilibx-linux/mlx.h"
#include "ray.h"
#include <stdlib.h>
#include <stdio.h>

// Create a mlx image of the right size to store the rendered scene

static void	set_canvas(t_canvas *canvas, t_gui *gui, bool max_size)
{
	int		screen_x;
	int		screen_y;

	if (max_size && MAX_WINDOW_SIZE)
	{
		mlx_get_screen_size(gui->mlx, &screen_x, &screen_y);
		if (screen_x < (int)gui->x_size || screen_y < (int)gui->y_size)
			printf("Note: decreased resolution to fit screen\n");
		if (screen_x < (int)gui->x_size)
			gui->x_size = screen_x;
		if (screen_y < (int)gui->y_size)
			gui->y_size = screen_y;
	}
	canvas->mlx_img = mlx_new_image(
			gui->mlx, (int)gui->x_size, (int)gui->y_size);
	if (canvas->mlx_img == NULL)
		exit_e("Can't create canvas image 1");
	canvas->data = mlx_get_data_addr(canvas->mlx_img, &canvas->bpp,
			&canvas->line_length, &canvas->byte_order);
	if (canvas->data == NULL)
		exit_e("Can't create canvas image 2");
}

static int	on_keypress(int keycode, t_gui *gui)
{
	if (keycode == XK_Escape)
		exit_success(gui);
	if (keycode == NEXT_CAMERA_KEY)
		gui_render_next_camera(gui);
	return (0);
}

// When the red cross/the close button is pressed run this

static int	on_cross(t_gui *gui)
{
	exit_success(gui);
	return (0);
}

static void	open_window(t_gui *gui)
{
	gui->window = mlx_new_window(
			gui->mlx, (int)gui->x_size, (int)gui->y_size, "miniRT");
	if (gui->window == NULL)
		exit_e("mlx_new_window() failed");
	mlx_key_hook(gui->window, on_keypress, gui);
	mlx_hook(gui->window, 33, 0L, on_cross, gui);
	gui_display_scene(gui);
	mlx_loop(gui->mlx);
}

void	gui_init(t_gui *gui, const char *rt_filename, bool create_window)
{
	ft_bzero(gui, sizeof(t_gui));
	gui->mlx = mlx_init();
	if (gui->mlx == NULL)
		exit_e("mlx_init() failed");
	parse_rt(gui, rt_filename);
	set_canvas(&gui->canvas, gui, create_window);
	if (create_window)
		open_window(gui);
}
