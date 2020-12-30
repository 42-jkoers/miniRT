/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   shapes.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jkoers <jkoers@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/27 20:55:30 by jkoers        #+#    #+#                 */
/*   Updated: 2020/12/31 00:36:48 by jkoers        ########   odam.nl         */
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

e_msg	destroy_add_sphere(e_msg msg, t_sphere *sphere)
{
	free(sphere);
	return (msg);
}

e_msg	add_sphere(char *line, t_arr_voidp *shapes)
{
	t_sphere	*sphere;
	char		**params;

	sphere = malloc(sizeof(t_sphere));
	if (sphere == NULL)
		return (destroy_add_sphere(ERR_MALLOC, sphere));
	sphere->shape = SHAPE_SPHERE;
	if (split_clamp(&params, line, 4) != SUCCESS)
		return (destroy_add_sphere(ERR_RT_BADRULE, sphere));
	if (set_point(&sphere->origin, params[1]) != SUCCESS)
		return (destroy_add_sphere(ERR_RT_BADRULE, sphere));
	if (strtonum_clamp(&sphere->diameter, params[2], '\0', 0, DOUBLE_MAX) != SUCCESS)
		return (destroy_add_sphere(ERR_RT_BADRULE, sphere));
	if (set_color(&sphere->color, params[3]) != SUCCESS)
		return (destroy_add_sphere(ERR_RT_BADRULE, sphere));
	return (destroy_add_sphere(SUCCESS, sphere));	
}
