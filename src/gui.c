/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   gui.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: jkoers <jkoers@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/20 18:50:36 by jkoers        #+#    #+#                 */
/*   Updated: 2021/01/06 01:07:40 by jkoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "gui.h"
#include "shapes.h"
#include "constants.h"
#include "rt_file.h"
#include "../lib/minilibx-linux/mlx.h"
#include "../lib/libft/include/libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <string.h>

void	exit_success(t_gui *gui)
{
	ft_putstr("Done\n");
	if (gui == NULL)
		exit(1);
	ft_arr_voidp_free(gui->shapes, free);
	if (gui->canvas.mlx_img)
		mlx_destroy_image(gui->mlx, gui->canvas.mlx_img);
	if (gui->window)
		mlx_destroy_window(gui->mlx, gui->window);
	if (gui->mlx)
	{
		mlx_destroy_display(gui->mlx);
		free(gui->mlx);
	}
	free(gui);
	exit(0);
}

t_gui	*new_gui(void)
{
	t_gui *gui;

	gui = malloc(sizeof(t_gui));
	if (gui == NULL)
		exit_e("malloc");
	ft_bzero(gui, sizeof(t_gui));
	return (gui);
}

int		on_keypress(int keycode, t_gui *gui)
{
	if (keycode == XK_Escape)
		exit_success(gui);
	return (0);
}

int		on_close(t_gui *gui)
{
	exit_success(gui);
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

void	set_canvas(t_canvas *canvas,
			void *mlx, unsigned long x_size, unsigned long y_size)
{
	canvas->mlx_img = mlx_new_image(mlx, (int)(x_size), (int)(y_size));
	if (canvas->mlx_img == NULL)
		exit_e("Can't create canvas image 1");
	canvas->data = mlx_get_data_addr(canvas->mlx_img, &canvas->bpp,
		&canvas->line_length, &canvas->byte_order);
	if (canvas->data == NULL)
		exit_e("Can't create canvas image 2");

}

void	set_window(void **window, unsigned long *x_size, unsigned long *y_size,
			void *mlx)
{
	int		screen_xsize;
	int		screen_ysize;

	*window = mlx_new_window(mlx, (int)(*x_size), (int)(*y_size), "miniRT");
	if (*window == NULL)
		exit_e("malloc");
	mlx_get_screen_size(mlx, &screen_xsize, &screen_ysize);
	if (screen_xsize < (int)*x_size)
	{
		*x_size = screen_xsize;
		verbose("Note: decreased x resolution\n");
	}
	if (screen_ysize < (int)*y_size)
	{
		*y_size = screen_ysize;
		verbose("Note: decreased y resolution\n");
	}
}

t_gui	*gui_init(char *rt_filename)
{
	t_gui	*gui;
	
	gui = new_gui();
	gui->mlx = mlx_init();
	parse_rt(gui, rt_filename);
	set_window(&gui->window, &gui->x_resolution, &gui->y_resolution, gui->mlx);
	set_canvas(&gui->canvas, gui->mlx, gui->x_resolution, gui->y_resolution);
	mlx_key_hook(gui->window, on_keypress, gui);
	mlx_hook(gui->window, 33,  0L, on_close, gui);
	return (gui);
}
