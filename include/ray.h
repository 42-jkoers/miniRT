/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ray.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: jkoers <jkoers@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/05 14:57:04 by jkoers        #+#    #+#                 */
/*   Updated: 2021/01/18 13:21:04 by jkoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include "constants.h"

t_hit (*g_hit_shape[SHAPE_LAST])(t_pos, t_ray);

void	render(t_gui *gui);

#endif
