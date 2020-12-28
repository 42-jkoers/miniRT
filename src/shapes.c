/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   shapes.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jkoers <jkoers@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/27 20:55:30 by jkoers        #+#    #+#                 */
/*   Updated: 2020/12/28 22:33:25 by jkoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libft/include/libft.h"
#include "../lib/ft_printf/ft_printf.h"
#include "../lib/minilibx-linux/mlx.h"
#include "gui.h"
#include "shapes.h"
#include "keycodes.h"
#include "rt_file.h"

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

/*
** 0x00RRGGBB
*/

int		rgbtoint(t_rgb *rgb)
{
	int res;
	
	res = 0;
	res |= (int)(rgb->r) << 16;
	res |= (int)(rgb->g) << 8;
	res |= (int)(rgb->b) << 0;
	return (res);
}

double	strtodbl(t_gui *gui, char *str, char end, double min, double max)
{
	size_t	i;
	double	num;
	
	if (str[0] == '\0')
		exit_clean(gui, "Line %i: fucked\n", (int)gui->rt_i);
	i = str[0] == '+' || str[0] == '-' ? 1 : 0;
	while (ft_isdigit(str[i]))
		i++;
	if (str[i] == '.')
		i++;
	while (ft_isdigit(str[i]))
		i++;
	if (str[i] != end)
		exit_clean(gui, "Line %i: Invalid number %s\n", (int)gui->rt_i, str);
	num = ft_strtodbl(str);
	if (num > max || num < min)
		exit_clean(gui, "Line %i: Number %s not in range\n", (int)gui->rt_i, str);
	return (num);	
}

void	set_origin(t_gui *gui, t_point *origin, char *str)
{
	if (ft_strcount(str, ',') != 2)
		exit_clean(gui, "Line %i: wrong number of args\n", (int)gui->rt_i);
	origin->x = strtodbl(gui, str, ',', 0.0, DOUBLE_MAX);
	str = ft_strchr(str, ',') + 1;
	origin->y = strtodbl(gui, str, ',', 0.0, DOUBLE_MAX);
	str = ft_strchr(str, ',') + 1;
	origin->z = strtodbl(gui, str, '\0', 0.0, DOUBLE_MAX);
}

void	set_color(t_gui *gui, t_rgb *color, char *str)
{
	if (ft_strcount(str, ',') != 2)
		exit_clean(gui, "Line %i: wrong number of args\n", (int)gui->rt_i);
	color->r = strtonum(gui, str, ',', 0, 255);
	str = ft_strchr(str, ',') + 1;
	color->g = strtonum(gui, str, ',', 0, 255);
	str = ft_strchr(str, ',') + 1;
	color->b = strtonum(gui, str, '\0', 0, 255);
}

void	add_sphere(t_gui *gui, t_arr_voidp *shapes, char *line)
{
	t_sphere	*sphere;
	size_t		numbers;

	sphere = malloc(sizeof(sphere));
	if (sphere == NULL)
		exit_clean(gui, "malloc 3\n");
	sphere->shape = SHAPE_SPHERE;
	gui->rt_line_split = ft_split_length(line, ' ', &numbers);
	if (numbers != 4)
		exit_clean(gui, "Line %i: wrong number of args\n", (int)gui->rt_i);
	set_origin(gui, &sphere->origin, gui->rt_line_split[1]);
	sphere->diameter = strtodbl(gui, gui->rt_line_split[2], '\0', 0, DOUBLE_MAX);
	set_color(gui, &sphere->color, gui->rt_line_split[3]);
	ft_printf("AAAAAAAAAAAAAA <%s>", gui->rt_line_split[1]);
	// ft_free_2d((void **)gui->rt_line_split, numbers);
	ft_arr_voidp_push(&shapes, sphere);
	if (VERBOSE)
		ft_printf("Circle\n");
}
