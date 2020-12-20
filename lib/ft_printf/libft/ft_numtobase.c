/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_numtobase.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jkoers <jkoers@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/01 00:20:00 by jkoers        #+#    #+#                 */
/*   Updated: 2020/11/02 12:40:11 by jkoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <stdlib.h>

char	*ft_numtobase(long num, char *base)
{
	size_t	numlen;
	long	base_n;
	char	*result;
	long	divider;

	base_n = (long)ft_strlen(base);
	numlen = ft_numlen(num, (unsigned long)base_n);
	result = malloc((numlen + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	result[numlen] = '\0';
	divider = num < 0 ? -((long)base_n) : (long)base_n;
	while (numlen > 0)
	{
		numlen--;
		result[numlen] = base[ft_abs(num % base_n)];
		num /= divider;
	}
	return (result);
}
