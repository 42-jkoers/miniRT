/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   intersect.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jkoers <jkoers@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/18 13:02:52 by jkoers        #+#    #+#                 */
/*   Updated: 2021/01/18 14:24:14 by jkoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

#include "constants.h"
#include "vector.h"
#include "../lib/minilibx-linux/mlx.h"
#include "../lib/libft/include/libft.h"
#include <math.h>

static t_hit	hit_triangle(t_pos pos, t_ray ray)
{
	static const double EPSILON = 1e-8;
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

static bool distance_plane(double *distance, t_pos pos, t_ray ray)
{
 	double	denom;
	double	t;
    t_vec3	p0l0;

	denom = dot(pos.pl.normal, ray.dir); 
	if (denom < 1e-6) // how small?
		return (false);
	p0l0 = subtract(pos.pl.origin, ray.origin); 
	t = dot(p0l0, pos.pl.normal) / denom;
	if (t < 0.0)
		return (false);
	*distance = t;
	return (true); 
}

static t_hit	hit_sphere(t_pos pos, t_ray ray)
{
	t_vec3	l;		// distance sphere ray
	double	tca;	// distance sphere ray on ray dir
	double	d2;		// distance from center sp to ray squared
	double	thc;
	t_hit	hit;

	l = subtract(pos.sp.origin, ray.origin);
	tca = dot(l, ray.dir);
	if (tca < 0)
		return ((t_hit){false});	// sphere is behind ray origin 
	d2 = dot(l, l) - tca * tca; 
	if (d2 > pos.sp.radius2)
		return ((t_hit){false});	// sphere is too small to intersect with ray
	thc = sqrt(pos.sp.radius2 - d2);
	hit.hit = true;
	hit.dist = tca - thc;
	hit.point = add(ray.origin, scale(ray.dir, hit.dist));
	hit.normal = unit(subtract(hit.point, pos.sp.origin)); // N = P - center;
	return (hit);
}

t_hit (*g_hit_shape[SHAPE_LAST])(t_pos, t_ray) = {
	[SHAPE_SPHERE] = hit_sphere,
	[SHAPE_TRIANGLE] = hit_triangle,
	// [SHAPE_PLANE] = distance_plane,
};
