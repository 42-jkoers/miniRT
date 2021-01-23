/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ray.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: jkoers <jkoers@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/05 13:18:30 by jkoers        #+#    #+#                 */
/*   Updated: 2021/01/18 13:21:18 by jkoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include "gui.h"

#include "constants.h"
#include "vector.h"
#include "../lib/minilibx-linux/mlx.h"
#include "../lib/libft/include/libft.h"
#include <math.h>

void	set_ray(t_ray *ray,
	double x, double y, const t_gui *gui)
{
	const double fov_scale = tan(gui->camera->fov * 0.5);
	const double aspect_ratio = gui->x_size / gui->y_size;
	const double px = (2 * (x + 0.5) / gui->x_size - 1) * aspect_ratio * fov_scale;
	const double py = (2 * (y + 0.5) / gui->y_size - 1) * fov_scale;

	ray->origin = gui->camera->origin;
	t_vec3 positive_x;
	if (gui->camera->orientation.x == 0.0 && gui->camera->orientation.z == 0.0)
		positive_x = vec(1.0, 0.0, 0.0);
	else
		positive_x = cross(gui->camera->orientation, vec(0.0, 1.0, 0.0));
	t_vec3 negative_y = cross(gui->camera->orientation, positive_x);
	t_vec3 scaled_x = scale(positive_x, px);
	t_vec3 scaled_y = scale(negative_y, py);
	ray->dir = add(add(scaled_x, scaled_y), gui->camera->orientation);
	normalize(&ray->dir);
}

void	*find_closest_shape(t_ray ray, const t_gui *gui)
{
	size_t	i;
	t_obj	*obj;
	t_obj	*closest_obj;
	double	closest;
	double	dist;

	i = 0;
	closest = DOUBLE_MAX;
	closest_obj = NULL;
	while (ft_arr_voidp_get(gui->shapes, i) != NULL)
	{
		obj = ft_arr_voidp_get(gui->shapes, i);
		if (g_distance[obj->shape](&dist, obj->pos, ray))
			if (dist < closest)
			{
				closest = dist;
				closest_obj = obj;
			}
		i++;
	}
	return (closest_obj);
}

void	compute_pixel(t_rgb *color,
			t_ray ray, const t_gui *gui)
{
	const t_obj *closest_shape = find_closest_shape(ray, gui);

	if (closest_shape == NULL)
		ft_bzero(color, sizeof(t_rgb));
	else
		*color = closest_shape->color;
}

void	render(t_gui *gui)
{
	double	x;
	double	y;
	t_rgb	color;
	static	t_ray ray;

	y = 0;
	while (y < gui->y_size)
	{
		x = 0;
		while (x < gui->x_size)
		{
			set_ray(&ray, x, y, gui);
			compute_pixel(&color, ray, gui);
			gui_set_pixel(gui, x, y, color);
			x++;
		}
		y++;
	}
}
