/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rt_file.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jkoers <jkoers@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/28 13:39:05 by jkoers        #+#    #+#                 */
/*   Updated: 2021/01/12 14:48:54 by jkoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parse_rt.h"
#include "constants.h"
#include "../lib/libft/include/libft.h"
#include <stdio.h>

void	log_shapes(const t_arr *shapes)
{
	t_obj			*obj;
	size_t			i;
	unsigned int	shape_n[SHAPE_LAST];

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
		if (shape_n[i] > 0)
			printf("   %-10s %u\n", rule_name(i), shape_n[i]);
		i++;
	}
}

bool	is_rule(char *line, t_rule rule)
{
	return (ft_strcmp(line, rule_id(rule)) == ' ');
}

static void	parse_rt_line(char *line, t_gui *gui)
{
	if (line[0] == '\0' || (ALLOW_RT_COMMENTS && line[0] == '#'))
		;
	else if (is_rule(line, RULE_RESOLUTION))
		set_resolution(gui, line);
	else if (is_rule(line, RULE_SPHERE))
		add_sphere(&gui->shapes, line);
	else if (is_rule(line, RULE_PLANE))
		add_plane(&gui->shapes, line);
	else if (is_rule(line, RULE_SQUARE))
		add_square(&gui->shapes, line);
	else if (is_rule(line, RULE_CYLINDER))
		add_cylinder(&gui->shapes, line);
	else if (is_rule(line, RULE_TRIANGLE))
		add_triangle(&gui->shapes, line);
	else if (is_rule(line, RULE_AMBIENT))
		set_ambient(&gui->ambient, line);
	else if (is_rule(line, RULE_CAMERA))
		add_camera(gui, line);
	else if (is_rule(line, RULE_LIGHT))
		add_light(&gui->lights, line);
	else
		exit_e("Unknown rule");
}

void	parse_rt(t_gui *gui, const char *rt_filename)
{
	size_t		rt_lines;
	char		**rt;
	size_t		i;

	rt = ft_split_file(rt_filename, &rt_lines);
	if (rt == NULL || rt_lines == 0)
		exit_e("Empty rt file");
	if (COUNT_RULES)
		exit_on_illegal_rule_n(rt);
	i = 0;
	while (rt[i])
	{
		line_error(rt[i]);
		parse_rt_line(rt[i], gui);
		i++;
	}
	ft_free_until_null_char(rt);
	if (VERBOSE)
		log_shapes(gui->shapes);
}
