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

extern t_hit (*g_hit_shape[SHAPE_LAST])(t_pos, t_ray);

t_ray	ray_from_pix(double x, double y, const t_gui *gui);
double	relative_intensity(t_vec3 point, t_vec3 normal, const t_light *light);
void	apply_scalar(t_rgb *color, t_rgb scalar, double intensity);
t_rgb	shadow(const t_gui *gui);

void	render(t_gui *gui);

#endif
