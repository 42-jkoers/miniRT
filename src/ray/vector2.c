/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector2.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jkoers <jkoers@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/08 15:59:04 by jkoers        #+#    #+#                 */
/*   Updated: 2021/01/18 13:59:11 by jkoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "constants.h"
#include <math.h>

// = a - b || to, from

t_vec3	subtract(t_vec3 a, t_vec3 b)
{
	t_vec3	v;

	v.x = a.x - b.x;
	v.y = a.y - b.y;
	v.z = a.z - b.z;
	return (v);
}

t_vec3	scale(t_vec3 v, double r)
{
	t_vec3	vec;

	vec.x = v.x * r;
	vec.y = v.y * r;
	vec.z = v.z * r;
	return (vec);
}

// Get point t distance away from origin in direction of (normalized) dir

t_vec3	translate(t_vec3 origin, t_vec3 dir, double t)
{
	return (add(origin, scale(dir, t)));
}

// The (always positive) squared distance between a and b

double	distance2(t_vec3 a, t_vec3 b)
{
	t_vec3	ab;

	ab = subtract(a, b);
	return (ab.x * ab.x + ab.y * ab.y + ab.z * ab.z);
}

// The (always positive) distance between a and b

double	distance(t_vec3 a, t_vec3 b)
{
	return (sqrt(distance2(a, b)));
}
