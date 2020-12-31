/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   gui.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: jkoers <jkoers@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/20 18:50:36 by jkoers        #+#    #+#                 */
/*   Updated: 2020/12/31 02:17:24 by jkoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "gui.h"
#include "shapes.h"
#include "constants.h"
#include "rt_file.h"
#include "constants.h"
#include "../lib/minilibx-linux/mlx.h"
#include "../lib/ft_printf/ft_printf.h"
#include "../lib/libft/include/libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <string.h>

void	print_joppe_sterror(e_msg msg)
{
	static const char *joppe_strerror[MSG_LAST] = {
		[SUCCESS] = "Done\n",
		[ERR_USELESS] = "Useless error message\n",
		[ERR_MALLOC] = "Malloc failed\n",
		[ERR_MLXINIT] = "Failed to init mlx\n",
		[ERR_RT_NOTFOUND] = "Rt file not found\n",
		[ERR_RT_EMPTY] = "Rt file is empty\n",
		[ERR_RT_INVALID] = "Rt file is invalid\n",
		[ERR_RT_BADRULE] = "Rt rule is invalid\n",
		[ERR_RT_NUMARGS] = "Rt rule has wrong number of arguments\n",
		[ERR_RT_BADVALUE] = "Rt rule has illegal value\n",
		[ERR_RT_UNKNOWN_RULE] = "Unknow rt rule\n",
		[ERR_RT_UNEXPECTED_CHAR] = "Unexpected character\n",
		[ERR_RT_UNEXPECTED_EOL] = "Unexpected end of line\n",
		[ERR_CANVAS_CREATEIMG] = "Failed to create mlx image for canvas\n",
		[ERR_MLX_INIT] = "Mlx init failed\n",
		[ERR_WINDOW_CREATE] = "Cannot create window\n"
	};
	ft_putstr((char *)(joppe_strerror[msg]));
}

void	exit_clean(t_gui *gui, e_msg msg)
{
	print_joppe_sterror(msg);
	if (gui == NULL)
		exit(msg == SUCCESS ? 0 : 1);
	ft_arr_voidp_free(gui->shapes, free);
	if (gui->window)
		mlx_destroy_window(gui->mlx, gui->window);
	if (gui->mlx)
	{
		mlx_destroy_display(gui->mlx);
		free(gui->mlx);
	}
	free(gui);
	exit(msg == SUCCESS ? 0 : 1);
}

t_gui	*new_gui(void)
{
	t_gui *gui;

	gui = malloc(sizeof(t_gui));
	if (gui == NULL)
		exit_clean(gui, ERR_MALLOC);
	ft_bzero(gui, sizeof(t_gui));
	return (gui);
}

int		on_keypress(int keycode, t_gui *gui)
{
	if (keycode == XK_Escape)
		exit_clean(gui, SUCCESS);
	return (0);
}

int		on_close(t_gui *gui)
{
	exit_clean(gui, SUCCESS);
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

e_msg	destroy_canvas(e_msg msg, t_canvas *canvas, void *mlx)
{
	if (canvas->mlx_img)
		mlx_destroy_image(mlx, canvas->mlx_img);
	return (msg);
}

e_msg	set_canvas(t_canvas *canvas, void *mlx, unsigned long x_size, unsigned long y_size)
{
	canvas->mlx_img = mlx_new_image(mlx, (int)(x_size), (int)(y_size));
	if (canvas->mlx_img == NULL)
		return (destroy_canvas(ERR_MALLOC, canvas, mlx));
	canvas->data = mlx_get_data_addr(canvas->mlx_img, &canvas->bpp, &canvas->line_length, &canvas->byte_order);
	if (canvas->data == NULL)
		return (destroy_canvas(ERR_MALLOC, canvas, mlx));
	return (SUCCESS);	
}

e_msg	set_window(void **window, void *mlx, unsigned long *x_size, unsigned long *y_size)
{
	void			*w;
	unsigned long	screen_xsize;
	unsigned long	screen_ysize;

	w = mlx_new_window(mlx, (int)(*x_size), (int)(*y_size), "miniRT");
	if (w == NULL)
		return (ERR_WINDOW_CREATE);
	*window = w;
	mlx_get_screen_size(mlx, (int *)&screen_xsize, (int *)&screen_ysize);
	if (screen_xsize < *x_size)
	{
		*x_size = screen_xsize;
		if (VERBOSE)
			ft_putstr("Note: decreased x resolution\n");
	}
	if (screen_ysize < *y_size)
	{
		*y_size = screen_ysize;
		if (VERBOSE)
			ft_putstr("Note: decreased y resolution\n");
	}
	return (SUCCESS);
}

t_gui	*gui_init(char *rt_filename)
{
	t_gui	*gui;
	e_msg	msg;
	
	gui = new_gui();
	gui->mlx = mlx_init();
	if (gui->mlx == NULL)
		exit_clean(gui, ERR_MLX_INIT);
	msg = parse_rt(rt_filename, gui);
	if (msg != SUCCESS)
		exit_clean(gui, msg);
	msg = set_window(gui->window, gui->mlx, &gui->x_size, &gui->y_size);
	if (msg != SUCCESS)
		exit_clean(gui, msg);
	msg = set_canvas(&gui->canvas, gui->mlx, gui->x_size, gui->y_size);
	if (msg != SUCCESS)
		exit_clean(gui, msg);
	mlx_key_hook(gui->window, on_keypress, gui);
	mlx_hook(gui->window, ClientMessage,  NoEventMask, on_close, gui);
	return (gui);
}
