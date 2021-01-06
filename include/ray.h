/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ray.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: jkoers <jkoers@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/05 14:57:04 by jkoers        #+#    #+#                 */
/*   Updated: 2021/01/05 18:14:16 by jkoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

#include "rt_file_helpers.h"

typedef struct	s_ray
{
	t_vec3		origin;
	t_vec3		direction;
}				t_ray;

#endif
