/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   intersect.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jkoers <jkoers@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/05 23:43:46 by jkoers        #+#    #+#                 */
/*   Updated: 2021/02/05 23:43:46 by jkoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERSECT_H
# define INTERSECT_H

# include "constants.h"

t_hit	hit_sphere(t_pos pos, t_ray ray);
t_hit	hit_triangle(t_pos pos, t_ray ray);

extern t_hit (*g_hit_shape[SHAPE_LAST])(t_pos, t_ray);

#endif
