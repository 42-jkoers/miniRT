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
	intensity = 1 * light->brightness * fmax(0.0, dot(normal, to_light));
	return (fmin(intensity, 1.0));
}

t_rgb	add_color(t_rgb color, t_rgb additive, double intensity)
{
	t_rgb	out;

	out.r = round(fmin(color.r + additive.r * intensity, 255.0));
	out.g = round(fmin(color.g + additive.g * intensity, 255.0));
	out.b = round(fmin(color.b + additive.b * intensity, 255.0));
	return (out);
}

t_rgb	mix_color(t_rgb light, t_rgb surface)
{
	t_rgb	out;

	out.r = round(light.r * (surface.r / 255.0));
	out.g = round(light.g * (surface.g / 255.0));
	out.b = round(light.b * (surface.b / 255.0));
	return (out);
}

t_rgb	no_bounce(void)
{
	return ((t_rgb){0, 0, 0});
}
