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

t_hit	hit_obj(t_shape shape, t_pos pos, t_ray ray)
{
	static	t_hit	(*hit_shape[SHAPE_LAST])(t_pos, t_ray) = {
		[SHAPE_CYLINDER] = hit_cylinder,
		[SHAPE_PLANE] = hit_plane,
		[SHAPE_SPHERE] = hit_sphere,
		[SHAPE_SQUARE] = hit_square,
		[SHAPE_TRIANGLE] = hit_triangle,
	};

	return (hit_shape[shape](pos, ray));
}
