/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jkoers <jkoers@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/03 01:40:22 by jkoers        #+#    #+#                 */
/*   Updated: 2020/11/03 01:41:46 by jkoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

char	*ft_strncat(char *dest, char *src, size_t nb)
{
	char	*start;

	start = dest;
	while (*dest != '\0')
		dest++;
	while (nb > 0 && *src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (start);
}
