/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   shapes.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jkoers <jkoers@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/27 20:56:20 by jkoers        #+#    #+#                 */
/*   Updated: 2021/01/05 23:31:52 by jkoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHAPES_H
# define SHAPES_H

# include "rt_file_helpers.h"
# include "constants.h"
# include "../lib/libft/include/libft.h"

void	log_shapes(t_arr_voidp *shapes);
void	add_sphere(t_arr_voidp **shapes, char *line);
void	add_plane(t_arr_voidp **shapes, char *line);
void	add_square(t_arr_voidp **shapes, char *line);
void	add_cylinder(t_arr_voidp **shapes, char *line);
void	add_triangle(t_arr_voidp **shapes, char *line);

#endif
