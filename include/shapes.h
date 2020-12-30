/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   shapes.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jkoers <jkoers@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/27 20:56:20 by jkoers        #+#    #+#                 */
/*   Updated: 2020/12/30 17:29:29 by jkoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHAPES_H
# define SHAPES_H

# include "rt_file_helpers.h"

typedef struct	s_orientation
{
	double			x;
	double			y;
	double			z;
}				t_orientation;

/*
** Shapes
*/
typedef enum
{
	SHAPE_SPHERE,
	SHAPE_PLANE,
	SHAPE_SQUARE,
	SHAPE_CYLINDER,
	SHAPE_TRIANGLE
}	e_shape;

typedef struct		s_sphere
{
	e_shape			shape;
	t_rgb			color;
	t_point			origin;
	double			diameter;
}					t_sphere;
e_msg	add_sphere(t_arr_voidp *shapes, char *line);

typedef struct		s_plane
{
	e_shape			shape;
	t_rgb			color;
	t_point			origin;
	t_orientation	orientation;
}					t_plane;

typedef struct		s_square
{
	e_shape			shape;
	t_rgb			color;
	t_point			origin;
	t_orientation	orientation;
	double			side_size;
}					t_square;

typedef struct		s_cylinder
{
	e_shape			shape;
	t_rgb			color;
	t_point			origin;
	t_orientation	orientation;
	double			diameter;
	double			height;
}					t_cylinder;

typedef struct		s_triangle
{
	e_shape			shape;
	t_rgb			color;
	t_point			p1;
	t_point			p2;
	t_point			p3;
}					t_triangle;

#endif
