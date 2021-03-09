/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   constants.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jkoers <jkoers@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/02 22:37:04 by jkoers        #+#    #+#                 */
/*   Updated: 2021/01/12 14:06:24 by jkoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "constants.h"
#include <stdlib.h>

char	*rule_id(t_rule i)
{
	static const char	*rule_id[RULE_LAST] = {
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

	return ((char *)rule_id[i]);
}

char	*rule_name(t_rule i)
{
	static const char	*rule_name[RULE_LAST] = {
		[RULE_SPHERE] = "Sphere",
		[RULE_PLANE] = "Plane",
		[RULE_SQUARE] = "Square",
		[RULE_CYLINDER] = "Cylinder",
		[RULE_TRIANGLE] = "Triangle",
		[RULE_RESOLUTION] = "Resolution",
		[RULE_AMBIENT] = "Ambient brightness",
		[RULE_CAMERA] = "Camera",
		[RULE_LIGHT] = "Light source",
	};

	return ((char *)rule_name[i]);
}

void	*malloc_safe(size_t size)
{
	void	*p;

	p = malloc(size);
	if (p == NULL)
		exit_e("malloc");
	return (p);
}

void	*calloc_safe(size_t size)
{
	void	*p;

	p = malloc_safe(size);
	ft_bzero(p, size);
	return (p);
}
