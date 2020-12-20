/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jkoers <jkoers@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/26 15:55:38 by jkoers        #+#    #+#                 */
/*   Updated: 2020/11/01 19:32:17 by jkoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <stdlib.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	little_len;
	char	*b;

	b = (char *)big;
	little_len = ft_strlen((char *)little);
	if (little_len == 0)
		return ((char *)big);
	while (len >= little_len)
	{
		len--;
		if (ft_memcmp(b, little, little_len) == 0)
			return (b);
		b++;
	}
	return (NULL);
}
