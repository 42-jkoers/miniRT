/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ray.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: jkoers <jkoers@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/05 13:18:30 by jkoers        #+#    #+#                 */
/*   Updated: 2021/01/17 13:04:47 by jkoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include "gui.h"

#include "constants.h"
#include "vector.h"
#include "../lib/minilibx-linux/mlx.h"
#include "../lib/ft_printf/ft_printf.h"
#include "../lib/libft/include/libft.h"
#include <math.h>

/*
void set_ray(t_ray *ray, double x, double y, t_gui *gui)
{
	// t_ray ray;
	
	// double	ndc_x;			// [0,1]   Normalized Device Coordinates
	// double	ndc_y;			// [0,1]   Normalized Device Coordinates
	// double	pixelscreen_x;	// [-1, 1] screen space
	// double	pixelscreen_y;	// [-1, 1] screen space
	// double	pixelcamera_x;	// [-aspect_ratio, aspect_radio]
	// double	pixelcamera_y;	// [-aspect_ratio, aspect_radio] 

	// double aspect_ratio;

	// ndc_x = (x + 0.5) / gui->x_size;
	// ndc_y = (y + 0.5) / gui->y_size;
	
	// pixelscreen_x = 2.0 * ndc_x - 1;
	// pixelscreen_y = 1 - 2 * ndc_y;
	
	// aspect_ratio = gui->x_size / gui->y_size;
	// pixelcamera_x = (2.0 * pixelscreen_x - 1) * aspect_ratio * tan(gui->camera->fov / 2);
	// pixelcamera_y = 1 - 2 * pixelscreen_y * tan(gui->camera->fov / 2);

	// return (ray);
}
*/

void	set_ray(t_ray *ray, double x, double y, t_gui *gui)
{
	double	aspect_ratio;
	double	Px;
	double	Py;

	aspect_ratio = gui->x_size / gui->y_size; // assuming width >= height 
	Px = (2 * ((x + 0.5) / gui->x_size) - 1) * tan(gui->camera->fov / 2) * aspect_ratio;
	Py = 1 - 2 * ((y + 0.5) / gui->y_size) * tan(gui->camera->fov / 2);
	ray->origin = gui->camera->origin;
	ray->direction = subtract(vec(Px, Py, -1.0), ray->origin);
	normalize(&ray->direction);
}


// void	set_ray(t_ray *ray, double x, double y, t_gui *gui)
// {
// 	double cam_canvas_dist = (gui->x_size / 2) / tan(gui->camera->fov / 2);
	
// 	ray->origin = gui->camera->origin;
// 	ray->direction.x = gui->camera->origin.x + cam_canvas_dist;
// 	ray->direction.y = (gui->camera->origin.y + gui->y_size / 2) - x;
// 	ray->direction.z = (gui->camera->origin.x + gui->x_size / 2) - y;

// 	ray->direction = subtract(ray->direction, ray->origin);
// 	normalize(&ray->direction);
// }

bool	distance_sphere(double *distance,
		t_sphere sp, t_ray ray) // distance to surface of sphere
{
	t_vec3	l;		// distance sphere ray
	double	tca;	// distance sphere ray on ray direction
	double	d2;		// distance from center sp to ray squared
	double	thc;

	l = subtract(sp.origin, ray.origin);
	tca = dot(l, ray.direction);
	if (tca < 0)
		return (false);	// sphere is behind ray origin 
	d2 = dot(l, l) - tca * tca; 
	if (d2 > sp.radius2)
		return (false);	// sphere is too small to intersect with ray
	thc = sqrt(sp.radius2 - d2); 
	*distance = tca - thc;
	return (true);
}

/*
** @return if shape intersects
** @param *dist distance to shape if there is an intersection
*/
bool	intersects(double *dist,
	t_ray ray, t_shape shape, const void *s)
{
	if (shape == SHAPE_SPHERE)
		return (distance_sphere(dist, *((t_sphere *)s), ray));
}

void	compute_pixel(t_rgb *color,
			t_ray ray, t_gui *gui)
{
	size_t	i;
	double	closest;
	double	dist;
	t_shape	shape;
	void	*closest_shape;

	i = 0;
	closest = 999999999999.0;
	closest_shape = NULL;
	while (ft_arr_voidp_get(gui->shapes, i) != NULL)
	{
		ft_memcpy(&shape, ft_arr_voidp_get(gui->shapes, i), sizeof(t_shape));
		if (intersects(&dist, ray, shape, ft_arr_voidp_get(gui->shapes, i)))
			if (dist < closest)
			{
				closest = dist;
				closest_shape = ft_arr_voidp_get(gui->shapes, i);
			}
		i++;
	}
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
