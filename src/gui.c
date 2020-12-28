/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   gui.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: jkoers <jkoers@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/20 18:50:36 by jkoers        #+#    #+#                 */
/*   Updated: 2020/12/28 17:31:04 by jkoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "gui.h"
#include "helpers.h"
#include "keycodes.h"
#include "rt_file.h"
#include "../lib/minilibx-linux/mlx.h"
#include "../lib/ft_printf/ft_printf.h"
#include "../lib/libft/include/libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <string.h>

t_gui	*new_gui(void)
{
	t_gui *gui;

	gui = malloc(sizeof(t_gui));
	if (gui == NULL)
		exit_clean(gui, "malloc 2\n");
	ft_bzero(gui, sizeof(t_gui));
	return (gui);
}

void	free_until_null(void **arr)
{
	size_t i;
	
	if (arr == NULL)
		return ;
	i = 0;
	while (arr[i])
		i++;
	ft_free_2d(arr, i);
}

void	exit_clean(t_gui *gui, const char *format, ...)
{
	va_list	ap;

	va_start(ap, format);
	vprintf(format, ap); // illegal
	va_end(ap);
	if (gui == NULL)
		exit(1);
	free_until_null((void **)gui->rt);
	free_until_null((void **)gui->rt_line_split);
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
	exit(1);
}

int		on_keypress(int keycode, t_gui *gui)
{
	if (keycode == MLXKEY_ESC)
		exit_clean(gui, "Done\n");
	return (0);
}

int	on_close(t_gui *gui)
{
	exit_clean(gui, "Done\n");
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

void	set_canvas(t_gui *gui)
{
	gui->canvas.mlx_img = mlx_new_image(gui->mlx, (int)(gui->x_size), (int)(gui->y_size));
	if (gui->canvas.mlx_img == NULL)
		exit_clean(gui, "Failed to create canvas at 1\n");
	gui->canvas.data = mlx_get_data_addr(gui->canvas.mlx_img, &gui->canvas.bpp, &gui->canvas.line_length, &gui->canvas.byte_order);
	if (gui->canvas.data == NULL)
		exit_clean(gui, "Failed to create canvas at 2\n");
}

t_gui	*gui_init(char *rt_filename)
{
	t_gui		*gui;
	
	gui = new_gui();
	gui->mlx = mlx_init();
	if (gui->mlx == NULL)
		exit_clean(gui, "Failed to init mlx\n");
	set_rt(gui, rt_filename);
	gui->fov_deg = 100;
	gui->window = mlx_new_window(gui->mlx, (int)(gui->x_size), (int)(gui->y_size), "miniRT");
	if (gui->window == NULL)
		exit_clean(gui, "Failed to open window\n");
	set_canvas(gui);
	mlx_key_hook(gui->window, on_keypress, gui);
	mlx_hook(gui->window, ClientMessage,  NoEventMask, on_close, gui);
	return (gui);
}
