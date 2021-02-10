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
	t_vec3	l;
	double	tca;
	double	d2;
	double	thc;
	t_hit	hit;

	l = subtract(pos.sp.origin, ray.origin);
	tca = dot(l, ray.dir);
	if (tca < 0.0)
		return ((t_hit){false});
	d2 = dot(l, l) - tca * tca;
	if (d2 > pos.sp.radius2)
		return ((t_hit){false});
	thc = sqrt(pos.sp.radius2 - d2);
	hit.hit = true;
	hit.dist = tca - thc;
	hit.point = add(ray.origin, scale(ray.dir, hit.dist));
	hit.normal = unit(subtract(hit.point, pos.sp.origin));
	return (hit);
}
