/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jkoers <jkoers@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/08 15:58:29 by jkoers        #+#    #+#                 */
/*   Updated: 2021/01/18 13:59:15 by jkoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# include "constants.h"

double	length(t_vec3 v);
double	dot(t_vec3 a, t_vec3 b);
t_vec3	cross(t_vec3 a, t_vec3 b);
t_vec3	add(t_vec3 a, t_vec3 b);
t_vec3	subtract(t_vec3 a, t_vec3 b);
t_vec3	scale(t_vec3 v, double r);
t_vec3	unit(t_vec3 v);
t_vec3	translate(t_vec3 origin, t_vec3 dir, double t);
double	distance2(t_vec3 a, t_vec3 b);
double	distance(t_vec3 a, t_vec3 b);
t_vec3	project_on_line(t_vec3 p, t_vec3 line0, t_vec3 line1);

typedef union u_rsqrt
{
	double		f;
	uint64_t	i;
}	t_rsqrt;

void	normalize(t_vec3 *v);

#endif
