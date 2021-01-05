/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   unsorted.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jkoers <jkoers@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/05 14:22:31 by jkoers        #+#    #+#                 */
/*   Updated: 2021/01/05 14:32:19 by jkoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

double radians(double degrees)
{
	return (degrees * M_PI / 180);
}

double degrees(double radians)
{
	return (radians * 180 / M_PI);
}
