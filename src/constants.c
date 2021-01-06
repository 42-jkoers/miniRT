/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   constants.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jkoers <jkoers@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/02 22:37:04 by jkoers        #+#    #+#                 */
/*   Updated: 2021/01/06 01:09:42 by jkoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "constants.h"
#include "gui.h"
#include "shapes.h"
#include <stdlib.h>
#include <stdio.h>

char *g_rule_id[RULE_LAST] = {
	[RULE_SPHERE] = "sp",
	[RULE_PLANE] = "pl",
	[RULE_SQUARE] = "sq",
	[RULE_CYLINDER] = "cy",
	[RULE_TRIANGLE] = "tr",
	[RULE_RESOLUTION] = "R",
	[RULE_AMBIENT] = "A",
	[RULE_CAMERA] = "c",
	[RULE_LIGHT] = "l",
};

char *g_rule_name[RULE_LAST] = {
	[RULE_SPHERE] = "Sphere",
	[RULE_PLANE] = "Plane",
	[RULE_SQUARE] = "Square",
	[RULE_CYLINDER] = "Cylinder",
	[RULE_TRIANGLE] = "Triangle",
	[RULE_RESOLUTION] = "Resolution",
	[RULE_AMBIENT] = "Brightness",
	[RULE_CAMERA] = "Camera",
	[RULE_LIGHT] = "Light source",
};

void	exit_e(char *msg)
{
	size_t	len;

	len = ft_strlen(msg);
	ft_putstr(msg);
	if (len > 0 && msg[len - 1] != '\n')
		ft_putstr("\n");
	exit(1);
}

void	exit_range(long num, long min, long max)
{

	exit(1);
}

void	exit_ranged(double num, double min, double max)
{

	exit(1);
}

void	exit_char(char got, char expected)
{
	printf("Expected <%c>, got <%c>\n", got, expected); // illegal
	exit(1);
}

// static t_msg (*shape_parser[SHAPE_LAST])(char *line, t_gui *gui) = {
// 	[RULE_SPHERE] = add_sphere,
// 	[RULE_PLANE] = add_plane,
// 	[RULE_SQUARE] = add_square,
// 	[RULE_CYLINDER] = add_cylinder,
// 	[RULE_TRIANGLE] = add_triangle
// };
