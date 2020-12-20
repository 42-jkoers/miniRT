/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_numlen.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jkoers <jkoers@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/31 15:16:21 by jkoers        #+#    #+#                 */
/*   Updated: 2020/11/01 19:23:50 by jkoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

size_t	ft_numlen(long num, unsigned long base)
{
	size_t	len;
	long	divider;

	if (num == 0)
		return (1);
	len = 0;
	if (num < 0)
	{
		divider = -((long)base);
		len += 1;
	}
	else
		divider = (long)base;
	while (num != 0)
	{
		num /= divider;
		len++;
	}
	return (len);
}
