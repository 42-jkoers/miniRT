/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   constants.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jkoers <jkoers@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/02 22:37:04 by jkoers        #+#    #+#                 */
/*   Updated: 2021/01/05 13:40:15 by jkoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "constants.h"
#include "gui.h"
#include "shapes.h"

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

char *g_joppe_strerror[MSG_LAST] = {
	[SUCCESS] = "Done\n",
	[ERR_USELESS] = "Useless error message\n",
	[ERR_MALLOC] = "Malloc failed\n",
	[ERR_MLXINIT] = "Failed to init mlx\n",
	[ERR_RT_NOTFOUND] = "Rt file not found\n",
	[ERR_RT_EMPTY] = "Rt file is empty\n",
	[ERR_RT_INVALID] = "Rt file is invalid\n",
	[BADRULE] = "Rt rule is invalid\n",
	[ERR_RT_NUMARGS] = "Rt rule has wrong number of arguments\n",
	[ERR_RT_BADVALUE] = "Rt rule has illegal value\n",
	[ERR_RT_UNKNOWN_RULE] = "Unknow rt rule\n",
	[ERR_RT_UNEXPECTED_CHAR] = "Unexpected character\n",
	[ERR_RT_UNEXPECTED_EOL] = "Unexpected end of line\n",
	[ERR_CANVAS_CREATEIMG] = "Failed to create mlx image for canvas\n",
	[ERR_MLX_INIT] = "Mlx init failed\n",
	[ERR_WINDOW_CREATE] = "Cannot create window\n"
};

// static e_msg (*shape_parser[SHAPE_LAST])(char *line, t_gui *gui) = {
// 	[RULE_SPHERE] = add_sphere,
// 	[RULE_PLANE] = add_plane,
// 	[RULE_SQUARE] = add_square,
// 	[RULE_CYLINDER] = add_cylinder,
// 	[RULE_TRIANGLE] = add_triangle
// };
