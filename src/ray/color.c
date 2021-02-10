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
#include <stdio.h>

double	relative_intensity(t_vec3 point, t_vec3 normal, const t_light *light)
{
	t_vec3	to_light;
	double	intensity;

	to_light = unit(subtract(light->origin, point));
	intensity = 1 * light->brightness * fmax(0.0, dot(normal, to_light));
	intensity = fmin(intensity, 1.0);
	return (intensity);
}

t_rgb	add_color(t_rgb color, t_rgb additive, double intensity)
{
	const double	r = color.r + ((double)additive.r * intensity);
	const double	g = color.g + ((double)additive.g * intensity);
	const double	b = color.b + ((double)additive.b * intensity);
	t_rgb			new;

	new.r = (unsigned char)round(fmin(r, 255.0));
	new.g = (unsigned char)round(fmin(g, 255.0));
	new.b = (unsigned char)round(fmin(b, 255.0));
	return (new);
}

t_rgb	multiply_color(t_rgb color, t_rgb multication)
{
	const double	r = color.r * ((double)multication.r / 255.0);
	const double	g = color.g * ((double)multication.g / 255.0);
	const double	b = color.b * ((double)multication.b / 255.0);
	t_rgb			new;

	new.r = (unsigned char)round(fmin(r, 255.0));
	new.g = (unsigned char)round(fmin(g, 255.0));
	new.b = (unsigned char)round(fmin(b, 255.0));
	return (new);
}

t_rgb	rgb(unsigned char r, unsigned char g, unsigned char b)
{
	return ((t_rgb){r, g, b});
}

t_rgb	shadow(const t_gui *gui)
{
	t_rgb	color;

	color = rgb(0, 0, 0);
	color = add_color(color, gui->ambient.color, gui->ambient.brightness);
	return (color);
}
