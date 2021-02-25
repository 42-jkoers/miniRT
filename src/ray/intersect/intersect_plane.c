/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   intersect_plane.c                                  :+:    :+:            */
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

t_hit	hit_plane(t_pos pos, t_ray ray)
{
	double	denom;
	double	t;
	t_vec3	p0l0;
	t_hit	hit;

	denom = dot(pos.pl.normal, ray.dir);
	p0l0 = subtract(pos.pl.origin, ray.origin);
	t = dot(p0l0, pos.pl.normal) / denom;
	if (t < 0.0)
		return ((t_hit){false});
	hit.hit = true;
	hit.dist = t;
	hit.normal = pos.pl.normal;
	hit.point = add(ray.origin, scale(ray.dir, hit.dist));
	return (hit);
}
