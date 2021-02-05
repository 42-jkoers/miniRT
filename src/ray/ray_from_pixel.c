/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ray_from_pixel.c                                   :+:    :+:            */
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

t_ray		ray_from_pix(double x, double y, const t_gui *gui)
{
	const double fov_scale = tan(gui->camera.fov * 0.5);
	const double aspect_ratio = (double)gui->x_size / (double)gui->y_size;
	const double px = (2 * (x + 0.5) / (double)gui->x_size - 1) * aspect_ratio * fov_scale;
	const double py = (2 * (y + 0.5) / (double)gui->y_size - 1) * fov_scale;

	t_ray	ray;
	ray.origin = gui->camera.origin;
	t_vec3 positive_x;
	if (gui->camera.dir.x == 0.0 && gui->camera.dir.z == 0.0)
		positive_x = vec(1.0, 0.0, 0.0);
	else
		positive_x = cross(gui->camera.dir, vec(0.0, 1.0, 0.0));
	t_vec3 negative_y = cross(gui->camera.dir, positive_x);
	t_vec3 scaled_x = scale(positive_x, px);
	t_vec3 scaled_y = scale(negative_y, py);
	ray.dir = add(add(scaled_x, scaled_y), gui->camera.dir);
	normalize(&ray.dir);
	return (ray);
}
