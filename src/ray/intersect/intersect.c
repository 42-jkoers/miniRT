/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   intersect.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jkoers <jkoers@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/05 23:47:21 by jkoers        #+#    #+#                 */
/*   Updated: 2021/02/05 23:47:21 by jkoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "intersect.h"
#include "constants.h"
#include "vector.h"

// Shit name but okay
// For every point on a shape there can be 2 surface normals. Both on the same
// line pointing in opposite directions.
// The "correct" one is the normal that has the smallest angle with the origin
// of the ray. This function selects that "correct" normal by either inverting
// the input normal or not.

static void	scale_to_p(t_vec3 *normal, t_vec3 p)
{
	t_vec3	inv;

	inv = scale(*normal, -1);
	if (distance2(inv, p) < distance2(*normal, p))
		*normal = inv;
}

t_hit	hit_obj(t_shape shape, t_pos pos, t_ray ray)
{
	static	t_hit	(*hit_shape[SHAPE_LAST])(t_pos, t_ray) = {
		[SHAPE_CYLINDER] = hit_cylinder,
		[SHAPE_PLANE] = hit_plane,
		[SHAPE_SPHERE] = hit_sphere,
		[SHAPE_TRIANGLE] = hit_triangle,
	};
	t_hit			hit;

	hit = hit_shape[shape](pos, ray);
	if (hit.hit)
		scale_to_p(&hit.normal, ray.origin);
	return (hit);
}
