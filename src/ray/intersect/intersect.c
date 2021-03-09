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

// Get the normal that points most towards ray.origin

t_vec3	correct_normal(t_vec3 normal, t_ray ray)
{
	if (dot(normal, ray.dir) > EPSILON)
		normal = scale(normal, -1);
	return (normal);
}

t_hit	hit_obj(t_shape shape, t_pos pos, t_ray ray)
{
	static	t_hit	(*hit_shape[SHAPE_LAST])(t_pos, t_ray) = {
		[SHAPE_CYLINDER] = hit_cylinder,
		[SHAPE_PLANE] = hit_plane,
		[SHAPE_SPHERE] = hit_sphere,
		[SHAPE_TRIANGLE] = hit_triangle,
	};

	return (hit_shape[shape](pos, ray));
}
