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
