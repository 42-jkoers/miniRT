/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jkoers <jkoers@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/26 14:44:38 by jkoers        #+#    #+#                 */
/*   Updated: 2020/10/28 15:16:31 by jkoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

void		*ft_memmove(void *dest, void *src, size_t n)
{
	char *d;
	char *s;

	if (dest == src)
		return (dest);
	if (dest < src)
		return (ft_memcpy(dest, src, n));
	d = dest;
	s = src;
	d += n - 1;
	s += n - 1;
	while (n > 0)
	{
		*d = *s;
		d--;
		s--;
		n--;
	}
	return (dest);
}
