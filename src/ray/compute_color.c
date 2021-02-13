/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   compute_color.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jkoers <jkoers@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/12 16:15:37 by jkoers        #+#    #+#                 */
/*   Updated: 2021/02/12 16:15:37 by jkoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include "intersect.h"
#include "constants.h"
#include "vector.h"
#include <math.h>

static t_rgb	compute_color_no_aa(unsigned x, unsigned y, const t_gui *gui)
{
	t_ray		camera_ray;

	camera_ray = ray_from_pix(x, y, gui);
	return (ray_to_color(camera_ray, gui));
}

static t_rgb	add_colors(const t_rgb *colors, unsigned n)
{
	double		r;
	double		g;
	double		b;
	unsigned	i;

	r = 0.0;
	g = 0.0;
	b = 0.0;
	i = 0;
	while (i < n)
	{
		r += colors[i].r;
		g += colors[i].g;
		b += colors[i].b;
		i++;
	}
	r /= n;
	g /= n;
	b /= n;
	return (rgb(round(r), round(g), round(b)));
}

t_rgb			compute_color(unsigned x, unsigned y, const t_gui *gui)
{
	const double	aa = 1.0 / sqrt(ANTI_ALIASING_LEVEL);
	double			x_off;
	double			y_off;
	t_rgb			colors[ANTI_ALIASING_LEVEL];
	size_t			i;

	if (DISABLE_ANTI_ALIASING)
		return (compute_color_no_aa(x, y, gui));
	i = 0;
	y_off = EPSILON;
	while (y_off < 1.0 && i < ANTI_ALIASING_LEVEL)
	{
		x_off = EPSILON;
		while (x_off < 1.0 && i < ANTI_ALIASING_LEVEL)
		{
			colors[i] =
				ray_to_color(ray_from_pix(x + x_off, y + y_off, gui), gui);
			i++;
			x_off += aa;
		}
		y_off += aa;
	}
	return (add_colors(colors, ANTI_ALIASING_LEVEL));
}
