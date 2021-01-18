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

t_vec3	vec(double x, double y, double z);
double	length(t_vec3 v); // also magnitude
double	dot(t_vec3 a, t_vec3 b);
double	angle(t_vec3 a, t_vec3 b);
t_vec3	cross(t_vec3 a, t_vec3 b);
t_vec3	add(t_vec3 a, t_vec3 b);
t_vec3	subtract(t_vec3 a, t_vec3 b); // a - b
t_vec3	scale(t_vec3 v, double r);

void	normalize(t_vec3 *v);

void	log_vec3(char *id, t_vec3 v);

#endif
