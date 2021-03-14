/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   is_power_of_2.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jkoers <jkoers@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/12 23:24:30 by jkoers        #+#    #+#                 */
/*   Updated: 2021/03/12 23:24:30 by jkoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	is_power_of_2(long x)
{
	if (x < 0)
		return (false);
	return (!(x == 0) && !(x & (x - 1)));
}

bool	is_power_of_2u(unsigned long x)
{
	return (!(x == 0) && !(x & (x - 1)));
}
