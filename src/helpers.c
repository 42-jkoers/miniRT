/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   helpers.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jkoers <jkoers@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/20 18:54:43 by jkoers        #+#    #+#                 */
/*   Updated: 2020/12/20 22:35:06 by jkoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "helpers.h"
#include "../lib/libft/include/libft.h"
#include "../lib/ft_printf/ft_printf.h"

#include <stdarg.h>
#include <stdlib.h>

void	exit_error(const char *format, ...)
{
	va_list ap;

	va_start(ap, format);
	ft_printf(format, ap);
	va_end(ap);
	exit(1);
}

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
	return res;
}
