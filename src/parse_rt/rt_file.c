/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rt_file.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jkoers <jkoers@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/28 13:39:05 by jkoers        #+#    #+#                 */
/*   Updated: 2021/01/12 14:28:20 by jkoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parse_rt.h"
#include "parse_rt.h"
#include "constants.h"
#include "unsorted.h"
#include "../lib/libft/include/libft.h"
#include <math.h>
#include <stdlib.h>
#include <unistd.h>

// bool	has_duplicate_rules(char **rt)
// {
// 	return (false);
// }

void	search_missing_rules(t_gui *gui)
{
	if (gui->x_resolution == 0 || gui->y_resolution == 0)
	{
		exit_e("Missing resolution rule");
		return ;
	}
}

void	parse_rt_line(char *line, t_gui *gui)
{
	if (line[0] == '\0'  || line[0] == '#')
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
		add_camera(&gui->cameras, line);
	else if (ft_strcmp(line, g_rule_id[RULE_LIGHT]) == ' ')
		add_light(&gui->lights, line);
	else
		exit_e("Unknown rule");
}

void	clearline(void) // libft
{
	ft_putstr("\33[2K\r");
}

void	foreach_arr(char **rt, t_gui *gui)
{
	size_t	i;

	i = 0;
	while (rt[i])
	{
		verbose("Reading: ");
		verbose(rt[i]);
		parse_rt_line(rt[i], gui);
		if (VERBOSE)
			clearline();
		i++;
	}
}

void	parse_rt(t_gui *gui, char *rt_filename)
{
	size_t	rt_lines;
	char	**rt;

	rt = ft_split_file(rt_filename, &rt_lines);
	if (rt == NULL || rt_lines == 0)
		exit_e("Empty rt file");
	foreach_arr(rt, gui);
	ft_free_until_null_char(rt);
	search_missing_rules(gui);
	gui->camera = (t_camera *)(gui->cameras->table[0]);
	if (VERBOSE)
		log_shapes(gui->shapes);
}
