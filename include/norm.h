/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   norm.h                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jkoers <jkoers@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/10 14:48:54 by jkoers        #+#    #+#                 */
/*   Updated: 2021/02/10 14:48:54 by jkoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef NORM_H
# define NORM_H

# include "constants.h"

typedef struct	s_ray_from_pix
{
	double		fov;
	double		aspect_ratio;
	double		px;
	double		py;
	t_ray		ray;
	t_vec3		positive_x;
	t_vec3		negative_y;
	t_vec3		scaled_x;
	t_vec3		scaled_y;
}				t_ray_from_pix;

#endif
