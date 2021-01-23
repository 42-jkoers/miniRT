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

static bool	distance_triangle(double *distance, t_pos pos, t_ray ray)
{
	static const double EPSILON = 1e-8;
	t_vec3 edge1, edge2, h, s, q;
	double a, f, u, v;
	edge1 = subtract(pos.tr.p2, pos.tr.p1);
	edge2 = subtract(pos.tr.p3, pos.tr.p1);
	h = cross(ray.direction, edge2);
	a = dot(edge1, h);
	if (a > -EPSILON && a < EPSILON)
		return (false); // Ray is parallel to this triangle.
	f = 1.0 / a;
	s = subtract(ray.origin, pos.tr.p1);
	u = f * dot(s, h);
	if (u < 0.0 || u > 1.0)
		return (false);
	q = cross(s, edge1);
	v = f * dot(ray.direction, q);

	if (v < 0.0 || u + v > 1.0)
		return (false);
	double t = f * dot(edge2, q);
	if (t < EPSILON) // There is a line intersection but not a ray intersection
		return (false);
	// outIntersectionPoint = rayOrigin + rayVector * t;
	*distance = length(scale(ray.direction, t));
	return (true);
}

static bool distance_plane(double *distance, t_pos pos, t_ray ray)
{
 	double	denom;
	double	t;
    t_vec3	p0l0;

	denom = dot(pos.pl.normal, ray.direction); 
	if (denom < 1e-6) // how small?
		return (false);
	p0l0 = subtract(pos.pl.origin, ray.origin); 
	t = dot(p0l0, pos.pl.normal) / denom;
	if (t < 0.0)
		return (false);
	*distance = t;
	return (true); 
}

static bool	distance_sphere(double *distance, t_pos pos, t_ray ray)
{
	t_vec3	l;		// distance sphere ray
	double	tca;	// distance sphere ray on ray direction
	double	d2;		// distance from center sp to ray squared
	double	thc;

	l = subtract(pos.sp.origin, ray.origin);
	tca = dot(l, ray.direction);
	if (tca < 0)
		return (false);	// sphere is behind ray origin 
	d2 = dot(l, l) - tca * tca; 
	if (d2 > pos.sp.radius2)
		return (false);	// sphere is too small to intersect with ray
	thc = sqrt(pos.sp.radius2 - d2); 
	*distance = tca - thc;
	return (true);
}

bool (*g_distance[SHAPE_LAST])(double *, t_pos, t_ray) = {
	[SHAPE_SPHERE] = distance_sphere,
	[SHAPE_TRIANGLE] = distance_triangle,
	[SHAPE_PLANE] = distance_plane,
};
