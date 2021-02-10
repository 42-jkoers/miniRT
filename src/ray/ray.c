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
#include "intersect.h"
#include "constants.h"
#include "vector.h"
#include <math.h>

/*
** Get closest object pointer from *shapes
*/

static t_bounce	get_bounce(const t_arr_voidp *shapes, t_ray ray)
{
	size_t		i;
	t_obj		*obj;
	t_hit		hit;
	t_bounce	bounce;
	double		closest_dist;

	i = 0;
	bounce.obj = NULL;
	closest_dist = DOUBLE_MAX;
	while (arr_get(shapes, i) != NULL)
	{
		obj = arr_get(shapes, i);
		hit = g_hit_shape[obj->shape](obj->pos, ray);
		if (hit.hit && hit.dist < closest_dist)
		{
			closest_dist = hit.dist;
			bounce.obj = obj;
			bounce.color = obj->color;
			bounce.point = hit.point;
			bounce.normal = hit.normal;
		}
		i++;
	}
	return (bounce);
}

/*
**  Assuming to_find has bounced
*/

static bool		is_obstructed(
	t_bounce to_find,
	const t_light *light,
	const t_arr_voidp *shapes)
{
	t_ray		ray;
	t_bounce	found;

	ray.origin = light->origin;
	ray.dir = unit(subtract(light->origin, to_find.point));
	found = get_bounce(shapes, ray);
	if (found.obj == NULL)
		return (false);
	return (to_find.obj == found.obj);
}

static t_rgb	compute_color(t_bounce bounce, const t_gui *gui)
{
	size_t	i;
	t_light	*light;
	t_rgb	scalar;
	double	intensity;

	if (bounce.obj == NULL)
		return (shadow(gui));
	i = 0;
	scalar =
		add_color(rgb(0, 0, 0), gui->ambient.color, gui->ambient.brightness);
	while (arr_get(gui->lights, i) != NULL)
	{
		light = arr_get(gui->lights, i);
		if (!is_obstructed(bounce, light, gui->shapes))
		{
			intensity = relative_intensity(bounce.point, bounce.normal, light);
			scalar = add_color(scalar, light->color, intensity);
		}
		i++;
	}
	return (multiply_color(bounce.color, scalar));
}

void			render(t_gui *gui)
{
	unsigned	x;
	unsigned	y;
	t_rgb		color;
	t_ray		camera_ray;
	t_bounce	bounce;

	y = 0;
	while (y < gui->y_size)
	{
		x = 0;
		while (x < gui->x_size)
		{
			camera_ray = ray_from_pix(x, y, gui);
			bounce = get_bounce(gui->shapes, camera_ray);
			color = compute_color(bounce, gui);
			gui_set_pixel(gui, x, y, color);
			x++;
		}
		y++;
	}
}
