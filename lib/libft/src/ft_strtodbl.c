/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtodbl.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jkoers <jkoers@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/28 18:44:02 by jkoers        #+#    #+#                 */
/*   Updated: 2020/12/28 18:44:26 by jkoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdbool.h>

static bool	skip_nondigit(char **str)
{
	bool	is_negative;

	while (ft_isspace(**str))
		(*str)++;
	is_negative = **str == '-';
	if (**str == '-' || **str == '+')
		(*str)++;
	return (is_negative);
}

double	ft_strtodbl(char *str)
{
	double	result;
	bool	is_negative;
	double	decimals;

	is_negative = skip_nondigit(&str);
	result = 0;
	while (ft_isdigit(*str))
	{
		result = (result * 10.0) - (double)(*str - '0');
		str++;
	}
	if (*str == '.')
		str++;
	decimals = 1.0;
	while (ft_isdigit(*str))
	{
		decimals *= 10.0;
		result -= (double)(*str - '0') / decimals;
		str++;
	}
	if (is_negative)
		return (result);
	else
		return (0.0 - result);
}
