/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_numlen_u.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jkoers <jkoers@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/31 15:16:21 by jkoers        #+#    #+#                 */
/*   Updated: 2020/11/01 19:23:42 by jkoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

size_t	ft_numlen_u(unsigned long num, unsigned long base)
{
	size_t	digits;

	if (num == 0)
		return (1);
	digits = 0;
	while (num != 0)
	{
		num /= base;
		digits++;
	}
	return (digits);
}
