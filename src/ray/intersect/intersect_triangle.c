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

#include "intersect.h"

#include "constants.h"
#include "vector.h"
#include "../lib/libft/include/libft.h"
#include <math.h>

t_hit	hit_triangle(t_pos pos, t_ray ray)
{
	t_vec3 edge1, edge2, h, s, q;
	double a, f, u, v;
	edge1 = subtract(pos.tr.p2, pos.tr.p1);
	edge2 = subtract(pos.tr.p3, pos.tr.p1);
	h = cross(ray.dir, edge2);
	a = dot(edge1, h);
	if (a > -EPSILON && a < EPSILON)
		return ((t_hit){false}); // Ray is parallel to this triangle.
	f = 1.0 / a;
	s = subtract(ray.origin, pos.tr.p1);
	u = f * dot(s, h);
	if (u < 0.0 || u > 1.0)
		return ((t_hit){false});
	q = cross(s, edge1);
	v = f * dot(ray.dir, q);

	if (v < 0.0 || u + v > 1.0)
		return ((t_hit){false});
	double t = f * dot(edge2, q);
	if (t < EPSILON) // There is a line intersection but not a ray intersection
		return ((t_hit){false});

	t_hit	hit;
	hit.hit = true;
	hit.dist = length(scale(ray.dir, t));
	hit.point = scale(ray.origin, hit.dist); // outIntersectionPoint = rayOrigin + rayVector * t;
	hit.normal = cross(subtract(pos.tr.p2, pos.tr.p1), subtract(pos.tr.p3, pos.tr.p1)); // N = (v1-v0).crossProduct(v2-v0);
	return (hit);
}
