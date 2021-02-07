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
#include "../lib/libft/include/libft.h"
#include <math.h>

t_hit (*g_hit_shape[SHAPE_LAST])(t_pos, t_ray) = {
	[SHAPE_SPHERE] = hit_sphere,
	[SHAPE_TRIANGLE] = hit_triangle,
	[SHAPE_PLANE] = hit_plane,
	[SHAPE_SQUARE] = hit_square,
};
