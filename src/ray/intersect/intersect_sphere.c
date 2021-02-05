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
#include "../lib/libft/include/libft.h"
#include <math.h>

t_hit	hit_sphere(t_pos pos, t_ray ray)
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
