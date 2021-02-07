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
#include "parse_rt.h"
#include "constants.h"
#include "../lib/libft/include/libft.h"
#include <math.h>
#include <stdlib.h>
#include <unistd.h>

void	parse_rt_line(char *line, t_gui *gui)
{
	if (line[0] == '\0'  || line[0] == '#') // illegal
		;
	else if (ft_strcmp(line, g_rule_id[RULE_RESOLUTION]) == ' ')
		set_resolution(gui, line);
	else if (ft_strcmp(line, g_rule_id[RULE_SPHERE]) == ' ')
		add_sphere(&gui->shapes, line);
	else if (ft_strcmp(line, g_rule_id[RULE_PLANE]) == ' ')
		add_plane(&gui->shapes, line);
	else if (ft_strcmp(line, g_rule_id[RULE_SQUARE]) == ' ')
		add_square(&gui->shapes, line);
	else if (ft_strcmp(line, g_rule_id[RULE_CYLINDER]) == ' ')
		add_cylinder(&gui->shapes, line);
	else if (ft_strcmp(line, g_rule_id[RULE_TRIANGLE]) == ' ')
		add_triangle(&gui->shapes, line);
	else if (ft_strcmp(line, g_rule_id[RULE_AMBIENT]) == ' ')
		set_ambient(&gui->ambient, line);
	else if (ft_strcmp(line, g_rule_id[RULE_CAMERA]) == ' ')
		add_camera(gui, line);
	else if (ft_strcmp(line, g_rule_id[RULE_LIGHT]) == ' ')
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
	exit_on_illegal_rule_n(rt);
	i = 0;
	while (rt[i])
	{
		g_failed_rule = rt[i];
		parse_rt_line(rt[i], gui);
		i++;
	}
	ft_free_until_null_char(rt);
	if (VERBOSE)
		log_shapes(gui->shapes);
}
