/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jkoers <jkoers@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/05 17:01:06 by jkoers        #+#    #+#                 */
/*   Updated: 2020/11/05 17:02:24 by jkoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

char	*ft_strncpy(char *dest, char *src, size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		dest[i] = src[i];
		if (src[i] == '\0')
			break ;
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}
