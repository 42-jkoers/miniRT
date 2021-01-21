/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ray.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: jkoers <jkoers@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/05 13:18:30 by jkoers        #+#    #+#                 */
/*   Updated: 2021/01/18 13:21:18 by jkoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include "gui.h"

#include "constants.h"
#include "vector.h"
#include "../lib/minilibx-linux/mlx.h"
#include "../lib/libft/include/libft.h"
#include <math.h>

void	set_ray_without_rotation(t_ray *ray,
	double x, double y, const t_gui *gui)
{
	const double scale = tan(gui->camera->fov * 0.5);
	// const double scale = (0.5 * gui->x_size) / tan(gui->camera->fov * 0.5);
	const double aspect_ratio = gui->x_size / gui->y_size;
	const double px = (2 * (x + 0.5) / gui->x_size - 1) * aspect_ratio * scale;
	const double py = (1 - 2 * (y + 0.5) / gui->y_size) * scale;

	ray->origin = gui->camera->origin;
	ray->direction = subtract(vec(px, py, -1.0), ray->origin);
	// ray->direction = add(vec(px, py, scale), ray->origin);
	normalize(&ray->direction);
}


void	set_ray(t_ray *ray,
	double x, double y, const t_gui *gui)
{
	const double	aspect_ratio = gui->x_size / gui->y_size;
	const double	half_height = tan(gui->camera->fov * 0.5);
	const double	half_width = aspect_ratio * half_height;
	ray->origin = gui->camera->origin;
	const t_vec3	w = unit(subtract(gui->camera->origin, gui->camera->orientation));
	const t_vec3	vup = vec(0.0, -1.0 , 0.0); // i do not really know
	const t_vec3	u = unit(cross(vup, w));
	const t_vec3	v = cross(w, u);
	
	// t_vec3			lower_left_corner = vec(-half_width, -half_height, -1.0);

	t_vec3			u_scaled = scale(u, half_width);
	t_vec3			v_scaled = scale(v, half_height);
	t_vec3			lower_left_corner = gui->camera->origin;
					lower_left_corner = subtract(lower_left_corner, u_scaled);
					lower_left_corner = subtract(lower_left_corner, v_scaled);
					lower_left_corner = subtract(lower_left_corner, w);
					
	t_vec3			horizontal = scale(u, 2 * half_width);
	t_vec3			vertical =   scale(v, 2 * half_height);
	
	// ray->direction = lower_left_corner + ((x + 0.5) / gui->x_size) * horizontal + ((y + 0.5) / gui->y_size) * vertical - origin;
	t_vec3			horizontal_scaled = scale(horizontal, 1.0 - (x + 0.5) / gui->x_size); // 1.0 - part is correction
	t_vec3			vertical_scaled = scale(vertical, (y + 0.5) / gui->y_size);

	// ray->direction = lower_left_corner + horizontal_scaled + vertical_scaled - origin;
	ray->direction = lower_left_corner;
	ray->direction = add(ray->direction, horizontal_scaled);
	ray->direction = add(ray->direction, vertical_scaled);
	ray->direction = subtract(ray->direction, gui->camera->origin);

	normalize(&ray->direction);
}

/*
** @return if shape intersects
** @param *dist distance to shape if there is an intersection
*/

void	*find_closest_shape(t_ray ray, const t_gui *gui)
{
	size_t	i;
	t_shape	shape;
	double	closest;
	double	dist;
	void	*closest_shape;

	i = 0;
	closest = 999999999999.0;
	closest_shape = NULL;
	while (ft_arr_voidp_get(gui->shapes, i) != NULL)
	{
		ft_memcpy(&shape, ft_arr_voidp_get(gui->shapes, i), sizeof(t_shape));
		if (g_distance[shape](&dist, ft_arr_voidp_get(gui->shapes, i), ray))
			if (dist < closest)
			{// is this neccecary
				closest = dist;
				closest_shape = ft_arr_voidp_get(gui->shapes, i);
			}
		i++;
	}
	return (closest_shape);
}


void	compute_pixel(t_rgb *color,
			t_ray ray, const t_gui *gui)
{
	const void *closest_shape = find_closest_shape(ray, gui);

	if (closest_shape == NULL)
		return (ft_bzero(color, sizeof(t_rgb)));
	ft_memcpy(color, &((t_sphere *)closest_shape)->color, sizeof(t_rgb));
}

void	render(t_gui *gui)
{
	double	x;
	double	y;
	t_rgb	color;
	static	t_ray ray;

	y = 0;
	while (y < gui->y_size)
	{
		x = 0;
		while (x < gui->x_size)
		{
			set_ray(&ray, x, y, gui);
			compute_pixel(&color, ray, gui);
			gui_set_pixel(gui, x, y, color);
			x++;
		}
		y++;
	}
}
