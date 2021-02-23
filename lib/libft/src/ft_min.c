/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_min.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jkoers <jkoers@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/16 16:28:20 by jkoers        #+#    #+#                 */
/*   Updated: 2020/12/26 22:16:39 by jkoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_min(long a, long b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

unsigned long	ft_min_u(unsigned long a, unsigned long b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

double	ft_minf(double a, double b)
{
	if (a < b)
		return (a);
	else
		return (b);
}
