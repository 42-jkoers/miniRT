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

static t_rgb	set_brightness(t_rgb color, double brightness)
{
	// amount = 1 - amount;
	// printf("%lf\n", amount);
	color.r = (double)color.r * /* 0.2126 * */ brightness;
	color.g = (double)color.g * /* 0.7152 * */ brightness;
	color.b = (double)color.b * /* 0.0722 * */ brightness;
	return (color);
}

static double	max_dbl(double a, double b)
{
	return (a > b ? a : b);
}

static double	min_dbl(double a, double b)
{
	return (a < b ? a : b);
}

// static double	abs_dbl(double d)
// {
// 	return (d < 0.0 ? 0.0 : d);
// }

t_rgb	compute_color(t_hit hit, t_obj obj, const t_gui *gui)
{
	size_t	i;
	t_light	*light;
	t_vec3	to_light;
	double	dim_n;
	
	if (!hit.hit)
		return ((struct s_rgb){0, 0, 0});
	i = 0;
	while (ft_arr_voidp_get(gui->lights, i) != NULL)
	{
		light = (t_light *)ft_arr_voidp_get(gui->lights, i);
		// light is not obstructed by objects for now
		to_light = unit(subtract(light->origin, hit.point));
		dim_n = 1 * light->brightness * max_dbl(0.0, dot(hit.normal, to_light));
		dim_n = min_dbl(dim_n, 1.0);
		return (set_brightness(obj.color, dim_n));
		i++;
	}
	return ((struct s_rgb){0, 0, 0});
}

t_rgb	get_color(t_ray ray, const t_gui *gui)
{
	size_t	i;
	t_obj	*obj;
	t_obj	closest_obj;
	t_hit	closest_hit;
	t_hit	hit;

	i = 0;
	closest_hit.hit = false;
	closest_hit.dist = DOUBLE_MAX;
	while (ft_arr_voidp_get(gui->shapes, i) != NULL)
	{
		obj = ft_arr_voidp_get(gui->shapes, i);
		hit = g_hit_shape[obj->shape](obj->pos, ray);
		if (hit.hit && hit.dist < closest_hit.dist)
		{
			closest_hit = hit;
			closest_obj = *obj;
		}
		i++;
	}
	return (compute_color(closest_hit, closest_obj, gui));
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
			color = get_color(ray, gui);
			gui_set_pixel(gui, x, y, color);
			x++;
		}
		y++;
	}
}
