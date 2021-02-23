/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jkoers <jkoers@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/27 10:31:07 by jkoers        #+#    #+#                 */
/*   Updated: 2020/10/28 13:58:25 by jkoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

size_t	ft_strlcpy(char *dst, char *src, size_t size)
{
	size_t	srclen;

	srclen = ft_strlen(src);
	if (srclen + 1 < size)
		ft_memcpy(dst, src, (srclen + 1) * sizeof(char));
	else if (size != 0)
	{
		ft_memcpy(dst, src, (size - 1) * sizeof(char));
		dst[size - 1] = '\0';
	}
	return (srclen);
}
