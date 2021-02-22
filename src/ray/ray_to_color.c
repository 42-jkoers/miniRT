/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ray_to_color.c                                     :+:    :+:            */
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

static bool	is2d(const t_obj *obj)
{
	if (obj->shape == SHAPE_TRIANGLE)
		return (true);
	if (obj->shape == SHAPE_PLANE)
		return (true);
	if (obj->shape == SHAPE_SQUARE)
		return (true);
	return (false);
}

static bool	same_point(t_vec3 p1, t_vec3 p2, double range)
{
	return ((p1.x >= p2.x - range && p1.x <= p2.x + range)
		&& (p1.y >= p2.y - range && p1.y <= p2.y + range)
		&& (p1.z >= p2.z - range && p1.z <= p2.z + range));
}

/*
**  Assuming to_find has bounced
*/

static bool	clear(t_bounce to_find, const t_light *l, const t_arr_voidp *shapes)
{
	t_ray		ray;
	t_bounce	found;

	ray.origin = l->origin;
	ray.dir = unit(subtract(l->origin, to_find.point));
	found = get_bounce(shapes, ray);
	if (found.obj == NULL)
		return (false);
	return (to_find.obj == found.obj
		&& same_point(to_find.point, found.point, EPSILON));
}

t_rgb	ray_to_color(t_ray ray, const t_gui *gui)
{
	size_t		i;
	t_light		*light;
	t_rgb		scalar;
	double		intensity;
	t_bounce	bounce;

	bounce = get_bounce(gui->shapes, ray);
	if (bounce.obj == NULL)
		return (shadow(gui));
	i = 0;
	scalar = add_color(
			rgb(0, 0, 0), gui->ambient.color, gui->ambient.brightness);
	while (arr_get(gui->lights, i) != NULL)
	{
		light = arr_get(gui->lights, i);
		if (!clear(bounce, light, gui->shapes))
		{
			intensity = relative_intensity(
					bounce.point, bounce.normal, is2d(bounce.obj), light);
			scalar = add_color(scalar, light->color, intensity);
		}
		i++;
	}
	return (multiply_color(bounce.color, scalar));
}
