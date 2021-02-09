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
#include "vector.h"
#include <stdlib.h>

void	add_sphere(t_arr_voidp **shapes, char *line)
{
	t_obj	*obj;
	char		**items;

	obj = malloc_safe(sizeof(t_obj));
	obj->shape = SHAPE_SPHERE;
	items = split_clamp(line, 4);
	set_point(&obj->pos.sp.origin, items[1]);
	obj->pos.sp.radius = strtodbl_clamp(items[2], '\0', 0.0, DOUBLE_MAX) * 0.5;
	obj->pos.sp.radius2 = obj->pos.sp.radius * obj->pos.sp.radius;
	set_color(&obj->color, items[3]);
	ft_free_until_null_char(items);
	if (ft_arr_voidp_push(shapes, obj) == NULL)
		exit_e("malloc");
}

void	add_plane(t_arr_voidp **shapes, char *line)
{
	t_obj	*obj;
	char	**items;

	obj = malloc_safe(sizeof(t_obj));
	obj->shape = SHAPE_PLANE;
	items = split_clamp(line, 4);
	set_point(&obj->pos.pl.origin, items[1]);
	set_dir(&obj->pos.pl.normal, items[2]);
	set_color(&obj->color, items[3]);
	ft_free_until_null_char(items);
	if (ft_arr_voidp_push(shapes, obj) == NULL)
		exit_e("malloc");
}

void	add_square(t_arr_voidp **shapes, char *line)
{
	t_obj	*obj;
	char	**items;

	obj = malloc_safe(sizeof(t_obj));
	obj->shape = SHAPE_SQUARE;
	items = split_clamp(line, 5);
	set_point(&obj->pos.sq.origin, items[1]);
	set_dir(&obj->pos.sq.normal, items[2]);
	obj->pos.sq.size = strtodbl_clamp(items[3], '\0', 0.0, DOUBLE_MAX);
	set_color(&obj->color, items[4]);
	ft_free_until_null_char(items);
	if (ft_arr_voidp_push(shapes, obj) == NULL)
		exit_e("malloc");
}

void	add_cylinder(t_arr_voidp **shapes, char *line)
{
	t_obj	*obj;
	char	**items;

	obj = malloc_safe(sizeof(t_obj));
	obj->shape = SHAPE_CYLINDER;
	items = split_clamp(line, 6);
	set_point(&obj->pos.cy.origin, items[1]);
	set_dir(&obj->pos.cy.dir, items[2]);
	obj->pos.cy.radius = strtodbl_clamp(items[3], '\0', 0.0, DOUBLE_MAX) * 0.5;
	obj->pos.cy.height = strtodbl_clamp(items[4], '\0', 0.0, DOUBLE_MAX);
	set_color(&obj->color, items[5]);
	obj->pos.cy.base2 =
		point(obj->pos.cy.origin, obj->pos.cy.dir, obj->pos.cy.height);
	ft_free_until_null_char(items);
	if (ft_arr_voidp_push(shapes, obj) == NULL)
		exit_e("malloc");
}

void	add_triangle(t_arr_voidp **shapes, char *line)
{
	t_obj	*obj;
	char	**items;

	obj = malloc_safe(sizeof(t_obj));
	obj->shape = SHAPE_TRIANGLE;
	items = split_clamp(line, 5);
	set_point(&obj->pos.tr.p1, items[1]);
	set_point(&obj->pos.tr.p2, items[2]);
	set_point(&obj->pos.tr.p3, items[3]);
	set_color(&obj->color, items[4]);
	ft_free_until_null_char(items);
	if (ft_arr_voidp_push(shapes, obj) == NULL)
		exit_e("malloc");
}

void	log_shapes(const t_arr_voidp *shapes)
{
	t_obj		*obj;
	size_t		i;
	unsigned	shape_n[SHAPE_LAST];

	i = 0;
	ft_bzero(shape_n, sizeof(shape_n));
	printf("Shapes found:\n");
	while (arr_get(shapes, i) != NULL)
	{
		obj = arr_get(shapes, i);
		shape_n[obj->shape] += 1;
		i++;
	}
	i = 0;
	while (i < SHAPE_LAST)
	{
		printf("%13s %u\n", g_rule_name[i], shape_n[i]);
		i++;
	}
}
