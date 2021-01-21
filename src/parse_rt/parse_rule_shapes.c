/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_rule_shapes.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: jkoers <jkoers@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/27 20:55:30 by jkoers        #+#    #+#                 */
/*   Updated: 2021/01/12 14:15:10 by jkoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parse_rt.h"
#include "../lib/libft/include/libft.h"
#include "gui.h"
#include "constants.h"
#include "parse_rt.h"
#include <stdlib.h>

/*
** #include <time.h>
** clock_t begin = clock();
** printf("%f s\n", (double)(clock() - begin) / CLOCKS_PER_SEC);
*/

void	add_sphere(t_arr_voidp **shapes, char *line)
{
	t_object	*sp;
	t_sphere	*pos;
	char		**items;

	sp = malloc_safe(sizeof(t_object));
	pos = malloc_safe(sizeof(t_sphere));
	sp->pos = (void *)pos;
	sp->shape = SHAPE_SPHERE;
	items = split_clamp(line, 4);
	set_point(&pos->origin, items[1]);
	pos->radius = strtodbl_clamp(items[2], '\0', 0.0, DOUBLE_MAX);
	pos->radius *= 0.5; // rt rule is with diameter
	pos->radius2 = pos->radius * pos->radius;
	set_color(&sp->color, items[3]);
	ft_free_until_null_char(items);
	sp->pos = pos;
	if (ft_arr_voidp_push(shapes, sp) == NULL)
		exit_e("malloc");
}

void	add_plane(t_arr_voidp **shapes, char *line)
{
	t_object *pl;
	t_plane	*pos;
	char	**items;

	pl = malloc_safe(sizeof(t_object));
	pos = malloc_safe(sizeof(t_plane));
	pl->shape = SHAPE_PLANE;
	items = split_clamp(line, 4);
	set_point(&pos->origin, items[1]);
	set_orientation(&pos->normal, items[2]);
	set_color(&pl->color, items[3]);
	ft_free_until_null_char(items);
	pl->pos = pos;
	if (ft_arr_voidp_push(shapes, pl) == NULL)
		exit_e("malloc");
}

void	add_square(t_arr_voidp **shapes, char *line)
{
	t_object	*sq;
	t_square	*pos;
	char		**items;

	sq = malloc_safe(sizeof(t_object));
	pos = malloc_safe(sizeof(t_square));
	sq->shape = SHAPE_SQUARE;
	items = split_clamp(line, 5);
	set_point(&pos->origin, items[1]);
	set_orientation(&pos->orientation, items[2]);
	pos->size = strtodbl_clamp(items[3], '\0', 0.0, DOUBLE_MAX);
	set_color(&sq->color, items[4]);
	ft_free_until_null_char(items);
	sq->pos = pos;
	if (ft_arr_voidp_push(shapes, sq) == NULL)
		exit_e("malloc");
}

void	add_cylinder(t_arr_voidp **shapes, char *line)
{
	t_object	*cy;
	t_cylinder	*pos;
	char		**items;

	cy = malloc_safe(sizeof(t_object));
	pos = malloc_safe(sizeof(t_cylinder));
	cy->shape = SHAPE_CYLINDER;
	items = split_clamp(line, 6);
	set_point(&pos->origin, items[1]);
	set_orientation(&pos->orientation, items[2]);
	pos->radius = strtodbl_clamp(items[3], '\0', 0.0, DOUBLE_MAX);
	pos->height = strtodbl_clamp(items[4], '\0', 0.0, DOUBLE_MAX);
	set_color(&cy->color, items[5]);
	cy->pos = pos;
	ft_free_until_null_char(items);
	if (ft_arr_voidp_push(shapes, cy) == NULL)
		exit_e("malloc");
}

void	add_triangle(t_arr_voidp **shapes, char *line)
{
	t_object	*tr;
	t_triangle	*pos;
	char		**items;

	tr = malloc_safe(sizeof(t_object));
	pos = malloc_safe(sizeof(t_triangle));
	tr->shape = SHAPE_TRIANGLE;
	items = split_clamp(line, 5);
	set_point(&pos->p1, items[1]);
	set_point(&pos->p2, items[2]);
	set_point(&pos->p3, items[3]);
	set_color(&tr->color, items[4]);
	ft_free_until_null_char(items);
	tr->pos = pos;
	if (ft_arr_voidp_push(shapes, tr) == NULL)
		exit_e("malloc");
}

void	log_shapes(t_arr_voidp *shapes)
{
	t_shape	shape;
	size_t	i;

	i = 0;
	ft_putstr("Shapes found:\n");
	while (ft_arr_voidp_get(shapes, i) != NULL)
	{
		ft_memcpy(&shape, ft_arr_voidp_get(shapes, i), sizeof(t_shape));
		if (shape < SHAPE_LAST)
			printf("\tFound %s\n", g_rule_name[shape]); // illegal
		else
			ft_putstr("\tSomething has gone horribly wrong\n");
		i++;
	}
}
