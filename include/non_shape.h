/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   non_shape.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jkoers <jkoers@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/05 20:21:31 by jkoers        #+#    #+#                 */
/*   Updated: 2021/01/06 00:30:01 by jkoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef NON_SHAPE_H
# define NON_SHAPE_H

# include "gui.h"
# include "constants.h"

void	add_camera(t_arr_voidp **cameras, char *line);
void	add_light(t_arr_voidp **lights, char *line);
void	set_resolution(unsigned long *x, unsigned long *y, char *line);
void	set_ambient(t_ambient *ambient, char *line);
void	set_camera_distance_canvas(t_arr_voidp *cameras, t_gui *gui);
void	set_size(double *x_size, double *y_size, t_gui *gui);

#endif
