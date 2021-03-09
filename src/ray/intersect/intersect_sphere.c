/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   intersect_sphere.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: jkoers <jkoers@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/05 23:43:16 by jkoers        #+#    #+#                 */
/*   Updated: 2021/02/05 23:43:16 by jkoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "intersect.h"
#include "constants.h"
#include "vector.h"
#include <math.h>
#include "quadratic.h"

static bool	get_intersections(double *t0, double *t1, t_sphere sp, t_ray ray)
{
	t_vec3		l;
	t_quadratic	q;

	l = subtract(ray.origin, sp.origin);
	q.a = dot(ray.dir, ray.dir);
	q.b = 2 * dot(ray.dir, l);
	q.c = dot(l, l) - sp.radius2;
	return (solve_quadratic(q, t0, t1));
}

// see doc/rayspherecases.png

static double	actual_t(double t0, double t1)
{
	if (t0 > 0 && t1 > 0)
		return (t0);
	if (t0 <= 0 && t1 > 0)
		return (t1);
	return (-1);
}

t_hit	hit_sphere(t_pos pos, t_ray ray)
{
	double	t0;
	double	t1;
	t_hit	hit;

	if (!get_intersections(&t0, &t1, pos.sp, ray))
		return ((t_hit){false});
	hit.dist = actual_t(t0, t1);
	if (hit.dist < 0)
		return ((t_hit){false});
	hit.hit = true;
	hit.point = translate(ray.origin, ray.dir, hit.dist);
	if (distance2(ray.origin, pos.sp.origin) > pos.sp.radius2)
		hit.normal = unit(subtract(hit.point, pos.sp.origin));
	else
		hit.normal = unit(subtract(pos.sp.origin, hit.point));
	return (hit);
}
