/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   gui.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: jkoers <jkoers@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/20 18:50:36 by jkoers        #+#    #+#                 */
/*   Updated: 2021/01/12 14:18:57 by jkoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "gui.h"

#include "constants.h"
#include "parse_rt.h"
#include "../lib/minilibx-linux/mlx.h"
#include "../lib/libft/include/libft.h"
#include <stdlib.h>

char	*gui_get_pixel_data(const t_gui *gui, unsigned long x, unsigned long y)
{
    return (gui->canvas.data + 
		(int)y * gui->canvas.line_length + (int)x * (gui->canvas.bpp / 8));
}

void	gui_set_pixel(t_gui *gui, double x, double y, t_rgb color)
{
	char	*pixel_data;

	pixel_data = gui_get_pixel_data(gui, x, y);
	pixel_data[0] = (uint8_t)color.b; 
	pixel_data[1] = (uint8_t)color.g;
	pixel_data[2] = (uint8_t)color.r;
	// gui->canvas.data[pixel + 3] = 0; // alpha is ignored by rest of codebase
}

t_rgb	gui_get_pixel(t_gui *gui, unsigned long x, unsigned long y)
{
	t_rgb color;
	char	*pixel_data;

	pixel_data = gui_get_pixel_data(gui, x, y);
	color.b = (unsigned char)pixel_data[0]; 
	color.g = (unsigned char)pixel_data[1];
	color.r = (unsigned char)pixel_data[2];
	return (color);
}

void	gui_write_canvas(t_gui *gui)
{
	mlx_put_image_to_window(gui->mlx, gui->window, gui->canvas.mlx_img, 0, 0);
}

void	exit_success(t_gui *gui)
{
	ft_putstr("Done\n");
	if (gui == NULL)
		exit(1);
	ft_arr_voidp_free(gui->shapes, free);
	if (gui->canvas.mlx_img)
		mlx_destroy_image(gui->mlx, gui->canvas.mlx_img);
	if (gui->mlx)
	{
		mlx_destroy_display(gui->mlx);
		free(gui->mlx);
	}
	free(gui);
	exit(0);
}
