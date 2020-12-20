/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_numtostr_u.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jkoers <jkoers@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/01 00:20:00 by jkoers        #+#    #+#                 */
/*   Updated: 2020/11/03 01:34:07 by jkoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <stdlib.h>

char	*ft_numtostr_u(unsigned long num)
{
	size_t	numlen;
	char	*result;

	numlen = ft_numlen_u(num, 10);
	result = malloc((numlen + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	result[numlen] = '\0';
	while (numlen > 0)
	{
		numlen--;
		result[numlen] = (char)((num % 10) + '0');
		num /= 10;
	}
	return (result);
}
