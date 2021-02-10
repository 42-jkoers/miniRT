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

/*
** = a - b or to, from
*/

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

void	normalize(t_vec3 *v)
{
	double	len;

	len = length(*v);
	if (len != 0.0)
	{
		v->x /= len;
		v->y /= len;
		v->z /= len;
	}
}

t_vec3	unit(t_vec3 v)
{
	normalize(&v);
	return (v);
}

t_vec3	translate(t_vec3 origin, t_vec3 dir, double t)
{
	return (add(origin, scale(dir, t)));
}
