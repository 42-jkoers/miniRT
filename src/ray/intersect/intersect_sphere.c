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

t_vec3	normal_sp(t_sphere sp, t_vec3 hitpoint, t_ray ray)
{
	t_vec3	normal;

	normal = unit(subtract(hitpoint, sp.origin));
	if (distance2(ray.origin, sp.origin) < sp.radius2)
		normal = scale(normal, -1);
	return (normal);
}

t_hit	hit_sphere(t_pos pos, t_ray ray)
{
	t_vec3	l;
	double	tca;
	double	d2;
	double	thc;
	t_hit	hit;

	l = subtract(pos.sp.origin, ray.origin);
	tca = fabs(dot(l, ray.dir));
	d2 = dot(l, l) - tca * tca;
	if (d2 > pos.sp.radius2)
		return ((t_hit){false});
	thc = sqrt(pos.sp.radius2 - d2);
	hit.hit = true;
	hit.dist = tca - thc;
	hit.point = translate(ray.origin, ray.dir, hit.dist);
	hit.normal = normal_sp(pos.sp, hit.point, ray);
	return (hit);
}
