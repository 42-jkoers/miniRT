/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exit.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jkoers <jkoers@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/10 19:55:43 by jkoers        #+#    #+#                 */
/*   Updated: 2021/02/10 19:55:43 by jkoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "constants.h"
#include <stdlib.h>
#include <stdio.h>

void	exit_e(const char *msg)
{
	size_t	len;

	printf("%s", msg);
	len = ft_strlen((char *)msg);
	if (len > 0 && msg[len - 1] != '\n')
		printf("\n");
	printf("At line <%s>\n", g_failed_rule);
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
