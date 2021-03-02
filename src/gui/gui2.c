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
#include <stdio.h>

void	gui_render_next_camera(t_gui *gui)
{
	if (gui->cameras->length == 1)
		return ;
	gui->camera_i++;
	if (gui->camera_i >= gui->cameras->length)
		gui->camera_i = 0;
	if (VERBOSE)
		printf("Switching to camera %lu\n", gui->camera_i + 1);
	ft_memcpy(
		&gui->camera, arr_get(gui->cameras, gui->camera_i), sizeof(t_camera));
	gui_display_scene(gui);
}
