/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   non_shape.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jkoers <jkoers@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/05 19:05:04 by jkoers        #+#    #+#                 */
/*   Updated: 2021/01/06 01:06:46 by jkoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */


#include "non_shape.h"
#include "constants.h"
#include "unsorted.h"
#include "../lib/libft/include/libft.h"
#include <math.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

void	add_camera(t_arr_voidp **cameras, char *line)
{
	char		**items;
	t_camera	*cam;

	cam = malloc(sizeof(t_camera));
	if (cam == NULL)
		exit_e("malloc");
	ft_bzero(cam, sizeof(t_camera));
	items =  split_clamp(line, 4);
	set_point(&cam->origin, items[1]);
	set_point(&cam->orientation, items[2]);
	cam->fov = strtodbl_clamp(items[3], '\0', 0.0, 180.0);
	cam->fov = radians(cam->fov);
	if (ft_arr_voidp_push(cameras, cam) == NULL)
		exit_e("malloc");
	ft_free_until_null_char(items);
}

void	add_light(t_arr_voidp **lights, char *line)
{
	char	**items;
	t_light	*light;

	light = malloc(sizeof(t_light));
	if (light == NULL)
		exit_e("malloc");
	items =  split_clamp(line, 4);
	set_point(&light->origin, items[1]);
	light->brightness = strtodbl_clamp(items[2], '\0', 0.0, 1.0);
	set_point(&light->orientation, items[3]);
	if(ft_arr_voidp_push(lights, light) == NULL)
		exit_e("malloc");
	ft_free_until_null_char(items);
}

void	set_resolution(unsigned long *x, unsigned long *y, char *line)
{
	char	**items;

	items =  split_clamp(line, 3);
	*x = (unsigned long)strtonum_clamp(items[1], '\0', 1, LONG_MAX);
	*y = (unsigned long)strtonum_clamp(items[2], '\0', 1, LONG_MAX);	
	ft_free_until_null_char(items);
}

void	set_ambient(t_ambient *ambient, char *line)
{
	char	**items;

	items =  split_clamp(line, 3);
	ambient->brightness = strtodbl_clamp(items[1], '\0', 0.0, LONG_MAX);
	set_color(&ambient->color, items[2]);
	ft_free_until_null_char(items);
}

void	set_camera_distance_canvas(t_arr_voidp *cameras, t_gui *gui)
{
	size_t		i;
	t_camera	*cam;
	
	i = 0;
	cam = (t_camera *)ft_arr_voidp_get(cameras, i);
	while (cam)
	{
		cam->distance_canvas = (gui->x_size / 2.0) / tan(cam->fov / 2.0);
		cam = (t_camera *)ft_arr_voidp_get(cameras, i);
		i++;
	}
}

void	set_size(double *x_size, double *y_size, t_gui *gui)
{
	*x_size = (double)(gui->x_resolution) * UNITS_PER_PIXEL;
	*y_size = (double)(gui->y_resolution) * UNITS_PER_PIXEL;
}
