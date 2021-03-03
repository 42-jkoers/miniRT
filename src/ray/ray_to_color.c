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

// Get closest t_obj * (relative to ray.origin) from *shapes

t_bounce	get_bounce(const t_arr_voidp *shapes, t_ray ray)
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
		hit = hit_obj(obj->shape, obj->pos, ray);
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

t_rgb	ray_to_color(t_ray ray, const t_gui *gui)
{
	size_t		i;
	t_light		*light;
	t_rgb		scalar;
	double		intensity;
	t_bounce	bounce;

	bounce = get_bounce(gui->shapes, ray);
	if (bounce.obj == NULL)
		return (no_bounce());
	i = 0;
	scalar = gui->ambient.scalar;
	while (arr_get(gui->lights, i) != NULL)
	{
		light = arr_get(gui->lights, i);
		if (is_clear_path(bounce, light, gui))
		{
			intensity = relative_intensity(
					bounce.point, bounce.normal, is2d(bounce.obj), light);
			scalar = add_color(scalar, light->color, intensity);
		}
		i++;
	}
	return (multiply_color(bounce.color, scalar));
}
