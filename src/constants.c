/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   constants.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jkoers <jkoers@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/02 22:37:04 by jkoers        #+#    #+#                 */
/*   Updated: 2021/01/03 00:32:19 by jkoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "constants.h"

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
