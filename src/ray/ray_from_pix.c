/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ray_from_pix.c                                     :+:    :+:            */
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
#include "norm.h"
#include <math.h>

/*
** READABLE
** #include "ray.h"
** #include "constants.h"
** #include "vector.h"
** #include "norm.h"
** #include <math.h>
**
** t_ray		ray_from_pix(double x, double y, const t_gui *gui)
** {
** 	const double fov = tan(gui->camera.fov * 0.5);
** 	const double aspect_ratio = (double)gui->x_size / (double)gui->y_size;
** 	const double px = (2 * (x + 0.5) / gui->x_size - 1) * aspect_ratio * fov;
** 	const double py = (2 * (y + 0.5) / (double)gui->y_size - 1) * fov_scale;
**
** 	t_ray	ray;
** 	ray.origin = gui->camera.origin;
** 	t_vec3 positive_x;
** 	if (gui->camera.dir.x == 0.0 && gui->camera.dir.z == 0.0)
** 		positive_x = vec(1.0, 0.0, 0.0);
** 	else
** 		positive_x = cross(gui->camera.dir, vec(0.0, 1.0, 0.0));
** 	t_vec3 negative_y = cross(gui->camera.dir, positive_x);
** 	t_vec3 scaled_x = scale(positive_x, px);
** 	t_vec3 scaled_y = scale(negative_y, py);
** 	ray.dir = add(add(scaled_x, scaled_y), gui->camera.dir);
** 	normalize(&ray.dir);
** 	return (ray);
** }
*/

t_ray		ray_from_pix(double x, double y, const t_gui *gui)
{
	t_ray_from_pix n;

	n.fov = tan(gui->camera.fov * 0.5);
	n.aspect_ratio = (double)gui->x_size / (double)gui->y_size;
	n.px = (2 * x / gui->x_size - 1) * n.aspect_ratio * n.fov;
	n.py = (2 * y / (double)gui->y_size - 1) * n.fov;
	n.ray.origin = gui->camera.origin;
	if (gui->camera.dir.x == 0.0 && gui->camera.dir.z == 0.0)
		n.positive_x = vec(1.0, 0.0, 0.0);
	else
		n.positive_x = cross(gui->camera.dir, vec(0.0, 1.0, 0.0));
	n.negative_y = cross(gui->camera.dir, n.positive_x);
	n.scaled_x = scale(n.positive_x, n.px);
	n.scaled_y = scale(n.negative_y, n.py);
	n.ray.dir = add(add(n.scaled_x, n.scaled_y), gui->camera.dir);
	normalize(&n.ray.dir);
	return (n.ray);
}
