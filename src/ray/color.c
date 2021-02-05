/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   color.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jkoers <jkoers@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/05 16:45:24 by jkoers        #+#    #+#                 */
/*   Updated: 2021/02/05 16:45:24 by jkoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include "constants.h"
#include "vector.h"
#include <math.h>

double	relative_intensity(t_vec3 point, t_vec3 normal, const t_light *light)
{
	t_vec3	to_light;
	double	intensity;

	to_light = unit(subtract(light->origin, point));
	intensity = 1 * light->brightness * max_dbl(0.0, dot(normal, to_light));
	intensity = min_dbl(intensity, 1.0);
	return (intensity);
}

void	apply_scalar(t_rgb *color, t_rgb scalar, double intensity)
{
	const double	inv_intensity = 1.0 - intensity;
    const double	r = (scalar.r * intensity) + color->r * inv_intensity;
    const double	g = (scalar.g * intensity) + color->g * inv_intensity;
    const double	b = (scalar.b * intensity) + color->b * inv_intensity;

	color->r = (unsigned char)round(r);
	color->g = (unsigned char)round(g);
	color->b = (unsigned char)round(b);
}

t_rgb	shadow(const t_gui *gui)
{
	t_rgb	color;

	color = (t_rgb){0, 0, 0};
	apply_scalar(&color, gui->ambient.color, gui->ambient.brightness);
	return (color);
}
