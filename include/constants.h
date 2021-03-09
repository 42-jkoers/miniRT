/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   constants.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jkoers <jkoers@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/21 19:27:08 by jkoers        #+#    #+#                 */
/*   Updated: 2021/01/12 14:18:13 by jkoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONSTANTS_H
# define CONSTANTS_H

# include "../lib/libft/include/libft.h"
# include "../settings.h"
# include <stdbool.h>
# include <sys/types.h>

# define DOUBLE_MAX	9999999999.0
# define DOUBLE_MIN	-9999999999.0
# define EPSILON	(1e-7)

# ifdef linux
#  define IS_LINUX 1
#  define KEY_ESC 65307
#  define NEXT_CAMERA_KEY 99
# else
#  define IS_LINUX 0
#  define KEY_ESC 53
#  define NEXT_CAMERA_KEY 8
# endif

void	exit_e(const char *msg);
void	exit_range(long num, long min, long max);
void	exit_ranged(double num, double min, double max);
void	exit_char(char got, char expected);
void	*malloc_safe(size_t size);
void	*calloc_safe(size_t size);

typedef enum e_shape
{
	SHAPE_SPHERE,
	SHAPE_PLANE,
	SHAPE_SQUARE,
	SHAPE_CYLINDER,
	SHAPE_TRIANGLE,
	SHAPE_LAST
}	t_shape;

typedef enum e_rule
{
	RULE_SPHERE,
	RULE_PLANE,
	RULE_SQUARE,
	RULE_CYLINDER,
	RULE_TRIANGLE,
	RULE_RESOLUTION,
	RULE_AMBIENT,
	RULE_CAMERA,
	RULE_LIGHT,
	RULE_LAST
}	t_rule;

char	*rule_id(t_rule i);
char	*rule_name(t_rule i);
char	*line_error(char *line);

typedef struct s_rgb
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
}					t_rgb;

typedef struct s_vec3
{
	double			x;
	double			y;
	double			z;
}					t_vec3;

typedef struct s_ray
{
	t_vec3			origin;
	t_vec3			dir;
}					t_ray;

typedef struct s_canvas
{
	void			*mlx_img;
	char			*data;
	int				bpp;
	int				line_length;
	int				byte_order;
}					t_canvas;

typedef struct s_ambient
{
	double			brightness;
	t_rgb			color;
	t_rgb			scalar;
}					t_ambient;

typedef struct s_camera
{
	t_vec3			origin;
	t_vec3			dir;
	double			fov;
}					t_camera;

typedef struct s_light
{
	t_vec3			origin;
	double			brightness;
	t_rgb			color;
}					t_light;

typedef struct s_gui
{
	t_arr			*shapes;
	t_arr			*lights;
	t_arr			*cameras;
	size_t			camera_i;
	t_ambient		ambient;
	unsigned int	x_size;
	unsigned int	y_size;
	t_camera		camera;
	unsigned int	row_to_render;

	void			*mlx;
	void			*window;
	t_canvas		canvas;
}					t_gui;

typedef struct s_cylinder
{
	t_vec3			origin;
	t_vec3			base2;
	t_vec3			dir;
	double			radius;
	double			height;
}					t_cylinder;

typedef struct s_plane
{
	t_vec3			origin;
	t_vec3			normal;
}					t_plane;

typedef struct s_sphere
{
	t_vec3			origin;
	double			radius;
	double			radius2;
}					t_sphere;

typedef struct s_triangle
{
	t_vec3			p0;
	t_vec3			p1;
	t_vec3			p2;
	t_vec3			edge1;
	t_vec3			edge2;
	t_vec3			normal;
}					t_triangle;

typedef union u_pos
{
	t_cylinder		cy;
	t_plane			pl;
	t_sphere		sp;
	t_triangle		tr;
}	t_pos;

typedef struct s_obj
{
	t_shape			shape;
	t_rgb			color;
	t_pos			pos;
}					t_obj;

typedef struct s_hit
{
	bool			hit;
	double			dist;
	t_vec3			point;
	t_vec3			normal;
}					t_hit;

typedef struct s_bounce
{
	t_obj			*obj;
	t_rgb			color;
	t_vec3			point;
	t_vec3			normal;
	t_vec3			ray_origin;
}					t_bounce;

#endif
