/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   gui2.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jkoers <jkoers@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/07 15:06:12 by jkoers        #+#    #+#                 */
/*   Updated: 2021/02/07 15:06:12 by jkoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "gui.h"
#include "constants.h"
#include "parse_rt.h"
#include "../lib/minilibx-linux/mlx.h"
#include "ray.h"

void	gui_render_next_camera(t_gui *gui)
{
	gui->camera_i++;
	if (gui->camera_i >= gui->cameras->length)
		gui->camera_i = 0;
	ft_memcpy(
		&gui->camera, arr_get(gui->cameras, gui->camera_i), sizeof(t_camera));
	gui_display_scene(gui);
}
