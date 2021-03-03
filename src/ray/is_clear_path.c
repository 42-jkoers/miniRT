/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   is_clear_path.c                                    :+:    :+:            */
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

bool	is2d(const t_obj *obj)
{
	if (obj->shape == SHAPE_TRIANGLE)
		return (true);
	if (obj->shape == SHAPE_PLANE)
		return (true);
	if (obj->shape == SHAPE_SQUARE)
		return (true);
	return (false);
}

static bool	same_point(t_vec3 p1, t_vec3 p2, double epsilon)
{
	return ((p1.x >= p2.x - epsilon && p1.x <= p2.x + epsilon)
		&& (p1.y >= p2.y - epsilon && p1.y <= p2.y + epsilon)
		&& (p1.z >= p2.z - epsilon && p1.z <= p2.z + epsilon));
}

// Eg: the camera is inside a sphere and the light source is outside the sphere

static bool	light_obstructed_by_itself(
	t_bounce to_find, const t_light *l, const t_gui *gui)
{
	t_hit		hit;
	t_ray		ray;

	if (is2d(to_find.obj))
		return (false);
	ray.origin = gui->camera.origin;
	ray.dir = unit(subtract(l->origin, gui->camera.origin));
	hit = hit_obj(to_find.obj->shape, to_find.obj->pos, ray);
	return (hit.hit);
}

// If there is a clear path between *l and te bounce point of to_find.
// Assuming to_find has bounced

bool	is_clear_path(
	t_bounce to_find, const t_light *l, const t_gui *gui)
{
	t_ray		ray;
	t_bounce	found;

	if (light_obstructed_by_itself(to_find, l, gui))
		return (false);
	ray.origin = l->origin;
	ray.dir = unit(subtract(to_find.point, l->origin));
	found = get_bounce(gui->shapes, ray);
	if (found.obj == NULL)
		return (false);
	return ((to_find.obj == found.obj)
		&& same_point(to_find.point, found.point, 0.1));
}
