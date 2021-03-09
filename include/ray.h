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

typedef struct s_thread
{
	pthread_t		id;
	t_gui			*gui;
	pthread_mutex_t	*row_to_render_lock;
}				t_thread;

bool			is2d(const t_obj *obj);
t_bounce		get_bounce(const t_arr *shapes, t_ray ray);
bool			is_clear_path(t_bounce from_camera, const t_light *l,
					const t_arr *shapes);
t_rgb			compute_color(unsigned int x, unsigned int y, const t_gui *gui);
t_ray			ray_from_pix(double x, double y, const t_gui *gui);
double			relative_intensity(t_vec3 p, t_vec3 n, const t_light *light);

t_rgb			ray_to_color(t_ray ray, const t_gui *gui);

t_rgb			no_bounce(void);

t_rgb			add_color(t_rgb color, t_rgb additive, double intensity);
t_rgb			multiply_color(t_rgb color, t_rgb multication);

void			render(t_gui *gui);

#endif
