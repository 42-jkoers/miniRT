/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   intersect_triangle.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: jkoers <jkoers@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/05 23:43:16 by jkoers        #+#    #+#                 */
/*   Updated: 2021/02/05 23:43:16 by jkoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
** #include "intersect.h"
**
** #include "constants.h"
** #include "vector.h"
** #include "../lib/libft/include/libft.h"
** #include <math.h>
**
** t_hit	hit_triangle(t_pos pos, t_ray ray)
** {
** 	t_vec3 h, s, q;
** 	double a, f, u, v;
**
** 	h = cross(ray.dir, pos.tr.edge2);
** 	a = dot(pos.tr.edge1, h);
** 	if (a > -EPSILON && a < EPSILON)
** 		return ((t_hit){false}); // Ray is parallel to this triangle.
** 	f = 1.0 / a;
** 	s = subtract(ray.origin, pos.tr.p0);
** 	u = f * dot(s, h);
** 	if (u < 0.0 || u > 1.0)
** 		return ((t_hit){false});
** 	q = cross(s, pos.tr.edge1);
** 	v = f * dot(ray.dir, q);
** 	if (v < 0.0 || u + v > 1.0)
** 		return ((t_hit){false});
** 	double t = f * dot(pos.tr.edge2, q);
** 	if (t < EPSILON) // There is a line intersection but not a ray intersection
** 		return ((t_hit){false});
**
** 	t_hit	hit;
** 	hit.hit = true;
** 	hit.dist = length(scale(ray.dir, t));
** 	hit.point = scale(ray.origin, hit.dist);
** 	hit.normal = cross(subtract(pos.tr.p1, pos.tr.p0),
** 		subtract(pos.tr.p2, pos.tr.p0)); // N = (v1-v0).crossProduct(v2-v0);
** 	hit.normal = unit(scale(hit.normal, -1.0));
** 	return (hit);
** }
*/

#include "intersect.h"
#include "norm.h"
#include "constants.h"
#include "vector.h"

t_hit	hit_triangle(t_pos pos, t_ray ray)
{
	t_hit_triangle	n;

	n.h = cross(ray.dir, pos.tr.edge2);
	n.a = dot(pos.tr.edge1, n.h);
	if (n.a > -EPSILON && n.a < EPSILON)
		return ((t_hit){false});
	n.f = 1.0 / n.a;
	n.s = subtract(ray.origin, pos.tr.p0);
	n.u = n.f * dot(n.s, n.h);
	if (n.u < 0.0 || n.u > 1.0)
		return ((t_hit){false});
	n.q = cross(n.s, pos.tr.edge1);
	n.v = n.f * dot(ray.dir, n.q);
	if (n.v < 0.0 || n.u + n.v > 1.0)
		return ((t_hit){false});
	n.t = n.f * dot(pos.tr.edge2, n.q);
	if (n.t < EPSILON)
		return ((t_hit){false});
	n.hit.hit = true;
	n.hit.dist = n.t;
	n.hit.point = add(ray.origin, scale(ray.dir, n.hit.dist));
	n.hit.normal = cross(
			subtract(pos.tr.p1, pos.tr.p0), subtract(pos.tr.p2, pos.tr.p0));
	normalize(&n.hit.normal);
	return (n.hit);
}
