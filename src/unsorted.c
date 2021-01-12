/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   unsorted.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jkoers <jkoers@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/05 14:22:31 by jkoers        #+#    #+#                 */
/*   Updated: 2021/01/09 00:23:47 by jkoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>


// clock_t tic = clock();
// 
// clock_t toc = clock();
// printf("Elapsed: %lf\n", (double)(toc - tic) / CLOCKS_PER_SEC);

double	radians(double degrees)
{
	return (degrees * M_PI / 180);
}

double	degrees(double radians)
{
	return (radians * 180 / M_PI);
}
