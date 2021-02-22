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

double	relative_intensity(t_vec3 p, t_vec3 n, bool is2d, const t_light *light)
{
	t_vec3	to_light;
	double	intensity;

	to_light = unit(subtract(light->origin, p));
	if (is2d)
		intensity = 1 * light->brightness * fabs(dot(n, to_light));
	else
		intensity = 1 * light->brightness * fmax(0.0, dot(n, to_light));
	intensity = fmin(intensity, 1.0);
	return (intensity);
}

t_rgb	add_color(t_rgb color, t_rgb additive, double intensity)
{
	double	r;
	double	g;
	double	b;
	t_rgb	new;

	r = color.r + ((double)additive.r * intensity);
	g = color.g + ((double)additive.g * intensity);
	b = color.b + ((double)additive.b * intensity);
	new.r = (unsigned char)round(fmin(r, 255.0));
	new.g = (unsigned char)round(fmin(g, 255.0));
	new.b = (unsigned char)round(fmin(b, 255.0));
	return (new);
}

t_rgb	multiply_color(t_rgb color, t_rgb multication)
{
	double	r;
	double	g;
	double	b;

	r = color.r * ((double)multication.r / 255.0);
	g = color.g * ((double)multication.g / 255.0);
	b = color.b * ((double)multication.b / 255.0);
	return ((t_rgb){round(r), round(g), round(b)});
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
