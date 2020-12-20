/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtonum_u.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jkoers <jkoers@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/26 17:30:43 by jkoers        #+#    #+#                 */
/*   Updated: 2020/11/08 15:33:32 by jkoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <stdbool.h>

unsigned long	ft_strtonum_u(char *str)
{
	unsigned long	result;
	bool			is_negative;

	while (ft_isspace(*str))
		str++;
	is_negative = *str == '-';
	if (*str == '+')
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
