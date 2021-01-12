/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jkoers <jkoers@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/08 15:59:04 by jkoers        #+#    #+#                 */
/*   Updated: 2021/01/09 00:52:02 by jkoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "constants.h"
#include <math.h>

t_vec3	vec(double x, double y, double z)
{
	t_vec3 v;

	v.x = x;
	v.y = y;
	v.z = z;
	return (v);
}

double	length(t_vec3 v) // also magnitude
{
	return (sqrt(v.x * v.x + v.y * v.y + v.z * v.z));
}

double	dot(t_vec3 a, t_vec3 b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

double	angle(t_vec3 a, t_vec3 b)
{
	return (acos(dot(a, b)));
}

t_vec3	cross(t_vec3 a, t_vec3 b)
{
	t_vec3 cross;
	
	cross.x = a.y * b.z - a.z * b.y;
	cross.y = a.z * b.x - a.x * b.z;
	cross.z = a.x * b.y - a.y * b.x;
	return (cross);
}

t_vec3	add(t_vec3 a, t_vec3 b)
{
	t_vec3	v;

	v.x = a.x + b.x;
	v.y = a.y + b.y;
	v.z = a.z + b.z;
	return (v);
}

t_vec3	subtract(t_vec3 a, t_vec3 b) // a - b
{
	t_vec3	v;

	v.x = a.x - b.x;
	v.y = a.y - b.y;
	v.z = a.z - b.z;
	return (v);
}

t_vec3	multiply(t_vec3 v, double r)
{
	t_vec3	vec;

	vec.x = v.x * r;
	vec.y = v.y * r;
	vec.z = v.z * r;
	return (vec);
}

void	normalize(t_vec3 *v)
{
	double len;
	
	len = length(*v);
	if (len != 0.0)
	{
		v->x /= len;
		v->y /= len;
		v->z /= len;
	}
}

#include <stdio.h>
void	log_vec3(char *id, t_vec3 v)
{
	printf("%-10sx: %lf\n", id, v.x);
	printf("          y: %lf\n", v.y);
	printf("          z: %lf\n\n", v.z);
}
