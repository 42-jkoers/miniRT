/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   gui.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: jkoers <jkoers@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/20 18:50:36 by jkoers        #+#    #+#                 */
/*   Updated: 2021/01/12 19:09:25 by jkoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "gui.h"

#include "constants.h"
#include "parse_rt.h"
#include "ray.h"
#include "../lib/minilibx-linux/mlx.h"
#include "../lib/libft/include/libft.h"
#include <stdlib.h>
#include <stdio.h>

// Mlx has a somewhat weird way to save pixel data
// @return pointer to 0xBBGGRR in memory

char	*gui_get_pixel_data(const t_gui *gui, unsigned x, unsigned y)
{
	return (gui->canvas.data
		+ y * gui->canvas.line_length + x * (gui->canvas.bpp / 8));
}

void	gui_set_pixel(t_gui *gui, unsigned x, unsigned y, t_rgb color)
{
	char	*pixel_data;

	pixel_data = gui_get_pixel_data(gui, x, y);
	pixel_data[0] = (uint8_t)color.b;
	pixel_data[1] = (uint8_t)color.g;
	pixel_data[2] = (uint8_t)color.r;
}

t_rgb	gui_get_pixel(t_gui *gui, unsigned x, unsigned y)
{
	t_rgb	color;
	char	*pixel_data;

	pixel_data = gui_get_pixel_data(gui, x, y);
	color.b = (unsigned char)pixel_data[0];
	color.g = (unsigned char)pixel_data[1];
	color.r = (unsigned char)pixel_data[2];
	return (color);
}

// Cleanup before exiting

void	exit_success(t_gui *gui)
{
	if (STUPID)
		printf("Done\n");
	if (gui == NULL)
		exit(1);
	ft_arr_voidp_free(gui->shapes, free);
	ft_arr_voidp_free(gui->cameras, free);
	ft_arr_voidp_free(gui->lights, free);
	if (gui->window)
		mlx_destroy_window(gui->mlx, gui->window);
	if (gui->canvas.mlx_img)
		mlx_destroy_image(gui->mlx, gui->canvas.mlx_img);
	if (gui->mlx)
	{
		if (IS_LINUX)
			mlx_destroy_display(gui->mlx);
		free(gui->mlx);
	}
	exit(0);
}

void	gui_display_scene(t_gui *gui)
{
	render(gui);
	mlx_put_image_to_window(gui->mlx, gui->window, gui->canvas.mlx_img, 0, 0);
}
