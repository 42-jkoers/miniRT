/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector.c                                           :+:    :+:            */
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

t_vec3	vec(double x, double y, double z)
{
	t_vec3	v;

	v.x = x;
	v.y = y;
	v.z = z;
	return (v);
}

double	length(t_vec3 v)
{
	return (sqrt(v.x * v.x + v.y * v.y + v.z * v.z));
}

// @return product of the Euclidean magnitudes of the two vectors
// and the cosine of the angle between them.
// = length(a) * length(b) * cos(alpha)

double	dot(t_vec3 a, t_vec3 b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

// @return vector orthogonal (perpendicular) to a and b

t_vec3	cross(t_vec3 a, t_vec3 b)
{
	t_vec3	v;

	v.x = a.y * b.z - a.z * b.y;
	v.y = a.z * b.x - a.x * b.z;
	v.z = a.x * b.y - a.y * b.x;
	return (v);
}

t_vec3	add(t_vec3 a, t_vec3 b)
{
	t_vec3	v;

	v.x = a.x + b.x;
	v.y = a.y + b.y;
	v.z = a.z + b.z;
	return (v);
}


// see doc/project_on_line.png
// a = p
// b = line0
// c = line1

t_vec3	project_on_line(t_vec3 p, t_vec3 line0, t_vec3 line1)
{
	t_vec3	dir;
	t_vec3	v;
	double	t;
	t_vec3	p_on_line;

	dir = unit(subtract(line1, line0));
	v = subtract(p, line0);
	t = dot(v, dir);
	p_on_line = translate(line0, dir, t);
	return (p_on_line);
}
