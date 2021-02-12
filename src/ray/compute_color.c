/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   compute_color.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jkoers <jkoers@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/12 16:15:37 by jkoers        #+#    #+#                 */
/*   Updated: 2021/02/12 16:15:37 by jkoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
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

static bool		same_point(t_vec3 p1, t_vec3 p2, double range)
{
	return ((p1.x >= p2.x - range && p1.x <= p2.x + range) &&
			(p1.y >= p2.y - range && p1.y <= p2.y + range) &&
			(p1.z >= p2.z - range && p1.z <= p2.z + range));
}

/*
**  Assuming to_find has bounced
*/

static bool		clear_path(
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
	return (to_find.obj == found.obj &&
			same_point(to_find.point, found.point, EPSILON));
}

static t_rgb	ray_to_color(t_ray ray, const t_gui *gui)
{
	size_t			i;
	t_light			*light;
	t_rgb			scalar;
	double			intensity;
	const t_bounce	bounce = get_bounce(gui->shapes, ray);

	if (bounce.obj == NULL)
		return (shadow(gui));
	i = 0;
	scalar =
		add_color(rgb(0, 0, 0), gui->ambient.color, gui->ambient.brightness);
	while (arr_get(gui->lights, i) != NULL)
	{
		light = arr_get(gui->lights, i);
		if (!clear_path(bounce, light, gui->shapes))
		{
			intensity = relative_intensity(bounce.point, bounce.normal, light);
			scalar = add_color(scalar, light->color, intensity);
		}
		i++;
	}
	return (multiply_color(bounce.color, scalar));
}

t_rgb			compute_color(unsigned x, unsigned y, const t_gui *gui)
{

	const double	aa = 1.0 / sqrt(ANTI_ALIASING_LEVEL);
	double			x_off;
	double			y_off;
	t_rgb			color;
	t_ray			camera_ray;

	color = rgb(0, 0, 0);
	y_off = 0.0;
	while (y_off < 1.0)
	{
		x_off = 0.0;
		while (x_off < 1.0)
		{
			camera_ray = ray_from_pix(x + x_off, y + y_off, gui);
			color = add_color(color,
				ray_to_color(camera_ray, gui), 1.0 / ANTI_ALIASING_LEVEL);
			x_off += aa;
		}
		y_off += aa;
	}
	return (color);
}
