/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   shapes.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jkoers <jkoers@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/27 20:56:20 by jkoers        #+#    #+#                 */
/*   Updated: 2020/12/28 20:47:35 by jkoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHAPES_H
# define SHAPES_H

typedef struct		s_rgb
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
}					t_rgb;

typedef struct	s_orientation
{
	double			x;
	double			y;
	double			z;

}				t_orientation;

typedef struct	s_point
{
	double			x;
	double			y;
	double			z;
}				t_point;
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
void	add_sphere(t_gui *gui, t_arr_voidp *shapes, char *line);

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
