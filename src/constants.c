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
#include "gui.h"

#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

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
	[RULE_AMBIENT] = "Ambient brightness",
	[RULE_CAMERA] = "Camera",
	[RULE_LIGHT] = "Light source",
};

void	exit_e(const char *msg)
{
	size_t	len;

	printf("%s", msg);
	len = ft_strlen((char *)msg);
	if (len > 0 && msg[len - 1] != '\n')
		printf("\n");
	printf ("At line <%s>\n", g_failed_rule);
	exit(1);
}

void	exit_range(long num, long min, long max)
{
	printf("Number %li out of range [%li %li]\n", num, min, max);
	exit_e("");
}

void	exit_ranged(double num, double min, double max)
{
	printf("Double %lf out of range [%lf %lf]\n", num, min, max);
	exit_e("");
}

void	exit_char(char got, char expected)
{
	if (ft_isprint(expected))
		printf("Expected <%c>, ", expected);
	else
		printf("Expected <x%x>, ", expected);
	if (ft_isprint(got))
		printf("got <%c>\n", got);
	else
		printf("got <x%x>\n", got);
	exit(1);
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
	void *p;

	p = malloc_safe(size);
	ft_bzero(p, size);
	return (p);
}

double	max_dbl(double a, double b)
{
	return (a > b ? a : b);
}

double	min_dbl(double a, double b)
{
	return (a < b ? a : b);
}

void	*arr_get(const t_arr_voidp *arr, size_t i)
{
	return (ft_arr_voidp_get((t_arr_voidp *)arr, i));
}
