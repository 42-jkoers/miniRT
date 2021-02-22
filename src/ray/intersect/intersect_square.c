/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   intersect_square.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: jkoers <jkoers@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/05 23:49:48 by jkoers        #+#    #+#                 */
/*   Updated: 2021/02/05 23:49:48 by jkoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "intersect.h"
#include "constants.h"
#include "vector.h"
#include <math.h>

static bool	is_inside_square(t_pos pos, t_vec3 hit_p)
{
	t_vec3	dist;
	double	border;

	dist = subtract(hit_p, pos.sq.origin);
	border = pos.sq.size * 0.5;
	if (fabs(dist.x) > border)
		return (false);
	if (fabs(dist.y) > border)
		return (false);
	if (fabs(dist.z) > border)
		return (false);
	return (true);
}

/*
** Converting square position data to plane position data
*/

static t_hit	hit_square_plane_subsection(t_pos pos, t_ray ray)
{
	t_pos	subsection;

	subsection.pl.origin = pos.sq.origin;
	subsection.pl.normal = pos.sq.normal;
	return (hit_plane(subsection, ray));
}

t_hit	hit_square(t_pos pos, t_ray ray)
{
	t_hit	hit;
	t_hit	subsection;

	subsection = hit_square_plane_subsection(pos, ray);
	if (!subsection.hit)
		return ((t_hit){false});
	hit.point = translate(pos.sq.origin, ray.dir, subsection.dist);
	if (!is_inside_square(pos, hit.point))
		return ((t_hit){false});
	hit.hit = true;
	hit.dist = subsection.dist;
	hit.normal = unit(pos.sq.normal);
	return (hit);
}
