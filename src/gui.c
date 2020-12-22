/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   gui.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: jkoers <jkoers@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/20 18:50:36 by jkoers        #+#    #+#                 */
/*   Updated: 2020/12/22 16:09:15 by jkoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "gui.h"
#include "helpers.h"
#include "keycodes.h"
#include "../lib/minilibx-linux/mlx.h"
#include "../lib/ft_printf/ft_printf.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void	exit_clean(int code, t_gui *gui, const char *format, ...)
{
	va_list ap;

	va_start(ap, format);
	ft_printf(format, ap);
	va_end(ap);
	if (gui != NULL)
	{
		if (gui->canvas.mlx_img)
			mlx_destroy_image(gui->mlx, gui->canvas.mlx_img);
		if (gui->window)
			mlx_destroy_window(gui->mlx, gui->window);
		if (gui->mlx)
			mlx_destroy_display(gui->mlx);
		free(gui);
	}
	exit(code);
}

int		on_keypress(int keycode, t_gui *gui)
{
	if (keycode == MLXKEY_ESC)
		exit_clean(0, gui, "Done\n");
	printf("Keycode %i\n", keycode);
	return (0);
}

void	gui_set_pixel(t_gui *gui, unsigned long x, unsigned long y, int color)
{
    char    *dst;

    dst = gui->canvas.data + \
		(y * gui->canvas.line_length + x * (gui->canvas.bpp / 8));
    *(unsigned int*)dst = color;
}

void	gui_write_canvas(t_gui *gui)
{
	mlx_put_image_to_window(gui->mlx, gui->window, gui->canvas.mlx_img, 0, 0);
}

t_gui	*gui_init(void)
{
	t_gui *gui;

	gui = malloc(sizeof(t_gui));
	if (gui == NULL)
		exit_clean(1, NULL, "GUI allocation failed\n");
	gui->mlx = mlx_init();
	if (gui->mlx == NULL)
		exit_clean(1, gui, "Failed to init mlx\n");
	gui->x_size = 1920;
	gui->y_size = 1080;
	gui->fov_deg = 100;
	gui->window = mlx_new_window(\
		gui->mlx, (int)(gui->x_size), (int)(gui->y_size), "miniRT");
	if (gui->window == NULL)
		exit_clean(1, gui, "Failed to open window\n");
	mlx_key_hook(gui->window, on_keypress, gui);
	gui->canvas.mlx_img = mlx_new_image(\
		gui->mlx, (int)(gui->x_size), (int)(gui->y_size));
	if (gui->canvas.mlx_img == NULL)
		exit_clean(1, gui, "Failed to create canvas at 1\n");
	gui->canvas.data = mlx_get_data_addr(gui->canvas.mlx_img, &gui->canvas.bpp,\
		&gui->canvas.line_length, &gui->canvas.byte_order);
	if (gui->canvas.data == NULL)
		exit_clean(1, gui, "Failed to create canvas at 2\n");
	return (gui);
}
