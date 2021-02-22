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
# include <pthread.h>

typedef struct s_job
{
	pthread_t		tid;
	unsigned int	start_y;
	unsigned int	num_rows;
	t_gui			*gui;
}				t_job;

t_rgb			compute_color(unsigned int x, unsigned int y, const t_gui *gui);
t_ray			ray_from_pix(double x, double y, const t_gui *gui);
double			relative_intensity(
					t_vec3 p, t_vec3 n, bool is2d, const t_light *light);

t_rgb			ray_to_color(t_ray ray, const t_gui *gui);

t_rgb			shadow(const t_gui *gui);

t_rgb			rgb(unsigned char r, unsigned char g, unsigned char b);
t_rgb			add_color(t_rgb color, t_rgb additive, double intensity);
t_rgb			multiply_color(t_rgb color, t_rgb multication);

void			render(t_gui *gui);

#endif
