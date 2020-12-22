/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   helpers.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jkoers <jkoers@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/20 18:54:43 by jkoers        #+#    #+#                 */
/*   Updated: 2020/12/21 19:24:12 by jkoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "helpers.h"
#include "gui.h"
#include "../lib/libft/include/libft.h"
#include "../lib/ft_printf/ft_printf.h"

#include <stdarg.h>
#include <stdlib.h>

/*
** #include <time.h>
** clock_t begin = clock();
** printf("%f s\n", (double)(clock() - begin) / CLOCKS_PER_SEC);
*/

/*
** 0x00RRGGBB
*/

int		rgbtoint(t_rgb *rgb)
{
	int res;
	
	res = 0;
	res |= (int)(rgb->r) << 16;
	res |= (int)(rgb->g) << 8;
	res |= (int)(rgb->b) << 0;
	return (res);
}
