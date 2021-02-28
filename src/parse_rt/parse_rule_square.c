/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_rule_square.c                                :+:    :+:            */
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
#include "norm.h"
#include <stdlib.h>
#include <math.h>

// edge1 = subtract(p1, p0);
// edge2 = subtract(p2, p0);

static void	square_to_triangles(t_triangle *trs, t_square sq, double half_side)
{
	t_vec3	cross_r[3];
	t_vec3	v[4];
	t_vec3	tmp[2];
	t_vec3	edges[4];

	if (fabs(sq.normal.z) == 1.0)
		tmp[0] = vec(1.0, 0.0, 0.0);
	else
		tmp[0] = vec(0.0, 0.0, 1.0);
	cross_r[0] = unit(cross(tmp[0], sq.normal));
	cross_r[1] = unit(cross(sq.normal, cross_r[0]));
	cross_r[2] = unit(cross(sq.normal, tmp[0]));
	tmp[1] = vec(sq.origin.x, sq.origin.y, sq.origin.z);
	v[0] = add(tmp[1], scale(add(cross_r[1], cross_r[0]), half_side));
	v[1] = add(tmp[1], scale(subtract(cross_r[1], cross_r[0]), half_side));
	v[2] = add(tmp[1], scale(subtract(cross_r[2], cross_r[1]), half_side));
	v[3] = add(tmp[1], scale(subtract(cross_r[0], cross_r[1]), half_side));
	edges[0] = subtract(v[1], v[0]);
	edges[1] = subtract(v[2], v[0]);
	edges[2] = subtract(v[2], v[0]);
	edges[3] = subtract(v[3], v[0]);
	trs[0] = (t_triangle){v[0], v[1], v[2], edges[0], edges[1]};
	trs[1] = (t_triangle){v[0], v[2], v[3], edges[2], edges[3]};
}

static void	add_triangles(t_arr_voidp **shapes, t_triangle *trs, t_rgb color)
{
	t_obj	*obj;
	size_t	i;

	i = 0;
	while (i < 2)
	{
		obj = malloc_safe(sizeof(t_obj));
		obj->shape = SHAPE_TRIANGLE;
		obj->color = color;
		obj->pos.tr = trs[i];
		if (ft_arr_voidp_push(shapes, obj) == NULL)
			exit_e("malloc");
		i++;
	}
}

// A square can be represented by 2 triangles.
// So we add 2 triangels to the renderer instead 1 triangle

void	add_square(t_arr_voidp **shapes, char *line)
{
	t_square	sq;
	t_rgb		color;
	char		**items;
	t_triangle	trs[2];

	items = split_clamp(line, 5);
	set_point(&sq.origin, items[1]);
	set_dir(&sq.normal, items[2]);
	sq.size = strtodbl_clamp(items[3], '\0', 0.0, DOUBLE_MAX);
	set_color(&color, items[4]);
	ft_free_until_null_char(items);
	square_to_triangles(trs, sq, sq.size * 0.5);
	add_triangles(shapes, trs, color);
}
