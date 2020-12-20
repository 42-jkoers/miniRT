/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtonum.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jkoers <jkoers@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/26 17:30:43 by jkoers        #+#    #+#                 */
/*   Updated: 2020/11/26 17:13:31 by jkoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <stdbool.h>

long	ft_strtonum(char *str)
{
	long	result;
	bool	is_negative;

	while (ft_isspace(*str))
		str++;
	is_negative = *str == '-';
	if (*str == '-' || *str == '+')
		str++;
	result = 0;
	while (ft_isdigit(*str))
	{
		result *= 10;
		result -= (long)(*str - '0');
		str++;
	}
	return (is_negative ? result : (-result));
}
