/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   shapes.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jkoers <jkoers@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/27 20:56:20 by jkoers        #+#    #+#                 */
/*   Updated: 2021/01/02 23:18:04 by jkoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHAPES_H
# define SHAPES_H

# include "rt_file_helpers.h"
# include "constants.h"
# include "../lib/libft/include/libft.h"

void	log_shapes(t_arr_voidp *shapes);

typedef struct		s_sphere
{
	e_shape			shape;
	t_rgb			color;
	t_point			origin;
	double			diameter;
}					t_sphere;
e_msg				add_sphere(char *line, t_arr_voidp **shapes);

typedef struct		s_plane
{
	e_shape			shape;
	t_rgb			color;
	t_point			origin;
	t_point			orientation;
}					t_plane;
e_msg				add_plane(char *line, t_arr_voidp **shapes);

typedef struct		s_square
{
	e_shape			shape;
	t_rgb			color;
	t_point			origin;
	t_point			orientation;
	double			size;
}					t_square;
e_msg				add_square(char *line, t_arr_voidp **shapes);

typedef struct		s_cylinder
{
	e_shape			shape;
	t_rgb			color;
	t_point			origin;
	t_point			orientation;
	double			diameter;
	double			height;
}					t_cylinder;
e_msg				add_cylinder(char *line, t_arr_voidp **shapes);

typedef struct		s_triangle
{
	e_shape			shape;
	t_rgb			color;
	t_point			p1;
	t_point			p2;
	t_point			p3;
}					t_triangle;
e_msg				add_triangle(char *line, t_arr_voidp **shapes);

#endif
