/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rt_file.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jkoers <jkoers@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/28 13:39:05 by jkoers        #+#    #+#                 */
/*   Updated: 2021/01/05 13:35:02 by jkoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "gui.h"
#include "shapes.h"
#include "constants.h"
#include "../lib/minilibx-linux/mlx.h"
#include "../lib/ft_printf/ft_printf.h"
#include "../lib/libft/include/libft.h"
#include <limits.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

// bool	has_duplicate_rules(char **rt)
// {
// 	return (false);
// }

e_msg	destroy_set_resolution(e_msg msg, char **params)
{
	ft_free_until_null_char(params);
	if (msg != SUCCESS)
		ft_putstr("Failed to set resolution\n");
	return (msg);
}

e_msg	set_resolution(char *line, unsigned long *x, unsigned long *y)
{
	char	**params;

	if (split_clamp(&params, line, 3) != SUCCESS)
		return (destroy_set_resolution(BADRULE, params));
	if (strtonum_clamp((long *)x, params[1], '\0', 1, LONG_MAX) != SUCCESS)
		return (destroy_set_resolution(ERR_RT_BADVALUE, params));
	if (strtonum_clamp((long *)y, params[2], '\0', 1, LONG_MAX) != SUCCESS)
		return (destroy_set_resolution(ERR_RT_BADVALUE, params));	
	return (destroy_set_resolution(SUCCESS, params));
}

e_msg	destroy_set_ambient(e_msg msg, char **params)
{
	ft_free_until_null_char(params);
	if (msg != SUCCESS)
		ft_putstr("Failed to set brightness\n");
	return (msg);
}

e_msg	set_ambient(char *line, t_ambient *ambient)
{
	char	**params;

	if (split_clamp(&params, line, 3) != SUCCESS)
		return (destroy_set_resolution(BADRULE, params));
	if (strtodbl_clamp(&ambient->brightness,
		params[1], '\0', 0.0, LONG_MAX) != SUCCESS)
		return (destroy_set_resolution(ERR_RT_BADVALUE, params));
	if (set_color(&ambient->color, params[2]) != SUCCESS)
		return (destroy_set_resolution(ERR_RT_BADVALUE, params));
	return (destroy_set_resolution(SUCCESS, params));
}

e_msg	destroy_add_camera(e_msg msg, char **params, t_camera *camera)
{
	ft_free_until_null_char(params);
	if (camera)
		free(camera);
	if (msg != SUCCESS)
		ft_putstr("Failed to set brightness\n");
	return (msg);
}

e_msg	add_camera(char *line, t_arr_voidp **cameras)
{
	char		**items;
	t_camera	*cam;

	cam = malloc(sizeof(t_camera));
	if (cam == NULL)
		return (ERR_MALLOC);
	if (split_clamp(&items, line, 4) != SUCCESS)
		return (destroy_add_camera(BADRULE, items, cam));
	if (set_point(&cam->origin, items[1]) != SUCCESS)
		return (destroy_add_camera(BADRULE, items, cam));
	if (set_point(&cam->orientation, items[2]) != SUCCESS)
		return (destroy_add_camera(BADRULE, items, cam));
	if (strtodbl_clamp(&cam->fov, items[3], '\0', 0.0, 180.0) != SUCCESS)
		return (destroy_add_camera(ERR_RT_BADVALUE, items, cam));
	if (ft_arr_voidp_push(cameras, cam) == NULL)
		return (destroy_add_camera(ERR_MALLOC, items, cam));
	return (SUCCESS);
}

e_msg	destroy_add_light(e_msg msg, char **params, t_light *light)
{
	ft_free_until_null_char(params);
	if (light)
		free(light);
	if (msg != SUCCESS)
		ft_putstr("Failed to set brightness\n");
	return (msg);
}

e_msg	add_light(char *line, t_arr_voidp **lights)
{
	char	**items;
	t_light	*light;

	light = malloc(sizeof(t_light));
	if (light == NULL)
		return (ERR_MALLOC);
	if (split_clamp(&items, line, 4) != SUCCESS)
		return (destroy_add_light(BADRULE, items, light));
	if (set_point(&light->origin, items[1]) != SUCCESS)
		return (destroy_add_light(BADRULE, items, light));
	if (strtodbl_clamp(&light->brightness,
			items[2], '\0', 0.0, 1.0) != SUCCESS)
		return (destroy_add_light(ERR_RT_BADVALUE, items, light));
	if (set_point(&light->orientation, items[3]) != SUCCESS)
		return (destroy_add_light(BADRULE, items, light));
	if (ft_arr_voidp_push(lights, light) == NULL)
		return (destroy_add_light(ERR_MALLOC, items, light));
	return (SUCCESS);
}

e_msg	parse_rt_line(char *line, t_gui *gui)
{
	if (line[0] == '\0'  || line[0] == '#')
		return (SUCCESS);
	else if (ft_strcmp(line, g_rule_id[RULE_RESOLUTION]) == ' ')
		return (set_resolution(line, &gui->x_size, &gui->y_size));
	else if (ft_strcmp(line, g_rule_id[RULE_SPHERE]) == ' ')
		return (add_sphere(line, &gui->shapes));
	else if (ft_strcmp(line, g_rule_id[RULE_PLANE]) == ' ')
		return (add_plane(line, &gui->shapes));
	else if (ft_strcmp(line, g_rule_id[RULE_SQUARE]) == ' ')
		return (add_square(line, &gui->shapes));
	else if (ft_strcmp(line, g_rule_id[RULE_CYLINDER]) == ' ')
		return (add_cylinder(line, &gui->shapes));
	else if (ft_strcmp(line, g_rule_id[RULE_TRIANGLE]) == ' ')
		return (add_triangle(line, &gui->shapes));
	else if (ft_strcmp(line, g_rule_id[RULE_AMBIENT]) == ' ')
		return (set_ambient(line, &gui->ambient));
	else if (ft_strcmp(line, g_rule_id[RULE_CAMERA]) == ' ')
		return (add_camera(line, &gui->cameras));
	else if (ft_strcmp(line, g_rule_id[RULE_LIGHT]) == ' ')
		return (add_light(line, &gui->lights));
	else
		return (ERR_RT_UNKNOWN_RULE);
}

// e_msg	parse_rt_line(char *line, t_gui *gui)
// {
// 	ssize_t i;
// 	char	*end;
// 	static e_msg (*shape_parser[SHAPE_LAST])() = {
// 		[RULE_SPHERE] = add_sphere,
// 		[RULE_PLANE] = add_plane,
// 		[RULE_SQUARE] = add_square,
// 		[RULE_CYLINDER] = add_cylinder,
// 		[RULE_TRIANGLE] = add_triangle
// 	};
// 	if (line[0] == '#' || ft_strlen(line) <= 1)
// 		return (SUCCESS);
// 	end = ft_strchr(line, ' ');
// 	if (end == NULL)
// 		return (ERR_RT_UNKNOWN_RULE);
// 	i = ft_arrnchrn(g_rule_id, SHAPE_LAST, line, (size_t)(end - line));
// 	if (i == -1)
// 		return (ERR_RT_UNKNOWN_RULE);
// 	return (shape_parser[i](line, gui->shapes));
// }

e_msg	destroy_parse_rt(e_msg msg, char **rt, size_t i)
{
	if (msg != SUCCESS)
		printf("Failed at line %02lu <%s>\n", i + 1, rt[i]); // illegal
	ft_free_until_null_char(rt);
	return (msg);
}

e_msg	parse_rt(char *rt_filename, t_gui *gui)
{
	size_t	rt_lines;
	char	**rt;
	e_msg	msg;
	size_t	i;

	rt = ft_split_file(rt_filename, &rt_lines);
	if (rt == NULL || rt_lines == 0)
		return (destroy_parse_rt(ERR_RT_EMPTY, rt, 0));
	i = 0;
	while (rt[i])
	{
		msg = parse_rt_line(rt[i], gui);
		if (msg != SUCCESS)
			return (destroy_parse_rt(msg, rt, i));
		i += 1;
	}
	if (VERBOSE)
		log_shapes(gui->shapes);
	return (destroy_parse_rt(SUCCESS, rt, i));
}
