/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   shapes.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jkoers <jkoers@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/27 20:55:30 by jkoers        #+#    #+#                 */
/*   Updated: 2021/01/02 23:19:52 by jkoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libft/include/libft.h"
#include "../lib/ft_printf/ft_printf.h"
#include "../lib/minilibx-linux/mlx.h"
#include "gui.h"
#include "shapes.h"
#include "constants.h"
#include "rt_file.h"
#include "rt_file_helpers.h"

#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>

/*
** #include <time.h>
** clock_t begin = clock();
** printf("%f s\n", (double)(clock() - begin) / CLOCKS_PER_SEC);
*/

static e_msg	destroy(e_msg msg, void *shape)
{
	free(shape);
	return (msg);
}

e_msg	add_sphere(char *line, t_arr_voidp **shapes)
{
	t_sphere	*sp;
	char		**items;

	sp = malloc(sizeof(t_sphere));
	if (sp == NULL)
		return (destroy(ERR_MALLOC, sp));
	sp->shape = SHAPE_SPHERE;
	if (split_clamp(&items, line, 4) != SUCCESS)
		return (destroy(BADRULE, sp));
	if (set_point(&sp->origin, items[1]) != SUCCESS)
		return (destroy(BADRULE, sp));
	if (strtodbl_clamp(&sp->diameter,
			items[2], '\0', 0.0, DOUBLE_MAX) != SUCCESS)
		return (destroy(BADRULE, sp));
	if (set_color(&sp->color, items[3]) != SUCCESS)
		return (destroy(BADRULE, sp));
	if (ft_arr_voidp_push(shapes, sp) == NULL)
		return (destroy(ERR_MALLOC, sp));
	return (SUCCESS);
}

e_msg	add_plane(char *line, t_arr_voidp **shapes)
{
	t_plane	*pl;
	char	**items;

	pl = malloc(sizeof(t_plane));
	if (pl == NULL)
		return (destroy(ERR_MALLOC, pl));
	pl->shape = SHAPE_PLANE;
	if (split_clamp(&items, line, 4) != SUCCESS)
		return (destroy(BADRULE, pl));
	if (set_point(&pl->origin, items[1]) != SUCCESS)
		return (destroy(BADRULE, pl));
	if (set_point(&pl->orientation, items[2]) != SUCCESS)
		return (destroy(BADRULE, pl));
	if (set_color(&pl->color, items[3]) != SUCCESS)
		return (destroy(BADRULE, pl));
	if (ft_arr_voidp_push(shapes, pl) == NULL)
		return (destroy(ERR_MALLOC, pl));
	return (SUCCESS);
}

e_msg	add_square(char *line, t_arr_voidp **shapes)
{
	t_square	*sq;
	char		**items;

	sq = malloc(sizeof(t_square));
	if (sq == NULL)
		return (destroy(ERR_MALLOC, sq));
	sq->shape = SHAPE_SQUARE;
	if (split_clamp(&items, line, 5) != SUCCESS)
		return (destroy(BADRULE, sq));
	if (set_point(&sq->origin, items[1]) != SUCCESS)
		return (destroy(BADRULE, sq));
	if (set_point(&sq->orientation, items[2]) != SUCCESS)
		return (destroy(BADRULE, sq));
	if (strtodbl_clamp(&sq->size, items[3], '\0', 0.0, DOUBLE_MAX) != SUCCESS)
		return (destroy(BADRULE, sq));
	if (set_color(&sq->color, items[4]) != SUCCESS)
		return (destroy(BADRULE, sq));
	if (ft_arr_voidp_push(shapes, sq) == NULL)
		return (destroy(ERR_MALLOC, sq));
	return (SUCCESS);
}

e_msg	add_cylinder(char *line, t_arr_voidp **shapes)
{
	t_cylinder	*cy;
	char		**items;

	cy = malloc(sizeof(t_cylinder));
	if (cy == NULL)
		return (destroy(ERR_MALLOC, cy));
	cy->shape = SHAPE_CYLINDER;
	if (split_clamp(&items, line, 6) != SUCCESS)
		return (destroy(BADRULE, cy));
	if (set_point(&cy->origin, items[1]) != SUCCESS)
		return (destroy(BADRULE, cy));
	if (set_point(&cy->orientation, items[2]) != SUCCESS)
		return (destroy(BADRULE, cy));
	if (strtodbl_clamp(&cy->diameter,
			items[3], '\0', 0.0, DOUBLE_MAX) != SUCCESS)
		return (destroy(BADRULE, cy));
	if (strtodbl_clamp(&cy->height, items[4], '\0', 0.0, DOUBLE_MAX) != SUCCESS)
		return (destroy(BADRULE, cy));
	if (set_color(&cy->color, items[5]) != SUCCESS)
		return (destroy(BADRULE, cy));
	if (ft_arr_voidp_push(shapes, cy) == NULL)
		return (destroy(ERR_MALLOC, cy));
	return (SUCCESS);
}

e_msg	add_triangle(char *line, t_arr_voidp **shapes)
{
	t_triangle	*tr;
	char		**items;

	tr = malloc(sizeof(t_triangle));
	if (tr == NULL)
		return (destroy(ERR_MALLOC, tr));
	tr->shape = SHAPE_TRIANGLE;
	if (split_clamp(&items, line, 5) != SUCCESS)
		return (destroy(BADRULE, tr));
	if (set_point(&tr->p1, items[1]) != SUCCESS)
		return (destroy(BADRULE, tr));
	if (set_point(&tr->p2, items[2]) != SUCCESS) 
		return (destroy(BADRULE, tr));
	if (set_point(&tr->p3, items[3]) != SUCCESS)
		return (destroy(BADRULE, tr));
	if (set_color(&tr->color, items[4]) != SUCCESS)
		return (destroy(BADRULE, tr));
	if (ft_arr_voidp_push(shapes, tr) == NULL)
		return (destroy(ERR_MALLOC, tr));
	return (SUCCESS);
}

void	log_shapes(t_arr_voidp *shapes)
{
	e_shape	shape;
	size_t	i;

	i = 0;
	ft_putstr("Shapes found:\n");
	while (ft_arr_voidp_get(shapes, i) != NULL)
	{
		ft_memcpy(&shape, ft_arr_voidp_get(shapes, i), sizeof(e_shape));
		if (shape < SHAPE_LAST)
			ft_printf("\tFound %s\n", g_rule_name[shape]); // illegal
		else	
			ft_putstr("\tSomething has gone horribly wrong\n");
		i++;
	}
}
