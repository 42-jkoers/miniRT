/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   intersect_cylinder.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: jkoers <jkoers@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/05 23:43:16 by jkoers        #+#    #+#                 */
/*   Updated: 2021/02/05 23:43:16 by jkoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "intersect.h"
#include "norm.h"
#include "constants.h"
#include "vector.h"
#include "../lib/libft/include/libft.h"
#include <math.h>

/*
** READABLE
** #include "intersect.h"
**
** #include "constants.h"
** #include "vector.h"
** #include "../lib/libft/include/libft.h"
** #include <math.h>
**
** // Calculate the normal in a point on the surface
** // it is a vertical vector in the bases and a vector
** // having the direction of the vector from the axis to the point
** static t_vec3	normal_in(t_vec3 p, t_cylinder cy)
** {
** 	// Point is on one of the bases
** 	if (p.x < cy.origin.x + cy.radius &&
** 		p.x > cy.origin.x - cy.radius &&
** 		p.z < cy.origin.z + cy.radius &&
** 		p.z > cy.origin.z - cy.radius)
** 	{
** 		if (p.y < cy.origin.y + cy.height + EPSILON &&
** 			p.y > cy.origin.y + cy.height - EPSILON)
** 			return ((t_vec3){0, 1, 0});
** 		if (p.y < cy.origin.y + EPSILON &&
** 			p.y > cy.origin.y - EPSILON)
** 			return ((t_vec3){0, -1, 0});
** 	}
**
** 	// Point is on lateral surface
**  	t_vec3 c0 = (t_vec3){cy.origin.x, p.y, cy.origin.z};
**  	return (unit(subtract(p, c0)));
** }
**
** // Calculate intersection with the base having center c
** // We do this by calculating the intersection with the plane
** // and then checking if the intersection is within the base circle
** static bool		intersect_base(
**	t_ray ray, t_vec3 c, double *t, t_cylinder cy)
** {
** 	t_vec3 normal = normal_in(c, cy);
** 	t_vec3 p0 = vec(ray.origin.x - cy.origin.x, ray.origin.y - cy.origin.y,
** 	ray.origin.z - cy.origin.z);
** 	double A = normal.x;
** 	double B = normal.y;
** 	double C = normal.z;
** 	double D = - (A * (c.x - cy.origin.x) + B * (c.y - cy.origin.y) + C *
** 	(c.z - cy.origin.z));
**
** 	if (A * ray.dir.x + B * ray.dir.y + C * ray.dir.z == 0.0)
** 		return (false);
** 	double dist = -(A * p0.x + B * p0.y + C * p0.z + D) / (A * ray.dir.x + B *
** 	ray.dir.y + C * ray.dir.z);
** 	if (dist < EPSILON)
** 		return false;
**
** 	t_vec3 p;
** 	p.x = p0.x + dist * ray.dir.x;
** 	p.y = p0.y + dist * ray.dir.y;
** 	p.z = p0.z + dist * ray.dir.z;
** 	if (p.x * p.x + p.z * p.z - cy.radius * cy.radius > EPSILON)
** 		return (false);
** 	*t = dist;
** 	return (true);
** }
**
** // Find intersection with infinite cylinder with center in the origin
** // to do that, translate the ray origin so that the center of the bottom base
** // is at the origin, then calculate intersection with the canonical infinite
** 	cylinder
** // and check if the ray intersects the lateral surface of the cylinder within
** 	our
** // bases, if not check if it's intersecting the bases and if not, it's not
** 	intersecting
** // our actual cylinder
** static bool		intersect_cy(double *t, t_ray ray, t_cylinder cy)
** {
** 	// coefficients for the intersection equation
** 	// got them mathematically intersecting the line equation with the cylinder
** 	equation
** 	const double a = ray.dir.x * ray.dir.x + ray.dir.z * ray.dir.z;
** 	const double b = ray.dir.x * ray.origin.x + ray.dir.z * ray.origin.z;
** 	const double c = ray.origin.x * ray.origin.x + ray.origin.z * ray.origin.z -
** 	 cy.radius * cy.radius;
** 	const double delta = b * b - a * c;
**
** 	if (delta < EPSILON)
** 		return (false);
** 	*t = (-b - sqrt(delta)) / a;
** 	if (*t <= EPSILON)
** 		return (false); // intersection is behind the ray origin
**
** 	double y = ray.origin.y + *t * ray.dir.y;
** 	// check if we intersect one of the bases
** 	if (y > cy.height + EPSILON || y < -EPSILON) {
** 		double dist;
** 		bool b1 = intersect_base(ray, cy.origin, &dist, cy);
** 		if (b1)
** 			*t = dist;
** 		bool b2 = intersect_base(ray, cy.origin, &dist, cy);
** 		if (b2 && dist > EPSILON && *t >= dist)
** 			*t = dist;
** 		return (b1 || b2);
** 	}
** 	return (true);
** }
**
** t_hit			hit_cylinder(t_pos pos, t_ray ray)
** {
** 	t_hit	hit;
**
** 	hit.hit = intersect_cy(&hit.dist, ray, pos.cy);
** 	if (!hit.hit)
** 		return ((t_hit){false});
** 	hit.point = translate(ray.origin, ray.dir, hit.dist);
** 	hit.normal = normal_in(hit.point, pos.cy);
** 	return (hit);
** }
*/

static t_vec3	normal_in(t_vec3 p, t_cylinder cy)
{
	if (p.x < cy.origin.x + cy.radius &&
		p.x > cy.origin.x - cy.radius &&
		p.z < cy.origin.z + cy.radius &&
		p.z > cy.origin.z - cy.radius)
	{
		if (p.y < cy.origin.y + cy.height + EPSILON &&
			p.y > cy.origin.y + cy.height - EPSILON)
			return ((t_vec3){0, 1, 0});
		if (p.y < cy.origin.y + EPSILON &&
			p.y > cy.origin.y - EPSILON)
			return ((t_vec3){0, -1, 0});
	}
	return (unit(subtract(p, (t_vec3){cy.origin.x, p.y, cy.origin.z})));
}

static bool		intersect_base(t_ray ray, t_vec3 c, double *t, t_cylinder cy)
{
	t_intersect_base n;

	n.normal = normal_in(c, cy);
	n.p0 = vec(ray.origin.x - cy.origin.x,
		ray.origin.y - cy.origin.y, ray.origin.z - cy.origin.z);
	n.A = n.normal.x;
	n.B = n.normal.y;
	n.C = n.normal.z;
	n.D = -(n.A * (c.x - cy.origin.x) + n.B * (c.y - cy.origin.y) + n.C *
		(c.z - cy.origin.z));
	if (n.A * ray.dir.x + n.B * ray.dir.y + n.C * ray.dir.z == 0.0)
		return (false);
	n.dist = -(n.A * n.p0.x + n.B * n.p0.y + n.C * n.p0.z + n.D) /
		(n.A * ray.dir.x + n.B * ray.dir.y + n.C * ray.dir.z);
	if (n.dist < EPSILON)
		return (false);
	n.p.x = n.p0.x + n.dist * ray.dir.x;
	n.p.y = n.p0.y + n.dist * ray.dir.y;
	n.p.z = n.p0.z + n.dist * ray.dir.z;
	if (n.p.x * n.p.x + n.p.z * n.p.z - cy.radius * cy.radius > EPSILON)
		return (false);
	*t = n.dist;
	return (true);
}

static bool		intersect_cy(double *t, t_ray ray, t_cylinder cy)
{
	t_intersect_cy n;

	n.a = ray.dir.x * ray.dir.x + ray.dir.z * ray.dir.z;
	n.b = ray.dir.x * ray.origin.x + ray.dir.z * ray.origin.z;
	n.c = ray.origin.x * ray.origin.x + ray.origin.z *
		ray.origin.z - cy.radius * cy.radius;
	n.delta = n.b * n.b - n.a * n.c;
	if (n.delta < EPSILON)
		return (false);
	*t = (-n.b - sqrt(n.delta)) / n.a;
	if (*t <= EPSILON)
		return (false);
	n.y = ray.origin.y + *t * ray.dir.y;
	if (n.y > cy.height + EPSILON || n.y < -EPSILON)
	{
		n.b1 = intersect_base(ray, cy.origin, &n.dist, cy);
		if (n.b1)
			*t = n.dist;
		n.b2 = intersect_base(ray, cy.origin, &n.dist, cy);
		if (n.b2 && n.dist > EPSILON && *t >= n.dist)
			*t = n.dist;
		return (n.b1 || n.b2);
	}
	return (true);
}

t_hit			hit_cylinder(t_pos pos, t_ray ray)
{
	t_hit	hit;

	hit.hit = intersect_cy(&hit.dist, ray, pos.cy);
	if (!hit.hit)
		return ((t_hit){false});
	hit.point = translate(ray.origin, ray.dir, hit.dist);
	hit.normal = normal_in(hit.point, pos.cy);
	return (hit);
}
