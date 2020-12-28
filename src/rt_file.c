/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rt_file.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jkoers <jkoers@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/28 13:39:05 by jkoers        #+#    #+#                 */
/*   Updated: 2020/12/28 17:09:41 by jkoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "gui.h"
#include "helpers.h"
#include "keycodes.h"
#include "../lib/minilibx-linux/mlx.h"
#include "../lib/ft_printf/ft_printf.h"
#include "../lib/libft/include/libft.h"
#include <limits.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

// bool	has_duplicate_rules(char **rt)
// {
// 	return (false);
// }

long	strtonum2(t_gui *gui, char *str, long min, long max)
{
	size_t	i;
	long	num;
	
	i = str[0] == '+' || str[0] == '-' ? 1 : 0;
	while (ft_isdigit(str[i]))
		i++;
	if (str[i] != '\0')
		exit_clean(gui, "Line %i: Invalid number %s\n", (int)gui->rt_i, str);
	num = ft_strtonum(str);
	if (num > max || num < min)
		exit_clean(gui, "Line %i: Invalid number %s\n", (int)gui->rt_i, str);
	return (num);	
}

void	set_resolution(t_gui *gui, char *line)
{
	size_t	params;

	gui->rt_line_split = ft_split_length(line, ' ', &params);
	if (gui->rt_line_split == NULL)
		exit_clean(gui, "malloc 1\n");
	if (params != 3)
		exit_clean(gui, "Line %i: Failed to set resolution\n", (int)gui->rt_i);
	mlx_get_screen_size(gui->mlx, (int *)(&gui->x_size), (int *)(&gui->y_size));
	gui->x_size = ft_min_u(gui->x_size, strtonum2(gui, gui->rt_line_split[1], 1, LONG_MAX));
	gui->y_size = ft_min_u(gui->y_size, strtonum2(gui, gui->rt_line_split[2], 1, LONG_MAX));
	ft_free_2d((void **)gui->rt_line_split, params);
	if (VERBOSE)
		ft_printf("Resolution %ix%i\n", (int)gui->x_size, (int)gui->y_size);
}

void	set_rt(t_gui *gui, char *rt_filename)
{
	size_t	rt_lines;

	gui->rt = ft_split_file(rt_filename, &rt_lines);
	if (gui->rt == NULL || rt_lines == 0)
		exit_clean(gui, "rt file nonexistant or empty <%s>\n", rt_filename);
	// if (has_duplicate_rules(gui->rt))
	// 	exit_clean(gui, "Found duplicate rules\n");
	gui->rt_i = 0;
	while (gui->rt[gui->rt_i])
	{
		if (ft_strlen(gui->rt[gui->rt_i]) <= 1)
			ft_printf("empty\n");
		else if (ft_strcmp(gui->rt[gui->rt_i], RULE_RESOLUTION) == ' ')
			set_resolution(gui, gui->rt[gui->rt_i]);
		// else if (ft_strcmp(RULE_CYLINDER, gui->rt[gui->rt_i]) == ' ')
		// 	;
		gui->rt_i += 1;
	}
}
