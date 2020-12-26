/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   gui.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: jkoers <jkoers@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/20 18:50:36 by jkoers        #+#    #+#                 */
/*   Updated: 2020/12/26 22:26:58 by jkoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "gui.h"
#include "helpers.h"
#include "keycodes.h"
#include "../lib/minilibx-linux/mlx.h"
#include "../lib/ft_printf/ft_printf.h"
#include "../lib/libft/include/libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

t_gui	*new_gui(void)
{
	t_gui *gui;

	gui = malloc(sizeof(t_gui));
	if (gui == NULL)
		return (NULL);
	gui->mlx = NULL;
	gui->window = NULL;
	gui->x_size = 0;
	gui->y_size = 0;
	gui->fov_deg = 0;
	return (gui);
}

void	exit_clean(t_gui *gui, char **rt, const char *format, ...)
{
	va_list	ap;
	size_t	i;

	if (rt)
	{
		i = 0;
		while (rt[i])
			i++;
		ft_free_2d((void **)rt, i);
	}
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
	exit(1);
}

int		on_keypress(int keycode, t_gui *gui)
{
	if (keycode == MLXKEY_ESC)
		exit_clean(gui, NULL, "Done\n");
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

void	set_resolution(t_gui *gui, char **rt)
{
	size_t	i;
	char	**resolution;
	size_t	params;

	i = 0;
	resolution = NULL;
	while (rt[i] && rt[i][0] != RT_RESOLUTION_ID)
		i++;
	if (rt[i][0] != RT_RESOLUTION_ID)
		exit_clean(gui, rt, "No resolution setting found\n");
	resolution = ft_split_length(rt[i], ' ', &params);
	if (resolution == NULL)
		exit_clean(gui, rt, "malloc 1\n");
	if (params < 3 || 
		!ft_isdigit(resolution[1][0]) || 
		!ft_isdigit(resolution[2][0]))
		exit_clean(gui, rt, "Failed to set resolution\n");
	mlx_get_screen_size(gui->mlx, (int *)(&gui->x_size), (int *)(&gui->y_size));
	gui->x_size = ft_min_u(gui->x_size, ft_strtonum_u(resolution[1]));
	gui->y_size = ft_min_u(gui->y_size, ft_strtonum_u(resolution[2]));
	if (gui->x_size == 0 || gui->y_size == 0)
		exit_clean(gui, rt, "Can't open window with width = 0 || height == 0\n");
}

t_gui	*gui_init(char *rt_filename)
{
	t_gui		*gui;
	char		**rt;
	size_t		rt_lines;
	
	gui = new_gui();
	if (gui == NULL)
		exit_clean(NULL, NULL, "malloc 2\n");
	rt = ft_split_file(rt_filename, &rt_lines);
	if (rt == NULL || rt_lines == 0)
		exit_clean(gui, rt, "rt file nonexistant or empty <%s>\n", rt_filename);
	gui->mlx = mlx_init();
	if (gui->mlx == NULL)
		exit_clean(gui, rt, "Failed to init mlx\n");
	set_resolution(gui, rt);
	gui->fov_deg = 100;
	gui->window = mlx_new_window(gui->mlx, (int)(gui->x_size), (int)(gui->y_size), "miniRT");
	if (gui->window == NULL)
		exit_clean(gui, rt, "Failed to open window\n");
	mlx_key_hook(gui->window, on_keypress, gui);
	gui->canvas.mlx_img = mlx_new_image(gui->mlx, (int)(gui->x_size), (int)(gui->y_size));
	if (gui->canvas.mlx_img == NULL)
		exit_clean(gui, rt, "Failed to create canvas at 1\n");
	gui->canvas.data = mlx_get_data_addr(gui->canvas.mlx_img, &gui->canvas.bpp, &gui->canvas.line_length, &gui->canvas.byte_order);
	if (gui->canvas.data == NULL)
		exit_clean(gui, rt, "Failed to create canvas at 2\n");
	return (gui);
}
